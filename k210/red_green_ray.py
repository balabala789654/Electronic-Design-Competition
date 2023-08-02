import sensor, image, time, lcd, gc
from modules import ybserial
lcd.init()
sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
sensor.skip_frames(time = 10000)
sensor.set_auto_whitebal(False)
sensor.set_auto_gain(False)
sensor.set_auto_exposure(False, exposure_us=3980000)
sensor.set_contrast(2)            # 设置对比度 0 这个参数无法读取 且调这个参数对画面似乎不会产生影响 暂时注释
sensor.set_brightness(2)          # 设置亮度 0 这个参数无法读取 且调这个参数对画面似乎不会产生影响 暂时注释
sensor.set_saturation(2)

serial = ybserial()

def communicate():
    serial.send_byte(0xaa)
    serial.send_byte(0x10)
    serial.send_byte(0x20)
    serial.send_byte(0xbb)
    return None

red_threshold = (0, 100, 61, 99, 19, 100)
green_threshold = (0, 100, -128, -41, 43, 92)
def find_ray(threshold):
    blobs = img.find_blobs([threshold], x_stride=5, y_stride=5, area_threshold=5, pixel_threshold=5, merge=True, margin=10)
    if blobs:
        b = blobs[0]
        cx = b.cx()
        cy = b.cy()
        img.draw_rectangle(b.rect(), color=(255, 0, 0))
        img.draw_cross(cx, cy, color=(255, 0, 0))
        return cx, cy
    return None

while True:
    img = sensor.snapshot()
    #img.binary([green_threshold])
    find_ray(green_threshold)
    communicate()
    lcd.display(img)
    gc.collect()

