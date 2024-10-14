size = int(input())
iters = int(input())
arr = [0] * size

for iter in range(iters):
    data = input()
    start, end, number = map(int, data.split(' '))
    
    if start > 0:
        arr[start - 1] = arr[start - 1] + number
    if end < size:
        arr[end] = arr[end] - number

sum = 0
max_sum = 0

for number in arr:
    sum = sum + number
    if sum > max_sum:
        max_sum = sum

print(max_sum, end='')
