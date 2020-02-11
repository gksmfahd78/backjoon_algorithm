natural_number_set = set(range(1, 10001)) #natural_number_set 크기를 10000으로 잡는다. 
generated_number_set = set() #generated_number_set는 정수를 넣는 변수

for i in range(1, 10001):
    #print(' i = ' + str(i))
    for j in str(i):
        #print('j = ' + str(j))
        i += int(j)
    #print('num = ' + str(i))
    generated_number_set.add(i)
    #print()

# print(generated_number_set)
# print(natural_number_set)

self_numbers_set = natural_number_set - generated_number_set

for i in sorted(self_numbers_set):
    print(i)