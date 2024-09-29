def isOdd(num):
    return num % 2 != 0

def findSum(num):
    # Base Case
    if num < 10:
        return num
    sum = 0
    while num != 0:
        rem = num % 10
        sum = sum + rem
        num = int(num / 10)
    return findSum(sum)

def findChar(num):
    char = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i']
    return char[num - 1]

str_input = input().split(' ')
outStr = ""

for num in str_input:
    currentNum = int(num)
    currentNum = findSum(currentNum)
    if isOdd(currentNum):
        outStr = f"{outStr}{findChar(currentNum)}"
    else:
        outStr = f"{outStr}{currentNum}"

print(outStr, end='')
