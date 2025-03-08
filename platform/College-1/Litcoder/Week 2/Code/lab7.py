def findSumPairs(arr, divisor):
    count = 0
    for ptr1 in range(len(arr)):
        for ptr2 in range(ptr1 + 1, len(arr)):
            if (arr[ptr1] + arr[ptr2]) % divisor == 0:
                count += 1
    return count

# Read the divisor
divisor = int(input())

# Read the array of integers
arr = list(map(int, input().split()))

# Print the result
print(findSumPairs(arr, divisor), end='')
