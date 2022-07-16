#!/usr/bin/env python3

import matplotlib.pyplot as plt
import math
import random

def getline(a, b):
    x1, y1 = a
    x2, y2 = b
    dx = x1-x2
    dy = y1-y2
    if dx == 0:
        return math.inf, 0
    else:
        a = dy/dx
        b = y1-a*x1
        return a, b

def getintersection(l, m):
    a, b = l
    c, d = m
    if (a==c):
        return math.inf, math.inf
    else:
        return (d-b)/(a-c), (a*d-b*c)/(a-c)

def get_random_point():
    return random.random(), random.random()

def plotpoint(p, c):
    x, y = p
    plt.plot(x, y, marker='.', markersize=10, color=c)

def main():
    window = plt.figure(figsize=(6,6))
    window.add_subplot()

    p1 = get_random_point()
    p2 = get_random_point()
    p3 = get_random_point()
    p4 = get_random_point()
    l1 = getline(p1, p2)
    l2 = getline(p3, p4)
    i0 = getintersection(l1, l2)

    plotpoint(p1, 'red')
    plotpoint(p2, 'red')
    plotpoint(p3, 'blue')
    plotpoint(p4, 'blue')
    plotpoint(i0, 'green')

    plt.show()

if __name__ == '__main__':
    main()
