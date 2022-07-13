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
    sx, sy = tuple(map(float, input().split()))
    plt.plot([0,sx], [0,sy], color='black')
    plt.show()

if __name__ == '__main__':
    main()
