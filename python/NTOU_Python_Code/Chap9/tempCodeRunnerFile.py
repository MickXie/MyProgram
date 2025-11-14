wechat_account = {
    'cshung': {                     # 第一個使用者帳號
        'last_name': '洪',          # 姓
        'first_name': '錦魁',        # 名
        'city': '台北'               # 城市
    },

    'kevin': {                      # 第二個使用者帳號
        'last_name': '鄭',
        'first_name': '義盟',
        'city': '北京'
    }
}

# ------------------------------------------------------------
# 遍歷整個字典，取得 key（帳號）與 value（內部字典）
# ------------------------------------------------------------
for account, info in wechat_account.items():
    print(f"帳號：{account}")

    # info 是一個字典，因此可用 key 取值
    print("姓氏：", info['last_name'])
    print("名字：", info['first_name'])
    print("城市：", info['city'])
    print("------------------------")  # 分隔線美觀
