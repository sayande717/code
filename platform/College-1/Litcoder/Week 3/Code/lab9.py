def runner(charlie_scores, dave_scores):
    # ERROR: if length is not 3, and the scores don't match
    if len(charlie_scores) != len(dave_scores) or len(charlie_scores) != 3:
        return
    
    charlie = 0
    dave = 0

    try:
        for index in range(3):
            score1 = int(charlie_scores[index])
            score2 = int(dave_scores[index])

            if score1 > score2:
                charlie += 1
            elif score2 > score1:
                dave += 1
    except ValueError:
        return
    
    return f'{charlie} {dave}'


arr1 = input().split(' ')
arr2 = input().split(' ')
print(runner(arr1, arr2), end=' ')
