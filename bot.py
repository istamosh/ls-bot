import win32api as api, win32con as con
import keyboard
import time

def click(x, y):
    api.SetCursorPos((x, y))
    api.mouse_event(con.MOUSEEVENTF_LEFTDOWN,0,0)
    time.sleep(10)
    api.mouse_event(con.MOUSEEVENTF_LEFTUP,0,0)

while keyboard.is_pressed('p') == False:
    click(1044, 486)

# displayMousePosition() RGB identifier is not working inside target window, shows "23, 23, 23"
# mouse click is not working, assumed to be layered window