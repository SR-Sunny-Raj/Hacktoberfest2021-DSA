# https://codeforces.com/problemset/problem/734/A
# 734A - Anton and Danik

n = int(input())
games = input()

count_a = 0
count_d = 0

for game in games:
    if game == "A":
        count_a += 1
    elif game == "D":
        count_d += 1

if count_a > count_d:
    print("Anton")
elif count_d > count_a:
    print("Danik")
else:
    print("Friendship")