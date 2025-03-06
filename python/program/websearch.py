#取得原始碼
"""
import urllib.request as request
src = "https://data.taipei/"
with request.urlopen(src) as response:
    data = response.read().decode("utf-8")
print(data)
"""
import urllib.request as request
import json
src = "https://data.taipei/api/v1/dataset/1668e561-f61d-4027-8bc2-b83703c7b447?scope=resourceAquire"
with request.urlopen(src) as response:
    data = json.load(response)
    nlist=data["result"]["results"]
    #!將名稱列表出來
with open("./texts/收好的資料.txt", mode="w",encoding="utf-8") as file:
    for name in nlist:
        file.write(name["縣市"]+" "+name["區域別"]+" "+name["已登記公私有土地面積公頃"]+" "+name["已登記公有土地面積公頃"]+" "+name["已登記私有土地面積公頃"]+"\n")
for name in nlist:
    print(name["縣市"],name["區域別"],name["已登記公私有土地面積公頃"],name["已登記公有土地面積公頃"],name["已登記私有土地面積公頃"])

