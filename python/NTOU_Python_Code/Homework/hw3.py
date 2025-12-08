registrations = {
    'Alice': ['CS101', 'MATH202'],
    'Bob': ['CS101', 'PHYS101'],
    'Charlie': ['MATH202', 'CHEM101'],
    'David': ['CS101']
}
course_enrollment = {}  
for student, course_list in registrations.items():
    for course in course_list:
        if course not in course_enrollment:
            course_enrollment[course] = set() 
        course_enrollment[course].add(student)  
print(course_enrollment)

{
 'CS101': {'Alice', 'Bob', 'David'},
 'MATH202': {'Alice', 'Charlie'},
 'PHYS101': {'Bob'},
 'CHEM101': {'Charlie'}
}

transactions = [
    ['Apple', 'Banana'],
    ['Orange', 'Apple'],
    ['Banana', 'Apple'],  
    ['Apple', 'Banana', 'Orange'],
    ['Orange', 'Apple']
]
combination_counts = {}
for items in transactions:
    combo = frozenset(items)
    if combo not in combination_counts:
        combination_counts[combo] = 0
    combination_counts[combo] += 1
print(combination_counts)

{
  frozenset({'Apple', 'Banana'}): 2,
  frozenset({'Apple', 'Orange'}): 2,
  frozenset({'Apple', 'Banana', 'Orange'}): 1
}


def make_rate_limiter(max_calls):
    remaining = max_calls   

    def limiter():
        nonlocal remaining   
        if remaining > 0:
            remaining -= 1
            return True
        else:
            return False

    return limiter

limit_2 = make_rate_limiter(2)

print(limit_2())   # True
print(limit_2())   # True
print(limit_2())   # False
print(limit_2())   # False


config_data = {
    'server': {
        'host': 'localhost',
        'port': 8080
    },
    'database': {
        'connection': {
            'host': 'db.example.com',
            'user': 'admin'
        }
    }
}
path1 = ['database', 'connection', 'host']
path2 = ['server', 'port']
path3 = ['server', 'timeout']        
path4 = ['server', 'host', 'address'] 
def get_nested_value(data, key_path):
    if not key_path:
        return None
    key = key_path[0]
    if key not in data:
        return None
    value = data[key]
    if len(key_path) == 1:
        return value
    if not isinstance(value, dict):
        return None
    return get_nested_value(value, key_path[1:])
print(get_nested_value(config_data, path1))  # db.example.com
print(get_nested_value(config_data, path2))  # 8080
print(get_nested_value(config_data, path3))  # None
print(get_nested_value(config_data, path4))  # None


def process_data(data_list, *tests, **transforms):
    results = {name: [] for name in transforms}
    for num in data_list:
        if not all(test(num) for test in tests):
            continue 
        for name, func in transforms.items():
            results[name].append(func(num))
    return results
def is_odd(n):
    return n % 2 != 0
def is_positive(n):
    return n > 0
data = [1, 2, 3, 4, 5, -1, -3]
result_data = process_data(
    data,
    is_odd,        
    is_positive,   
    squared=lambda x: x**2,  
    plus_one=lambda x: x + 1  
)
print(result_data)

{'squared': [1, 9, 25], 'plus_one': [2, 4, 6]}

