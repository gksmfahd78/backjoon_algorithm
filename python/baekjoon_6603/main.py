from itertools import combinations
number_list = list(map(int, input().split()))

while number_list != [0]:
    number_list = sorted(number_list[1:]) 
    
    for numbers in list(combinations(number_list, 6)): 
        for num in numbers:
            print(num, end=' ')
        print()
    print()
    
    number_list = list(map(int, input().split())) 