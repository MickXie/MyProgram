from PIL import ImageColor
from PIL import Image
img = Image.open(r"C:\Users\mickx\Desktop\MyProgram\python\NTOU_Python_Code\Python_Pillow\1.jpg")
print(img.filename)
print(img.size)
print(img.format)
print(img.format_description)
print(img.filename)
img.save(r"C:\Users\mickx\Desktop\MyProgram\python\NTOU_Python_Code\Python_Pillow\1.png")
pictObj = Image.new("RGB", (300, 180), "aqua") # 建立aqua顏色影像
pictObj.save("out17_7.jpg")
width,height = img.size
newPict1 = img.resize((width*2, height) , Image.BILINEAR) # 寬度放大2倍
img.transpose(Image.FLIP_LEFT_RIGHT).save("1.jpg")
img.transpose(Image.FLIP_TOP_BOTTOM).save("2.jpg")
newPict1.show()
print(img.getpixel((width/2, height/2)))
rotated = img.rotate(45, expand=True)
rotated.show()

from PIL import ImageColor
from PIL import Image
newImage = Image.new('RGBA', (300, 300), "Yellow")
for x in range(50, 251): # x軸區間在50-250
    for y in range(50, 151): # y軸區間在50-150
        newImage.putpixel((x, y), (0, 255, 255, 255)) # 填青色
newImage.save("out17_14_1.png") # 第一階段存檔
for x in range(50, 251): # x軸區間在50-250
    for y in range(151, 251): # y軸區間在151-250
        newImage.putpixel((x, y), ImageColor.getcolor("Blue", "RGBA"))
newImage.save("out17_14_2.png") # 第一階段存檔

cropPict = img.crop((80, 30, 150, 100))

from PIL import Image
pict = Image.open("rushmore.jpg") # 建立Pillow物件
copyPict = pict.copy() # 複製
cropPict = copyPict.crop((80, 30, 150, 100)) # 裁切區間
copyPict.paste(cropPict, (20, 20)) # 第一次合成
copyPict.paste(cropPict, (20, 100)) # 第二次合成
copyPict.save("out17_17.jpg") # 儲存

from PIL import ImageColor
from PIL import Image
img=Image.open(r"C:\Users\mickx\Desktop\MyProgram\python\NTOU_Python_Code\Python_Pillow\1.jpg")
cropPict = img.crop((80, 30, 150, 100))
width, height = cropPict.size
startX=10
startY=10
newImage = Image.new('RGBA', (20+width*8, 20+height*4), "Yellow")
for i in range(0,4):
    for j in range(0,8):
        x=startX+width*(j)
        y=startY+height*(i)
        newImage.paste(cropPict, (x, y))
newImage.save("answer.png")

from PIL import ImageColor
from PIL import ImageFilter

img=Image.open(r"C:\Users\mickx\Desktop\MyProgram\python\NTOU_Python_Code\Python_Pillow\1.jpg")
filterPict = img.filter(ImageFilter.FIND_EDGES)
filterPict.show()

from PIL import Image, ImageDraw
newImage = Image.new('RGBA', (300, 300), "Yellow") # 建立300*300黃色底的影像
drawObj = ImageDraw.Draw(newImage)
drawObj.line([(0,0), (299,0), (299,299), (0,299), (0,0)], fill="Black",width=2)
drawObj.ellipse([(50,50), (250,250)], outline="Blue", width=3) 
newImage.show()