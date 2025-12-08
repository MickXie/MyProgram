from PIL import Image, ImageDraw
newImage = Image.new('RGBA', (300, 300), "Yellow") # 建立300*300黃色底的影像
drawObj = ImageDraw.Draw(newImage)
drawObj.line([(0,0), (299,0), (299,299), (0,299), (0,0)], fill="Black",width=2)
drawObj.ellipse([(50,50), (250,250)], outline="Blue", width=3) 
newImage.show()