#!/usr/bin/env python3

import random

def main():
    a,b,c = 1,2,3
    for i in range(3):
        for j in range(2):
            print(a,b,c)
            if j == 0:
                b,c = c,b
        a,c = c,a

if __name__ == '__main__':
    main()
