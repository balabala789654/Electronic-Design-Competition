import sensor, image, time, lcd, gc
from machine import UART
from board import board_info
from fpioa_manager import fm

fm.register(10, fm.fpioa.UART1_TX, force=True)
fm.register(11, fm.fpioa.UART1_RX, force=True)

#设置串口的波特率，数据位，停止位，奇偶校验位
uart = UART(UART.UART1, 115200, 8, 1, 0, timeout=1000, read_buf_len=4096)

lcd.init()
lcd.rotation(3)
sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QQVGA) #妈蛋 板子太垃圾只能用小画幅
sensor.skip_frames(time = 10000)
sensor.set_auto_exposure(1)
sensor.set_auto_whitebal(True)
sensor.set_auto_gain(True)
#sensor.set_vflip(1)
#sensor.set_hm mirror(0)
black_rect=[50, 50, 50, 50]
black_point_a=(0, 0)
black_point_b=(0, 0)
black_point_c=(0, 0)
black_point_d=(0, 0)

tranfrom_black_point_a=(0, 0)
tranfrom_black_point_b=(0, 0)
tranfrom_black_point_c=(0, 0)
tranfrom_black_point_d=(0, 0)

k=8.1227

def transfrom(_point, _rect, k):
    #print(((_point[0]-_rect[0])*k), ((_point[1]-_rect[1])*k)))
    return (int(((_point[0]-_rect[0])*k)/10), int(((_point[1]-_rect[1])*k)/10)))

def communicate(point_A, point_B, point_C, point_D):
    FH = bytearray([0xfe, point_A[0], point_A[1], point_B[0], point_B[1], point_C[0], point_C[1], point_D[0], point_D[1], 0xff])
    uart.write(FH)
    time.sleep_ms(10)
    return None


def find_black_broder(threshold):
    blobs = img.find_blobs(threshold,x_stride=2, y_stride=2, area_threshold=5, pixels_threshold=5,merge=True,margin=10)
    if len(blobs)>=1 :
        b = blobs[0]
        cx = b[5]
        cy = b[6]
        black_rect[0]=b[0]-5
        black_rect[1]=b[1]-5
        black_rect[2]=b[2]+5
        black_rect[3]=b[3]+5
        img.draw_rectangle6(black_rect)
        return int(cx), int(cy)
    return -1, -1

clock = time.clock()
black_threshold =  [(0, 0, -128, 127, -128, 127)]
black_rect=[30, 25, 110, 75]
while(True):
    clock.tick()
    img = sensor.snapshot()
    #find_black_broder(black_threshold)
    img.draw_rectangle(black_rect)
    for r in img.find_rects(threshold = 30000, roi=black_rect):
        img.draw_rectangle(r.rect(), color = (255, 0, 0))
        for p in r.corners(): img.draw_circle(p[0], p[1], 5, color = (0, 255, 0))
        black_point_a =r.corners()[0]
        black_point_b =r.corners()[1]
        black_point_c =r.corners()[2]
        black_point_d =r.corners()[3]
        #print(black_point_a, black_point_b, black_point_c, black_point_d)
        tranfrom_black_point_a=transfrom(black_point_a, black_rect, k)
        tranfrom_black_point_b=transfrom(black_point_b, black_rect, k)
        tranfrom_black_point_c=transfrom(black_point_c, black_rect, k)
        tranfrom_black_point_d=transfrom(black_point_d, black_rect, k)
        print("a:", tranfrom_black_point_a, "b: ", tranfrom_black_point_b, "c: ", tranfrom_black_point_c, "d: ", tranfrom_black_point_d)
        communicate(tranfrom_black_point_a, tranfrom_black_point_b, tranfrom_black_point_c, tranfrom_black_point_d)
    lcd.display(img)
    gc.collect()

uart.deinit()
del uart
