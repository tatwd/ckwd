# -*- coding: UTF-8 -*-
import math

# String
print "Hello World"
print 'Hello World'
print 'I\'m a student'

str1 = "Hello "
str2 = "Python "
num = 2

print str1+str2+str(num)

#获取两点之间的距离
def getDistance(x1, y1, x2, y2):
    d = math.sqrt(math.pow((x1-x2), 2)+math.pow((y1-y2), 2))
    return d

print "d= "+str(getDistance(1, 2, 2, 3))
