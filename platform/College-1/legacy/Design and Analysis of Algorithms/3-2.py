def computeLPS(pattern):
    m = len(pattern)
    LPS = [0] * m
    length = 0
    i = 1

    while i < m:
        if pattern[i] == pattern[length]:
            length += 1
            LPS[i] = length
            i += 1
        else:
            if length != 0:
                length = LPS[length - 1]
            else:
                LPS[i] = 0
                i += 1
    return LPS

def KMPSearch(text, pattern):
    n = len(text)
    m = len(pattern)
    LPS = computeLPS(pattern)
    i = 0
    j = 0
    indexList = []

    while i < n:
        if text[i] == pattern[j]:
            i += 1
            j += 1

            if j == m:
                indexList.append(i - j)
                j = LPS[j - 1]
        else:
            if j != 0:
                j = LPS[j - 1]
            else:
                i += 1
    return indexList

def main():
    inputText = str(input("Enter string: "))
    inputPattern = str(input("Enter pattern: "))
    print(KMPSearch(inputText, inputPattern))    

main()