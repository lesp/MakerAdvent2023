import board
from adafruit_neokey.neokey1x4 import NeoKey1x4
import usb_hid
from adafruit_hid.keyboard import Keyboard
from adafruit_hid.keyboard_layout_us import KeyboardLayoutUS
from adafruit_hid.keycode import Keycode
import time

keyboard = Keyboard(usb_hid.devices)
keyboard_layout = KeyboardLayoutUS(keyboard)

# use default I2C bus
i2c_bus = board.STEMMA_I2C()

# Create a NeoKey object
neokey = NeoKey1x4(i2c_bus, addr=0x30)

# Check each button, if pressed, light up the matching neopixel!
while True:
    if neokey[0]:
        print("SPACEBAR")
        neokey.pixels[0] = 0x0
        keyboard.send(Keycode.SPACEBAR)
        keyboard.release_all()
        time.sleep(0.1)
    else:
        neokey.pixels[0] = 0x00FF00

    if neokey[1]:
        print("Backspace")
        neokey.pixels[1] = 0x0
        keyboard.send(Keycode.BACKSPACE)
        keyboard.release_all()
        time.sleep(0.1)
    else:
        neokey.pixels[1] = 0xFFFF00

    if neokey[2]:
        print("Blade")
        neokey.pixels[2] = 0x0
        keyboard.send(Keycode.B)
        keyboard.release_all()
        time.sleep(0.1)
    else:
        neokey.pixels[2] = 0xFF0000

    if neokey[3]:
        print("Pointer")
        neokey.pixels[3] = 0x0
        keyboard.send(Keycode.A)
        keyboard.release_all()
        time.sleep(0.1)
    else:
        neokey.pixels[3] = 0x00FFFF
