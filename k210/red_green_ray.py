import sensor, image, time, lcd, gc
from modules import ybserial
lcd.init()
sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
sensor.skip_frames(time = 10000)
sensor.set_auto_whitebal(False)
sensor.set_auto_gain(False)
sensor.set_auto_exposure(False, exposure_us=3970000)
sensor.set_contrast(2)            # 设置对比度 0 这个参数无法读取 且调这个参数对画面似乎不会产生影响 暂时注释
sensor.set_brightness(2)          # 设置亮度 0 这个参数无法读取 且调这个参数对画面似乎不会产生影响 暂时注释
sensor.set_saturation(2)

serial = ybserial()

def communicate(point_a, point_b):
    serial.send_byte(0xfe)
    serial.send_byte(point_a[0])
    serial.send_byte(point_a[1])
    serial.send_byte(point_b[0])
    serial.send_byte(point_b[1])
    serial.send_byte(0xff)
    return None

red_threshold = (0, 100, 59, 127, 26, 60)
green_threshold = (0, 100, -128, -41, 43, 92)
point_green=(0, 0)
point_red=(0, 0)
def find_ray(threshold, x):
    blobs = img.find_blobs([threshold], x_stride=2, y_stride=2, area_threshold=2, pixel_threshold=2, merge=True, margin=10)
    if blobs:
        b = blobs[0]
        cx = b.cx()
        cy = b.cy()
        if x:
            img.draw_rectangle(b.rect(), color=(255, 0, 0))
            img.draw_cross(cx, cy, color=(255, 0, 0))
            print("green: ", cx, cy)
            point_green=(cx, cy)
        else:
            img.draw_rectangle(b.rect(), color=(0, 255, 0))
            img.draw_cross(cx, cy, color=(0, 255, 0))
            print("red: ", cx, cy)
            point_red=(cx, cy)
        return (cx, cy)
    return (None, None)

while True:
    img = sensor.snapshot()
    #img.binary([green_threshold])
    find_ray(green_threshold, 1)
    find_ray(red_threshold, 0)
    communicate(point_green, point_red)
    lcd.display(img)
    gc.collect()

