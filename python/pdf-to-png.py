import tkinter as tk
from tkinter import filedialog, messagebox, ttk
from pdf2image import convert_from_path
import os
import webbrowser
import threading

# 設定 poppler 路徑
poppler_path = r"C:\Users\mickx\OneDrive\桌面\poppler-24.07.0\Library\bin"  # 設定你的 poppler bin 資料夾路徑

# 定義畫質選項對應的 DPI
QUALITY_OPTIONS = {
    "一般": 100,
    "高階": 200,
    "進階": None  # 進階允許使用者自定義解析度
}

# 設置轉換進度
def update_progress(current_page, total_pages):
    progress_var.set(int(current_page / total_pages * 100))
    root.update_idletasks()

# 選擇 PDF 檔案
def select_pdf_files():
    pdf_file_paths = filedialog.askopenfilenames(
        title="選擇 PDF 檔案", 
        filetypes=[("PDF 檔案", "*.pdf")]
    )
    if pdf_file_paths:
        selected_files_text.set("\n".join(pdf_file_paths))
        update_filename_preview()
    return pdf_file_paths

# 選擇輸出資料夾
def select_output_dir():
    output_dir = filedialog.askdirectory(title="選擇輸出資料夾")
    if output_dir:
        selected_output_text.set(output_dir)
    return output_dir

# 更新文件名稱預覽
def update_filename_preview():
    pdf_file_paths = selected_files_text.get().splitlines()
    if not pdf_file_paths:
        filename_preview.set("未選擇檔案")
        return
    
    base_name = os.path.splitext(os.path.basename(pdf_file_paths[0]))[0]
    custom_name = filename_entry.get()
    if custom_name:
        preview_name = custom_name.replace("{name}", base_name).replace("{page}", "1")
    else:
        preview_name = f"{base_name}_page_1"
    
    filename_preview.set(preview_name)

# 執行 PDF 轉換的主功能
def convert_pdf_to_images():
    pdf_file_paths = selected_files_text.get().splitlines()
    if not pdf_file_paths:
        messagebox.showwarning("警告", "你必須選擇至少一個 PDF 檔案！")
        return

    output_dir = selected_output_text.get()
    if not output_dir:
        messagebox.showwarning("警告", "你必須選擇一個輸出資料夾！")
        return
    
    selected_quality = quality_var.get()
    dpi = QUALITY_OPTIONS[selected_quality]
    
    if selected_quality == "進階":
        try:
            dpi = int(dpi_entry.get())
        except ValueError:
            messagebox.showwarning("錯誤", "請輸入有效的解析度 (DPI)")
            return

    output_format = format_var.get()
    compress_images = compress_var.get()
    custom_name = filename_entry.get()

    try:
        total_pages = sum([len(convert_from_path(pdf_file, dpi=10, poppler_path=poppler_path)) for pdf_file in pdf_file_paths])
        current_page = 0

        for pdf_file_path in pdf_file_paths:
            pages = convert_from_path(pdf_file_path, dpi=dpi, poppler_path=poppler_path)
            base_name = os.path.splitext(os.path.basename(pdf_file_path))[0]
            for i, page in enumerate(pages):
                page_num = i + 1
                if custom_name:
                    output_name = custom_name.replace("{name}", base_name).replace("{page}", str(page_num))
                else:
                    output_name = f"{base_name}_page_{page_num}"
                
                output_path = os.path.join(output_dir, f'{output_name}.{output_format}')
                
                if compress_images:
                    page.save(output_path, output_format.upper(), quality=85, optimize=True)
                else:
                    page.save(output_path, output_format.upper())
                
                current_page += 1
                update_progress(current_page, total_pages)

        messagebox.showinfo("成功", f"PDF 已成功轉換並儲存到 {output_dir}")
        webbrowser.open(output_dir)  # 自動打開輸出資料夾

    except Exception as e:
        messagebox.showerror("錯誤", f"轉換失敗: {str(e)}")

# 開始轉換的執行緒
def start_conversion_thread():
    thread = threading.Thread(target=convert_pdf_to_images)
    thread.start()

# 當畫質改變時，控制解析度輸入框
def on_quality_change(*args):
    if quality_var.get() == "進階":
        dpi_entry.config(state='normal')
    else:
        dpi_entry.config(state='disabled')

# 建立主介面
root = tk.Tk()
root.title("PDF 轉 JPG/PNG")
root.geometry("600x700")
root.config(bg='#333333')  # 深色背景

# 設置滾動條框架
main_frame = tk.Frame(root)
main_frame.pack(fill=tk.BOTH, expand=1)

canvas = tk.Canvas(main_frame, bg='#333333')
canvas.pack(side=tk.LEFT, fill=tk.BOTH, expand=1)

scrollbar = ttk.Scrollbar(main_frame, orient=tk.VERTICAL, command=canvas.yview)
scrollbar.pack(side=tk.RIGHT, fill=tk.Y)

canvas.configure(yscrollcommand=scrollbar.set)
canvas.bind('<Configure>', lambda e: canvas.configure(scrollregion=canvas.bbox("all")))

scrollable_frame = tk.Frame(canvas, bg='#333333')

canvas.create_window((0, 0), window=scrollable_frame, anchor="nw")

# 標題
title_label = ttk.Label(scrollable_frame, text="PDF 轉換器", font=("Helvetica", 24, "bold"), background='#333333', foreground="white")
title_label.pack(pady=20)

# 選擇 PDF 檔案按鈕
select_pdf_button = tk.Button(scrollable_frame, text="選擇 PDF 檔案", command=select_pdf_files, bg="#4CAF50", fg="white", font=("Helvetica", 14))
select_pdf_button.pack(pady=10)

# 顯示選擇的檔案
selected_files_text = tk.StringVar()
selected_files_label = tk.Label(scrollable_frame, textvariable=selected_files_text, relief="sunken", width=60, height=5, anchor="nw", justify="left", bg="white", font=("Helvetica", 12))
selected_files_label.pack(pady=10)

# 選擇輸出資料夾按鈕
select_output_button = tk.Button(scrollable_frame, text="選擇輸出資料夾", command=select_output_dir, bg="#4CAF50", fg="white", font=("Helvetica", 14))
select_output_button.pack(pady=10)

# 顯示選擇的輸出資料夾
selected_output_text = tk.StringVar()
selected_output_label = tk.Label(scrollable_frame, textvariable=selected_output_text, relief="sunken", width=60, height=2, anchor="nw", justify="left", bg="white", font=("Helvetica", 12))
selected_output_label.pack(pady=10)

# 選擇畫質 (一般, 高階, 進階)
quality_label = tk.Label(scrollable_frame, text="選擇畫質:", background='#333333', fg="white", font=("Helvetica", 14))
quality_label.pack(pady=10)

quality_var = tk.StringVar(value="一般")
quality_var.trace("w", on_quality_change)
quality_frame = tk.Frame(scrollable_frame, bg='#333333')
quality_frame.pack(pady=5)
quality_general = tk.Radiobutton(quality_frame, text="一般", variable=quality_var, value="一般", bg="#333333", fg="white", font=("Helvetica", 12), selectcolor="#4CAF50")
quality_high = tk.Radiobutton(quality_frame, text="高階", variable=quality_var, value="高階", bg="#333333", fg="white", font=("Helvetica", 12), selectcolor="#4CAF50")
quality_advanced = tk.Radiobutton(quality_frame, text="進階", variable=quality_var, value="進階", bg="#333333", fg="white", font=("Helvetica", 12), selectcolor="#4CAF50")
quality_general.grid(row=0, column=0, padx=20)
quality_high.grid(row=0, column=1, padx=20)
quality_advanced.grid(row=0, column=2, padx=20)

# 進階模式下的解析度輸入
dpi_label = tk.Label(scrollable_frame, text="解析度 (進階模式):", background='#333333', fg="white", font=("Helvetica", 14))
dpi_label.pack(pady=10)
dpi_entry = tk.Entry(scrollable_frame, state='disabled', font=("Helvetica", 12))
dpi_entry.insert(0, "300")  # 預設值為 300 DPI
dpi_entry.pack(pady=5)

# 文件名稱格式輸入
filename_label = tk.Label(scrollable_frame, text="文件名稱格式 (使用 {name} 和 {page}):", background='#333333', fg="white", font=("Helvetica", 14))
filename_label.pack(pady=10)
filename_entry = tk.Entry(scrollable_frame, font=("Helvetica", 12))
filename_entry.insert(0, "{name}_page_{page}")  # 預設名稱
filename_entry.pack(pady=5)

# 文件名稱預覽
filename_preview = tk.StringVar(value="未選擇檔案")
filename_preview_label = tk.Label(scrollable_frame, textvariable=filename_preview, background='#333333', fg="#FFD700", font=("Helvetica", 12, "italic"))
filename_preview_label.pack(pady=5)

# 選擇圖片格式 (JPG 或 PNG 或 TIFF 或 BMP)
format_label = tk.Label(scrollable_frame, text="選擇輸出格式:", background='#333333', fg="white", font=("Helvetica", 14))
format_label.pack(pady=10)

format_var = tk.StringVar(value="jpg")
format_frame = tk.Frame(scrollable_frame, bg='#333333')
format_frame.pack(pady=5)
format_jpg = tk.Radiobutton(format_frame, text="JPG", variable=format_var, value="jpg", bg="#333333", fg="white", font=("Helvetica", 12), selectcolor="#4CAF50")
format_png = tk.Radiobutton(format_frame, text="PNG", variable=format_var, value="png", bg="#333333", fg="white", font=("Helvetica", 12), selectcolor="#4CAF50")
format_tiff = tk.Radiobutton(format_frame, text="TIFF", variable=format_var, value="tiff", bg="#333333", fg="white", font=("Helvetica", 12), selectcolor="#4CAF50")
format_bmp = tk.Radiobutton(format_frame, text="BMP", variable=format_var, value="bmp", bg="#333333", fg="white", font=("Helvetica", 12), selectcolor="#4CAF50")
format_jpg.grid(row=0, column=0, padx=20)
format_png.grid(row=0, column=1, padx=20)
format_tiff.grid(row=0, column=2, padx=20)
format_bmp.grid(row=0, column=3, padx=20)

# 壓縮圖片選項
compress_var = tk.BooleanVar()
compress_check = ttk.Checkbutton(scrollable_frame, text="減小檔案大小 (壓縮)", variable=compress_var)
compress_check.pack(pady=10)

# 轉換進度條
progress_var = tk.IntVar()
progress_bar = ttk.Progressbar(scrollable_frame, maximum=100, variable=progress_var)
progress_bar.pack(pady=20, fill=tk.X)

# 建立按鈕來進行轉換
convert_button = tk.Button(scrollable_frame, text="開始轉換", command=start_conversion_thread, bg="#4CAF50", fg="white", font=("Helvetica", 14))
convert_button.pack(pady=30)

# 執行介面
root.mainloop()
