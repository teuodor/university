'''
Created on 17 Feb 2019

@author: Teuodor
'''
from _ast import arg
def longest_sub(a):
    s = [0] * len(a)
    p = [0] * len(a)
    p[len(a)-1] = -1
    s[len(a)-1] = 1
    for i in range(len(a)-2,-1,-1):
        p[i] = -1
        s[i] = 1
        for j in range(i+1,len(a)):
            if a[j] <= a[i] and s[i] <= s[j] + 1:
                s[i] = s[j] + 1
                p[i] = j
     
    print(p)
    print(s)           
    j = 0
    for i in range(0,len(a)):
        if s[i]>=s[j]:
            j = i
        
    rez = []
    while j!=-1:
        rez = rez + [a[j]]
        j = p[j]
        
    return rez

l = [123,1,2384,3,3928,5,4,2002]
print(l)
print(longest_sub(l))
arg
    