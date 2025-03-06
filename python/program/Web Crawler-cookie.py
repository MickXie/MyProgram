"""
!因為要按下已滿十八歲的按鈕固有cookie
"""
import urllib.request as req
import json
import bs4 
def getData(url):       
    #!要建立一個Request物件,附加Request Headers 的資訊
    request =req.Request(url1,headers={
        "User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/113.0.0.0 Safari/537.36",
        "cookie":"over18=1"
        })
    with req.urlopen(request) as response:
        data = response.read().decode("utf-8")
    root=bs4.BeautifulSoup(data,"html.parser")
    #!抓title標籤的字串
    print(root.title.string)
    #!找全部的
    titles=root.find_all("div", class_="title")
    for titles in titles:
        if titles.a!=None:
            print (titles.a.string)
    nextLink=root.find("a", string ="‹ 上頁")   
    return nextLink["href"]
url1="https://www.ptt.cc/bbs/Gossiping/index.html"
count=0
#!選擇抓幾葉
while count<3:
    url1="https://www.ptt.cc"+getData(url1)
    count=count+1
print(url1)