import network
import time
import ntptime
from machine import Pin
wlan = network.WLAN(network.STA_IF)
wlan.active(True)
wlan.connect("WIFI SSID","PASSWORD")
time.sleep(5)
print(wlan.isconnected())
ntptime.settime()
date = time.localtime()
day = date[2]

def clear():
    i = 0
    for i in range(15):
        Pin(i, Pin.OUT).low()

def advent(n):
    if n <= 14:
        print(n)
        Pin(n, Pin.OUT).high()
        time.sleep(1)
        Pin(n, Pin.OUT).low()
        time.sleep(0.1)
    if n == 15:
        print(n)
        Pin(1, Pin.OUT).high()
        Pin(5, Pin.OUT).high()
        time.sleep(1)
        Pin(1, Pin.OUT).low()
        Pin(5, Pin.OUT).low()
        time.sleep(0.1)
    if n == 16:
        print(n)
        Pin(1, Pin.OUT).high()
        Pin(6, Pin.OUT).high()
        time.sleep(1)
        Pin(1, Pin.OUT).low()
        Pin(6, Pin.OUT).low()
        time.sleep(0.1)
    if n == 17:
        print(n)
        Pin(1, Pin.OUT).high()
        Pin(7, Pin.OUT).high()
        time.sleep(1)
        Pin(1, Pin.OUT).low()
        Pin(7, Pin.OUT).low()
        time.sleep(0.1)
    if n == 18:
        print(n)
        Pin(1, Pin.OUT).high()
        Pin(8, Pin.OUT).high()
        time.sleep(1)
        Pin(1, Pin.OUT).low()
        Pin(8, Pin.OUT).low()
        time.sleep(0.1)
    if n == 19:
        print(n)
        Pin(1, Pin.OUT).high()
        Pin(9, Pin.OUT).high()
        time.sleep(1)
        Pin(1, Pin.OUT).low()
        Pin(9, Pin.OUT).low()
        time.sleep(0.1)
    if n == 20:
        print(n)
        Pin(2, Pin.OUT).high()
        Pin(0, Pin.OUT).high()
        time.sleep(1)
        Pin(2, Pin.OUT).low()
        Pin(0, Pin.OUT).low()
        time.sleep(0.1)
    if n == 21:
        print(n)
        Pin(2, Pin.OUT).high()
        Pin(1, Pin.OUT).high()
        time.sleep(1)
        Pin(2, Pin.OUT).low()
        Pin(1, Pin.OUT).low()
        time.sleep(0.1)
    if n == 22:
        print(n)
        Pin(2, Pin.OUT).high()
        Pin(2, Pin.OUT).high()
        time.sleep(1)
        Pin(2, Pin.OUT).low()
        Pin(2, Pin.OUT).low()
        time.sleep(0.1)
    if n == 23:
        print(n)
        Pin(2, Pin.OUT).high()
        Pin(3, Pin.OUT).high()
        time.sleep(1)
        Pin(2, Pin.OUT).low()
        Pin(3, Pin.OUT).low()
        time.sleep(0.1)
    if n == 24:
        print(n)
        Pin(2, Pin.OUT).high()
        Pin(4, Pin.OUT).high()
        time.sleep(1)
        Pin(2, Pin.OUT).low()
        Pin(4, Pin.OUT).low()
        time.sleep(0.1)
    if n == 25:
        i = 0
        for i in range(26):
            Pin(i, Pin.OUT).high()
            time.sleep(0.2)
            Pin(i, Pin.OUT).low()
            time.sleep(0.1)
try:    
    while True:
        clear()
        advent(day)
except:
    print("Uh oh")
