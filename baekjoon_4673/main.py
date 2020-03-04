natural_number_set = set(range(1, 10001))
generated_number_set = set()

for i in range(1, 10001):
    for j in str(i):
        i += int(j)
self_numbers_set = natural_number_set - generated_number_set

for i in sorted(self_numbers_set):
    print(i)
