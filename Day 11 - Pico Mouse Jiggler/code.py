import usb_hid
from adafruit_hid.mouse import Mouse
from time import sleep
from random import randint

m = Mouse(usb_hid.devices)

while True:
    x = randint(0,640)
    y = randint(0,480)
    m.move(x, y)
    sleep(0.5)
