#!/usr/bin/env python3

# 27019578
# Mugi Noda

import random

N = 8

def main():
    print(N)
    for i in range(N*3):
        x, tot = sorted([random.random(), random.random()])
        y = tot-x
        print(x, y)

if __name__ == '__main__':
    main()
