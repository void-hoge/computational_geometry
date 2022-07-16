#!/usr/bin/env python3

import matplotlib.pyplot as plt

def main():
    window = plt.figure(figsize=(6,6))
    window.add_subplot()
    plt.plot([0,1], [0,0], color='black')
    plt.plot([0,0], [0,1], color='black')
    plt.plot([0,1], [1,0], color='black')
    n = int(input())
    for _ in range(n*3):
        x, y = tuple(map(float, input().split()))
        plt.plot(x, y, marker='.', markersize=10, color='red')

    n = int(input())
    for _ in range(n):
        x, y = tuple(map(float, input().split()))
        plt.plot(x, y, marker='.', markersize=10, color='blue')

    n = int(input())
    for _ in range(n):
        x, y = tuple(map(float, input().split()))
        plt.plot(x, y, marker='.', markersize=10, color='green')

    n = int(input())
    for _ in range(n):
        x, y = tuple(map(float, input().split()))
        plt.plot(x, y, marker='.', markersize=10, color='yellow')

    x, y = tuple(map(float, input().split()))
    plt.plot([0,x], [0,y], color='red')
    plt.plot([0,x], [1,y], color='red')
    plt.plot([1,x], [0,y], color='red')

    x, y = tuple(map(float, input().split()))
    plt.plot([0,x], [0,y], color='blue')
    plt.plot([0,x], [1,y], color='blue')
    plt.plot([1,x], [0,y], color='blue')

    x, y = tuple(map(float, input().split()))
    plt.plot([0,x], [0,y], color='green')
    plt.plot([0,x], [1,y], color='green')
    plt.plot([1,x], [0,y], color='green')

    plt.show()
    
if __name__ == '__main__':
    main()
