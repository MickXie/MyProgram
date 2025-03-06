import tkinter as tk
import time

def update_time():
    current_time = time.strftime("%H:%M:%S")
    time_label.config(text=current_time)
    # 每秒更新一次時間
    time_label.after(1000, update_time)

# 建立視窗
window = tk.Tk()
window.title("當前時間")
window.geometry("200x50")

# 建立時間標籤
time_label = tk.Label(window, font=("Helvetica", 24))
time_label.pack()

# 開始更新時間
update_time()

# 啟動應用程式的主迴圈
window.mainloop()

