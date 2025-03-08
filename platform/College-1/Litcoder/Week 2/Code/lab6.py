def isPrime(num):
    if num == 0 or num == 1:
        return True
    for i in range(2, num):
        if num % i == 0:
            return False
    return True

num = input()
outNum = 0

# Find the largest prime less than the first digit
for i in range(int(num[0]) - 1, 0, -1):
    if isPrime(i):
        outNum = outNum * 10 + i
        break

# Process the rest of the digits
for _ in range(len(num) - 1):
    for digit in range(9, 0, -1):
        temp = outNum * 10 + digit
        if isPrime(temp):
            outNum = temp
            break

print(outNum, end='')
