#! /usr/bin/env python3
# encoding: utf-8

sum = 0
for i in range(3, 1000):
    sum += i if i%3==0 or i%5==0 else 0

print(sum)
