import sensor, image, time, lcd, gc

lcd.init()
sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QQVGA)
sensor.skip_frames(time = 10000)
sensor.set_auto_exposure(1)
sensor.set_auto_whitebal(False)
sensor.set_auto_gain(False)

black_rect=[50, 50, 50, 50]
black_point_a=(0, 0)
black_point_b=(0, 0)
black_point_c=(0, 0)
black_point_d=(0, 0)

def find_black_broder(threshold):
    blobs = img.find_blobs(threshold,x_stride=2, y_stride=2, area_threshold=5, pixels_threshold=5,merge=True,margin=10)
    if len(blobs)>=1 :#有色块
        b = blobs[0]
        cx = b[5]
        cy = b[6]
        black_rect[0]=b[0]-5
        black_rect[1]=b[1]-5
        black_rect[2]=b[2]+5
        black_rect[3]=b[3]+5
        img.draw_rectangle(black_rect)
        return int(cx), int(cy)
    return -1, -1 #表示没有找到

clock = time.clock()
black_threshold =  [(0, 0, -128, 127, -128, 127)]
while(True):
    clock.tick()
    img = sensor.snapshot()
    #find_black_broder(black_threshold)
    for r in img.find_rects(threshold = 10000):
        img.draw_rectangle(r.rect(), color = (255, 0, 0))
        for p in r.corners(): img.draw_circle(p[0], p[1], 5, color = (0, 255, 0))
        black_point_a =r.corners()[0]
        black_point_b =r.corners()[1]
        black_point_c =r.corners()[2]
        black_point_d =r.corners()[3]
        print(black_point_a, black_point_b, black_point_c, black_point_d)
    lcd.display(img)
    gc.collect()