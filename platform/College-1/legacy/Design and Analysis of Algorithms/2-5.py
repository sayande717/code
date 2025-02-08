def longestCommonSubsequence(names1, names2):
    m = len(names1)
    n = len(names2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if names1[i - 1] == names2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    
    lcs_length = dp[m][n]
    
    # Retrieve the actual subsequence
    subsequence = []
    i = m
    j = n
    while i > 0 and j > 0:
        if names1[i - 1] == names2[j - 1]:
            subsequence.append(names1[i - 1])
            i -= 1
            j -= 1
        elif dp[i - 1][j] > dp[i][j - 1]:
            i -= 1
        else:
            j -= 1
    
    subsequence.reverse()
    
    return lcs_length, subsequence

nameArr1 = ["Sachin", "Virat", "Dhoni", "Rohit", "Jadeja"]
nameArr2 = ["Virat", "Sachin", "Jadeja", "Dhoni", "Rohit"]
print(f"Array 1 as per question: {nameArr1}")
print(f"Array 2 as per question: {nameArr2}")

lengthLCS, subsequence = longestCommonSubsequence(nameArr1, nameArr2)
print()
print(f"Length of the longest common subsequence: {lengthLCS}")
print(f"Actual subsequence: {subsequence}")
