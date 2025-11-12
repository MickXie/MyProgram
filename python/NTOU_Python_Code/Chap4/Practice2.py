heads=eval(input())
legs=eval(input())
rabbits = (legs - 2 * heads) / 2   # 兔的數量
chickens = heads - rabbits          # 雞的數量
print(f"雞的數量：{chickens:.0f} 隻")
print(f"兔的數量：{rabbits:.0f} 隻")
