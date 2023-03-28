import itertools

def nextRand24(a, b):
    AND = (1 << 32) - 1
    cur = 0
    while True:
        cur = (cur * a + b) & AND
        yield cur >> 8

def nextRand32(a, b):
    gen = nextRand24(a, b)
    while True:
        c = next(gen); d = next(gen)
        yield (c << 8) ^ d

n, q = map(int, input().split())
a, b = map(int, input().split())
x = list(itertools.islice(nextRand32(a, b), n)) # данный массив

import heapq

heapq.heapify(x)
for i in range(q - 1):
    heapq.heappop(x)
print(heapq.heappop(x))