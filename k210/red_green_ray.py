import sensor, image, time, lcd


lcd.init()
sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
sensor.skip_frames(time = 100)
sensor.set_auto_gain(False)
sensor.set_auto_whitebal(False)
clock = time.clock()


threshold = [0, 100, 57, 127, 29, 127] # Middle L, A, B values.
while(True):
    clock.tick()
    img = sensor.snapshot()
    for blob in img.find_blobs([threshold], pixels_threshold=10, area_threshold=10, merge=True, margin=10):
        img.draw_rectangle(blob.rect())
    lcd.display(img)
    print(clock.fps())
