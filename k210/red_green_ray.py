import sensor, image, time, lcd, gc

lcd.init()
sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
sensor.skip_frames(time = 10000)
sensor.set_auto_exposure(1)
sensor.set_auto_whitebal(False)
sensor.set_auto_gain(False)
sensor.set_auto_exposure(False, exposure_us=1400)

def communicate():
    return None

red_threshold = (0, 100, 61, 99, 19, 100)
green_threshold = [(0, 100, -128, -41, 43, 92)
def find_ray(threshold):
    blobs = img.find_blobs([threshold], x_stride=10, y_stride=10, area_threshold=10, pixel_threshold=10, merge=True, margin=10)
    if blobs:
        b = blobs[0]
        cx = b.cx()
        cy = b.cy()

        img.draw_cross(cx, cy, color=(0, 255, 128))
        return cx, cy
    return None

while True:
    img = sensor.snapshot()
    img.binary(green_threshold)
    find_ray(green_threshold)
    lcd.display(img)
    gc.collect()

