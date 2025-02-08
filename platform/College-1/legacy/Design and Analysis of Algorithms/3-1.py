def rabinKarp(text, pattern):
    n = len(text)
    m = len(pattern)
    indexList = []

    patternHash = sum(ord(pattern[i]) for i in range(m))
    
    stringHash = sum(ord(text[i]) for i in range(n))
    
    for i in range(n - m + 1):
        if patternHash == stringHash:
            if text[i:i + m] == pattern:
                indexList.append(i)

        if i < n - m:
            stringHash = stringHash - ord(text[i]) + ord(text[i + m])
    return indexList

def main():
    inputText = str(input("Enter string: "))
    inputPattern = str(input("Enter pattern: "))
    print(rabinKarp(inputText, inputPattern))    

main()
