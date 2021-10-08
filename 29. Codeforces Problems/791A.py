# https://codeforces.com/problemset/problem/791/A
# 791A - Bear and Big Brother

sizes = [int(size) for size in input().split()]
i = 0

while sizes[0] <= sizes[1]:
    sizes[0] *= 3
    sizes[1] *= 2
    i += 1

print(i)