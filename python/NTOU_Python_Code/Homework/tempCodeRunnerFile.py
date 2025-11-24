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
