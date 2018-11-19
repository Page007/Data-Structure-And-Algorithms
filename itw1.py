import random
import math
c = 65536
a = list()
for i in range(1, c + 1):
    a.append(i)
print('Enter your favourite number')
fav = int(input())
b = list()
for i in range (fav):
    random.shuffle(a)
    b.append(random.choice(a))
fav = random.choice(b)
print('Your number has been finalized!!')
print('Start guessing!!!', '\n')
del(c)
c = 65537
count = 0
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
