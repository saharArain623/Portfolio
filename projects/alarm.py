import time
from datetime import datetime

def alarm_clock():
    print("Python Alarm Clock / Reminder App")
    alarm_time = input("Set alarm (HH:MM:SS): ")
    message = input("Enter message for alarm: ")

    print(f"Alarm set for {alarm_time} with message: '{message}'")

    while True:
        now = datetime.now().strftime("%H:%M:%S")
        if now == alarm_time:
            print(f"\n⏰ Alarm! {message}")
            break
        time.sleep(1)

alarm_clock()