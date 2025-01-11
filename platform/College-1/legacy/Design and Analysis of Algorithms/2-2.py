import math
import time

# Function to find the maximum of two numbers
def max(a, b):
    return a if a > b else b

def karatsuba(n1, n2):
    # If either of the numbers is single-digit, perform a simple multiplication. Otherwise, use the algorithm.
    # This logic also functions as the Base Condition.
    if n1 < 10 or n2 < 10:
        return n1 * n2

    # Calculate the number of digits in `n1` and `n2`.
    # `math.log10(1234+1)` gives us the number of digits in 1234.
    size1 = max(int(math.log10(n1) + 1), int(math.log10(n2) + 1))
    size2 = size1 // 2

    # Split the digits
    a = n1 // 10 ** size2
    b = n1 % 10 ** size2
    c = n2 // 10 ** size2
    d = n2 % 10 ** size2

    # Calculating intermediates
    z0 = karatsuba(b, d)
    z1 = karatsuba(a, c)
    z2 = karatsuba(a + b, c + d) - z1 - z0

    # Calculating result
    return z1 * 10 ** size1 + z2 * 10 ** size2 + z0

def multiply(n1,n2):
    return (n1*n2)

def main():
    number1 = int(input("Enter number 1: "))
    number2 = int(input("Enter number 2: "))

    # Current system time taken to demonstrate efficiency
    startTime = time.time()
    resultTraditional = multiply(number1, number2)
    endTime = time.time()
    timeTraditional = endTime - startTime

    startTime = time.time()
    resultKaratsuba = karatsuba(number1, number2)
    endTime = time.time()
    timeKaratsuba = endTime - startTime
    
    print("\nNumber 1:", number1)
    print("Number 2:", number2)
    
    print("\nTraditional Method:")
    print(f"Result: {resultTraditional}, Time Taken: {timeTraditional}")
    
    print("\nKaratsuba Method: ")
    print(f"Result: {resultKaratsuba}, Time Taken: {timeKaratsuba}")

main()