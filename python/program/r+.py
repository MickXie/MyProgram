import json

with open("./texts/txt.txt", mode="r+", encoding="utf-8") as text:
    data = text.read()
    print(data)
    text.write("一一一")
    text.seek(0)  # 将文件指针移动到文件开头
    data = text.read()
    print(data)
    text.write("哈哈哈")
    text.seek(0)  # 将文件指针移动到文件开头
    data = text.read()
    print(data)

with open("./texts/json.json", mode="r+", encoding="utf-8") as json_file:
    data = json.load(json_file)
    print(data)
    print(data["nn"])
    print(data["mm"])
#open("./texts/json.json", mode="r+", encoding="utf-8") as json_file: