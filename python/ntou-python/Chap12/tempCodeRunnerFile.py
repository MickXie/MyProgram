class Father():
    def __init__(self):
        self.fathermoney = 10000   # 父親共有的資產

class Ira(Father):
    def __init__(self):
        self.iramoney = 8000       # Ira 的資產
        super().__init__()         # 父親的資產一起初始化

class Ivan(Father):
    def __init__(self):
        self.ivanmoney = 3000      # Ivan 的資產
        super().__init__()         # 父親的資產一起初始化

    def get_money(self):
        print("Ivan資產:", self.ivanmoney)
        print("父親資產:", self.fathermoney)
        print("Ira資產:", Ira().iramoney)
ivan = Ivan()
ivan.get_money()
print("Ira資產:", Ira().iramoney)