# -*- coding:UTF-8 -*-

#递归求阶乘
def fac(num):
    if num == 0:
        return 1
    else:
        return num*fac(num-1)
print fac(3)