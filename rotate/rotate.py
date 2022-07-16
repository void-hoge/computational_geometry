#!/usr/bin/env python3

import matplotlib.pyplot as plt

def rotate(x, y):
    return -x-y+1, x

def rrotate(x, y):
    return y, -x-y+1

def main():
    window = plt.figure(figsize=(6,6))
    window.add_subplot()
    plt.plot([0,1], [0,0], color='black')
    plt.plot([0,0], [0,1], color='black')
    plt.plot([0,1], [1,0], color='black')
    x, y = 0.1, 0.1
    xr, yr = rotate(x, y)
    xrr, yrr = rotate(xr, yr)
    xrrr, yrrr = rotate(xrr, yrr)
    plt.plot(x, y, marker='.', markersize=10, color='red')
    plt.plot(xr, yr, marker='.', markersize=10, color='green')
    plt.plot(xrr, yrr, marker='.', markersize=10, color='blue')
    plt.plot(xrrr, yrrr, marker='.', markersize=10, color='black')
    plt.show()

if __name__ == '__main__':
    main()
