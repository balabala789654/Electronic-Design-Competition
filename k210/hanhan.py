# Find Rects Example
#
# 这个例子展示了如何使用april标签代码中的四元检测代码在图像中找到矩形。 四元检测算法以非常稳健的方式检测矩形，并且比基于Hough变换的方法好得多。 例如，即使镜头失真导致这些矩形看起来弯曲，它仍然可以检测到矩形。 圆角矩形是没有问题的！
# (但是，这个代码也会检测小半径的圆)...

import sensor, image, time
#from pyb import UART
sensor.reset()
sensor.set_pixformat(sensor.RGB565) # 灰度更快(160x120 max on OpenMV-M7)
sensor.set_framesize(sensor.QQVGA)
sensor.skip_frames(time = 10000)
sensor.set_auto_exposure(1) #在这里调节曝光度，调节完可以比较清晰地看清激光点
sensor.set_auto_whitebal(False) # turn this off.
sensor.set_auto_gain(False) # 关闭增益（色块识别时必须要关）
#uart = UART(3, 9600)
RXY = "0,0"
def color_blob(threshold):

    blobs = img.find_blobs(threshold,x_stride=2, y_stride=1, area_threshold=0, pixels_threshold=0,merge=False,margin=1)
    #print(blobs)
    if len(blobs)>=1 :#有色块
        # Draw a rect around the blob.
        b = blobs[0]
        #img.draw_rectangle(b[0:4]) # rect
        cx = b[5]
        cy = b[6]
        for i in range(len(blobs)-1):
            #img.draw_rectangle(b[0:4]) # rect
            cx = blobs[i][5]+cx
            cy = blobs[i][6]+cy
        cx=int(cx/len(blobs))
        cy=int(cy/len(blobs))
        #img.draw_cross(cx, cy) # cx, cy
        #  print(cx,cy)
        RXY = "%d,%d "%(cx,cy)
        return int(cx), int(cy)
    return -1, -1 #表示没有找到

clock = time.clock()
threshold =  [(60, 255, -20, 20, -20, 20)]
while(True):
    clock.tick()
    img = sensor.snapshot()
    #img.binary(threshold)
    # 下面的`threshold`应设置为足够高的值，以滤除在图像中检测到的具有
    # 低边缘幅度的噪声矩形。最适用与背景形成鲜明对比的矩形。
    color_blob(threshold)
    for r in img.find_rects(threshold = 10000):
        img.draw_rectangle(r.rect(), color = (255, 0, 0))
        for p in r.corners(): img.draw_circle(p[0], p[1], 5, color = (0, 255, 0))
        XY1 = "A %d,%d "%( r.corners()[0][0],r.corners()[0][1])
        XY2 = "B %d,%d "%( r.corners()[1][0],r.corners()[1][1])
        XY3 = "C %d,%d "%( r.corners()[2][0],r.corners()[2][1])
        XY4 = "D %d,%d "%( r.corners()[3][0],r.corners()[3][1])
        #uart.write(XY1+XY2+XY3+XY4+'\r\n')
        print(XY1+XY2+XY3+XY4+'\r\n')
       #// print(X1)

    #print("FPS %f" % clock.fps())
