# zodiac.py
# 讀入西元年（19xx 或 20xx），輸出對應的生肖（中文）

animals = ['鼠', '牛', '虎', '兔', '龍', '蛇', '馬', '羊', '猴', '雞', '狗', '豬']

def zodiac(year: int) -> str:
    # 以 2008 年為基準（2008 = 鼠）
    idx = (year - 2008) % 12
    return animals[idx]

def main():
    s = input("請輸入你出生的西元年（格式例：1995 或 2003）：").strip()
    # 基本檢查：是否為數字、長度是否為4、年份是否在 1900-2099 範圍
    if not (s.isdigit() and len(s) == 4):
        print("輸入格式錯誤，請輸入四位數的西元年（例：1988）。")
        return
    year = int(s)
    if year < 1900 or year > 2099:
        print("本程式僅接受 19xx 或 20xx 範圍（1900-2099）。")
        return

    print(f"{year} 年的生肖是：{zodiac(year)}")


