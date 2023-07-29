import sensor, image, time, lcd
import gc
from maix import utils as ut
import machine
from modules import ybserial


serial = ybserial()

sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
sensor.run(1)
sensor.skip_frames(time = 2000)
sensor.set_auto_gain(False)
sensor.set_auto_whitebal(False)

lcd.init(freq=15000000)
clock = time.clock()
#ut.gc_heap_size(7*1024*1024)
#machine.reset()

threshold=[0, 100, 49, 127, 13, 73]

blob_cx=0
blob_cy=0

def communicate():
    serial.send_byte(0xaa)
    serial.send_byte(blob_cx)
    serial.send_byte(blob_cy)
    serial.send_byte(0xbb)

while(True):
    clock.tick()
    img = sensor.snapshot()
    for blob in img.find_blobs([threshold], pixels_threshold=10, area_threshold=10, merge=True, margin=10):
        blob_cx=blob.cx()
        blob_cy=blob.cy()
        img.draw_rectangle(blob.rect())
        img.draw_cross(blob_cx, blob_cy)
        img.draw_line(blob_cx, 0, blob_cx, 240, color=(0, 255, 255))

    lcd.display(img)
    #print(blob_cx, blob_cy)
    communicate()
    gc.collect()


