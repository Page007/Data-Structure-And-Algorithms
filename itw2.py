'''
This is a rudimentary code for flagged Fibonacci generator which is one of the most commonly used PRNG method.
We assume that the operator in the FFG method is bitwise EXOR of the numbers.
'''
import random
import math
print('Enter any 4 numbers of your choice')
b = list()
for i in range(4):
    b.append(int(input()))
print('Now, enter any number of your choice ')
a = int(input())
while a > 0:
    a -= 1
    k = a + 1
    j = a
    b.append(b[k % len(b)]^b[j % len(b)])
del(a)
#print(b)
fav = random.choice(b)
c = 123456789
count = 0
print('Your random number has been generated')
while c != fav and count < 6:
    count += 1
    print('$$ ')
    c = int(input())
    if c > fav:
        print('Come on! Be realistic, that\'s too high!! \n')
    elif c < fav:
        print('Enter a number of some weight!!\n')
    elif c - fav > 10000:
        print('You are 10 tons away from your answer\n')
    elif c == fav:
        print('You have hit the jackpot\n')
    elif c -fav > 5000:
        print('About 5000 away!!')
    elif c - fav <1000 :
        print('Close!!! About a ton away!\n')
    elif c - fav < 500:
        print('Wheezing closer to the number are we ???? \n')
    else:
        print('That is just wrong! Try another one')
    if count == 4:
        print('The hint is : ', fav/10)
if count == 6:
    print('Sorry, the number was : ',fav)
print('Thank you for playing\n')

