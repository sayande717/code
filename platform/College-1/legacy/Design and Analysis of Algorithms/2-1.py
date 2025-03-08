# Recursive approach for Domino tiling
def dominoTiling(num):
    # Base condition
    if num == 0:
        return 1
    elif num == 1:
        return 1
    else:
        return dominoTiling(num-1) + dominoTiling(num-2)

# INPUT
rows = int(input("Enter the number of rows: "))
result = dominoTiling(rows)

# OUTPUT
print(f"Number of ways to tile {rows} rows is {result}.")
