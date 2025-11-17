# Q1
registrations = {
    "Alice": ["Math", "Physics"],
    "Bob": ["Math", "Chemistry"],
    "Charlie": ["Physics"]
}

course_enrollment = {}

for student, courses in registrations.items():
    for course in courses:
        if course not in course_enrollment:
            course_enrollment[course] = set()
        course_enrollment[course].add(student)

print("Q1 course_enrollment:")
print(course_enrollment)
# 例如: {'Math': {'Alice', 'Bob'}, 'Physics': {'Alice', 'Charlie'}, 'Chemistry': {'Bob'}}

# Q2
transactions = [
    ["apple", "banana"],
    ["banana", "apple"],   # 與 ["apple", "banana"] 視為同一組合
    ["apple", "orange"],
    ["banana"],
    ["apple", "banana"]
]

combination_counts = {}

for t in transactions:
    combo = frozenset(t)  # 把清單轉成 frozenset，順序就不重要了
    if combo not in combination_counts:
        combination_counts[combo] = 0
    combination_counts[combo] += 1

print("\nQ2 combination_counts:")
for combo, count in combination_counts.items():
    print(combo, "=>", count)

# Q3
def make_rate_limiter(max_calls):
    remaining = max_calls  # 外層變數，用來記錄剩餘可呼叫次數

    def limiter():
        nonlocal remaining  # 告訴 Python：要用外層的 remaining 來修改
        if remaining > 0:
            remaining -= 1
            return True
        else:
            return False

    return limiter


# 測試用例
print("\nQ3 test:")
limiter = make_rate_limiter(3)
print(limiter())  # True
print(limiter())  # True
print(limiter())  # True
print(limiter())  # False
print(limiter())  # False

# Q4
def get_nested_value(data, key_path):
    # 若 key_path 空了，或 data 不是字典，直接回傳 None
    if not key_path or not isinstance(data, dict):
        return None

    key = key_path[0]

    # 找不到這個 key
    if key not in data:
        return None

    value = data[key]

    # 如果這是最後一個 key，就直接回傳 value
    if len(key_path) == 1:
        return value

    # 還有更多 key，要往下一層找，而且 value 必須也是 dict
    if isinstance(value, dict):
        return get_nested_value(value, key_path[1:])
    else:
        return None


# 測試用例
config = {
    "database": {
        "connection": {
            "host": "localhost",
            "port": 5432
        }
    },
    "api": {
        "endpoint": "/v1/data"
    }
}

print("\nQ4 test:")
print(get_nested_value(config, ["database", "connection", "host"]))   # "localhost"
print(get_nested_value(config, ["database", "connection", "port"]))   # 5432
print(get_nested_value(config, ["api", "endpoint"]))                  # "/v1/data"
print(get_nested_value(config, ["api", "missing"]))                   # None
print(get_nested_value(config, ["database", "connection", "user"]))   # None

# Q5
def process_data(data_list, *tests, **transforms):
    # 1. 以 transforms 的 key 建立 results 字典，初始都是空 list
    results = {name: [] for name in transforms}

    for num in data_list:
        # 3. 必須通過所有 tests
        if all(test(num) for test in tests):
            # 4. 通過測試後，套用每一個 transform 函數
            for name, func in transforms.items():
                results[name].append(func(num))

    return results


# 測試用例
def is_odd(x):
    return x % 2 == 1

def is_positive(x):
    return x > 0

data_list = [-3, -2, -1, 0, 1, 2, 3, 4, 5]

result = process_data(
    data_list,
    is_odd,           # tests：只留下「奇數」
    is_positive,      # 且「大於 0」
    squared=lambda x: x ** 2,         # transforms
    plus_one=lambda x: x + 1
)

print("\nQ5 result:")
print(result)
# 只會處理 1, 3, 5
# squared: [1, 9, 25]
# plus_one: [2, 4, 6]
