import torch
from torch import nn, optim
from torchvision import transforms, models
from PIL import Image
content_image_path = r"C:\Users\mickx\Downloads\螢幕擷取畫面 2024-12-19 114629.png"
style_image_path = r"C:\Users\mickx\Downloads\style_image.png"

# 加载图片
def load_image(image_path, size=512):
    image = Image.open(image_path).convert("RGB")
    transform = transforms.Compose([
        transforms.Resize((size, size)),
        transforms.ToTensor()
    ])
    image = transform(image).unsqueeze(0)
    return image.to(device)

# 定义 VGG 模型用于提取特征
class VGGFeatures(nn.Module):
    def __init__(self):
        super(VGGFeatures, self).__init__()
        vgg = models.vgg19(pretrained=True).features
        self.layers = nn.ModuleList([vgg[i] for i in range(21)])  # 只取前21层
        for param in self.parameters():
            param.requires_grad = False

    def forward(self, x):
        features = []
        for i, layer in enumerate(self.layers):
            x = layer(x)
            if i in {1, 6, 11, 20}:  # 提取指定层的特征
                features.append(x)
        return features

# Gram 矩阵计算，用于计算风格损失
def gram_matrix(tensor):
    b, c, h, w = tensor.size()
    features = tensor.view(b, c, h * w)
    G = torch.matmul(features, features.transpose(1, 2))
    return G / (c * h * w)

# 风格迁移算法
def style_transfer(content_img, style_img, iterations=300, style_weight=1e6, content_weight=1):
    model = VGGFeatures().to(device)
    target = content_img.clone().requires_grad_(True)
    optimizer = optim.Adam([target], lr=0.01)
    style_features = model(style_img)
    style_grams = [gram_matrix(f) for f in style_features]
    content_features = model(content_img)

    for _ in range(iterations):
        optimizer.zero_grad()
        target_features = model(target)
        content_loss = sum(torch.mean((t - c) ** 2) for t, c in zip(target_features, content_features))
        style_loss = sum(torch.mean((gram_matrix(t) - s) ** 2) for t, s in zip(target_features, style_grams))
        loss = content_loss * content_weight + style_loss * style_weight
        loss.backward()
        optimizer.step()
    return target

# 定义设备
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

# 加载内容图像和风格图像
content_image_path = "path_to_content_image.jpg"  # 替换为内容图像路径
style_image_path = "path_to_style_image.jpg"  # 替换为风格图像路径

content_image = load_image(content_image_path)
style_image = load_image(style_image_path)

# 执行风格迁移
output = style_transfer(content_image, style_image, iterations=300)

# 保存结果
output_image = transforms.ToPILImage()(output.squeeze(0).cpu())
output_image.save("styled_output.png")
