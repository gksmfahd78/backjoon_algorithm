num = int(input())
for _ in range(num):
   bin_num = bin(int(input()))[2:]
   for i in range(len(bin_num)):
       if bin_num[-i -1] == '1':
           print(i, end = ' ')