def print_common():
    freq_dict = {}

    # Loop to read input 3 times
    for _ in range(3):
        in_arr = input().split(' ')
        for num in in_arr:
            num = int(num)
            freq_dict[num] = freq_dict.get(num, 0) + 1

    found = False

    # Iterate through the dictionary to find common elements
    for key, value in freq_dict.items():
        if value == 3:
            found = True
            print(f'{key} ', end='')

    if not found:
        print('No Elements', end='')

# Call the function
print_common()
