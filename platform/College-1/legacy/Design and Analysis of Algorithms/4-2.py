def rabin_karp(text, pattern):
    n = len(text)
    m = len(pattern)
    d = 256
    q = 101
    h = 1
    p = 0
    t = 0
    result = []

    for index in range(m-1):
        h = (h * d) % q

    for index in range(m):
        p = (d * p + ord(pattern[index])) % q
        t = (d * t + ord(text[index])) % q

    for index in range(n - m + 1):
        if p == t:
            if text[index:index+m] == pattern:
                result.append(index)

        if index < n - m:
            t = (d * (t - ord(text[index]) * h) + ord(text[index + m])) % q
            if t < 0:
                t = t + q

    return result

text = "ABCCDDAEFG"
pattern = "CDD"
occurrences = rabin_karp(text, pattern)
print(f"Pattern found at indices: {occurrences}")
