# 比赛代码框架准备
import threading
import queue
import serial
import serial.tools.list_ports
import time
import cv2
import numpy as np
import os
import ctypes

class MyUnion(ctypes.Union):
    _fields_ = [
        ("float_value", ctypes.c_float),
        ("char_array", ctypes.c_char * 4)
    ]

send_union = MyUnion()
read_union = MyUnion()

def nothing(x):
    pass

def create_Trackbar():
    for x in track_bar:
        if x == "H1" or x == "H2":
            cv2.createTrackbar(x, "HSV", 0, 180, nothing)
        else:
            cv2.createTrackbar(x, "HSV", 0, 255, nothing)
    return None

def get_Trackbar():
    HSV_ret = [0, 0, 0, 0, 0, 0]
    for x in range(6):
        HSV_ret[x-1] = cv2.getTrackbarPos(track_bar[x-1], "HSV")
    return HSV_ret

def serial_init(port_name, baudrate):
    global my_serial
    my_serial = serial.Serial(port=port_name, baudrate=baudrate, bytesize=serial.EIGHTBITS, parity=serial.PARITY_NONE, stopbits=serial.STOPBITS_ONE, timeout=None)
    if my_serial.isOpen():
        print("serial open success :-)")
        # print(my_serial.name)
        return True
    else:
        print("serial open fialed :-(")
        return False

def thread_opencv_entry(x):
    while video.isOpened() and (not shut_down_event.is_set()):
        # print("working")
        ret_frame, frame = video.read()
        if not ret_frame:
            print("video error")
            break
        frame_blur = cv2.GaussianBlur(frame, (9, 9), 2) # 高斯滤波
        frame_HSV = cv2.cvtColor(frame_blur, cv2.COLOR_RGB2HSV)    

        mask = cv2.inRange(frame_HSV, lowerb=red_lower, upperb=red_upper)

        frame_bit_add = cv2.bitwise_and(frame, frame, mask=mask)
        
        contours, n = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
        cv2.drawContours(frame, contours=contours, contourIdx=-1, color=(255, 0, 0), thickness=2)
        Circles = cv2.HoughCircles(mask, cv2.HOUGH_GRADIENT, dp=1.2, minDist=200, param1=20, param2=10, minRadius=1, maxRadius=5)
        
        if Circles is not None:
            Circles = np.round(Circles[0, :]).astype("int")

            for [x, y, r] in Circles:
                # print("x: ", x, "y: ", y, "r: ", r)
                cv2.circle(frame, [x, y], r, (0, 255, 0), 2)
                pos_queue.put([x, y])
        else:
            pos_queue.put([0, 0])
        
        # cv2.putText(img=frame, text=f"fps:{video.get(cv2.CAP_PROP_FPS)}", org=[0,50], fontFace=cv2.FONT_HERSHEY_SIMPLEX, fontScale=1, color=[0, 0, 0], thickness=1)
        # cv2.imshow("frame", frame)
        cv2.imshow("HSV", mask)
        cv2.imshow("out", frame)
        # time.sleep(0.01)
        cv2.waitKey(1)
    return None

def thread_write_entry(x):
    data = 0
    
    while not shut_down_event.is_set():
        send_union.float_value = 3.1415926
        my_serial.write(send_union.char_array)
        time.sleep(0.5)
    return None

def thread_read_entry(x):
    while not shut_down_event.is_set():
        read_data = my_serial.read_all()
        if read_data != b'':
            read_union.char_array = read_data[0:4]
            # print("receive: " , read_union.float_value)
    return None

if __name__ == "__main__":
    serial_init("COM6", 115200)
    print("电赛!!!!")

    # cv2.namedWindow("frame", cv2.WINDOW_NORMAL)
    # cv2.namedWindow("HSV", cv2.WINDOW_NORMAL)
    # cv2.namedWindow("out", cv2.WINDOW_NORMAL)
    track_bar = ["H1", "S1", "V1", "H2", "S2", "V2"]
    red_lower = np.array([114, 49, 225])
    red_upper = np.array([179, 252, 255])

    thread_opencv = threading.Thread(target=thread_opencv_entry, args=("thread_opencv_entry", ))
    thread_write = threading.Thread(target=thread_write_entry, args=("thread_write_entry", ))
    thread_read = threading.Thread(target=thread_read_entry, args=("thread_read_entry", ))

    global pos_queue
    pos_queue = queue.Queue()
    shut_down_event = threading.Event()
    global video
    video = cv2.VideoCapture(1, cv2.CAP_DSHOW)
    # video = cv2.VideoCapture(1)


    video.set(cv2.CAP_PROP_AUTO_EXPOSURE, 0.25)
    video.set(cv2.CAP_PROP_EXPOSURE, -1) # 曝光度
    video.set(cv2.CAP_PROP_BRIGHTNESS, 100) # 亮度
    video.set(cv2.CAP_PROP_CONTRAST, 100) # 对比度
    video.set(cv2.CAP_PROP_SATURATION, 500) # 饱和度    

    print(video.get(cv2.CAP_PROP_EXPOSURE), video.get(cv2.CAP_PROP_BRIGHTNESS), video.get(cv2.CAP_PROP_CONTRAST), video.get(cv2.CAP_PROP_SATURATION))

    thread_opencv.start()
    thread_write.start()
    thread_read.start()

    try:
        while True: # 主线程
            time.sleep(0.001)
    except KeyboardInterrupt:
        shut_down_event.set()

        thread_opencv.join()
        thread_write.join()
        thread_read.join()

        my_serial.close()
        video.release()
        cv2.destroyAllWindows()    
        print("all thread end")

