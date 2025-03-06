from tkinter import *
from tkinter import filedialog
from pytube import YouTube

def choose_directory():
    file_path = filedialog.askdirectory()
    entry_path.delete(0, END)
    entry_path.insert(0, file_path)

def download_youtube_video():
    url = entry_url.get()
    file_path = entry_path.get()

    try:
        # 创建YouTube对象
        yt = YouTube(url)

        # 获取视频的最高分辨率
        stream = yt.streams.get_highest_resolution()

        # 下载视频
        stream.download(output_path=file_path)

        label_status.config(text="视频下载完成！", fg="green")
    except Exception as e:
        label_status.config(text="下载视频时出错：" + str(e), fg="red")

def close_app():
    window.destroy()

# 创建GUI窗口
window = Tk()
window.title("YouTube视频下载器")

# 设置颜色
bg_color = "#F8F8F8"
btn_bg_color = "#3366CC"
btn_fg_color = "white"

# 设置字体
font_style = ("Arial", 12)

# 设置窗口背景颜色
window.config(bg=bg_color)

# 创建标签和输入框
label_url = Label(window, text="YouTube链接:", font=font_style, bg=bg_color)
label_url.grid(row=0, column=0, padx=10, pady=10, sticky="w")
entry_url = Entry(window, width=40, font=font_style)
entry_url.grid(row=0, column=1, padx=10, pady=10)

label_path = Label(window, text="保存路径:", font=font_style, bg=bg_color)
label_path.grid(row=1, column=0, padx=10, pady=10, sticky="w")
entry_path = Entry(window, width=40, font=font_style)
entry_path.grid(row=1, column=1, padx=10, pady=10)

# 创建选择文件夹按钮
button_select_dir = Button(window, text="选择文件夹", command=choose_directory, font=font_style,
                           bg=btn_bg_color, fg=btn_fg_color)
button_select_dir.grid(row=2, column=0, padx=10, pady=10, sticky="w")

# 创建下载按钮
button_download = Button(window, text="下载", command=download_youtube_video, font=font_style,
                         bg=btn_bg_color, fg=btn_fg_color)
button_download.grid(row=2, column=1, padx=10, pady=10, sticky="e")

# 创建状态标签
label_status = Label(window, text="", font=font_style, bg=bg_color)
label_status.grid(row=3, column=0, columnspan=2, padx=10, pady=10)

# 创建关闭按钮
button_close = Button(window, text="关闭", command=close_app, font=font_style,
                      bg=btn_bg_color, fg=btn_fg_color)
button_close.grid(row=4, column=0, columnspan=2, padx=10, pady=10)

# 启动GUI主循环
window.mainloop()
