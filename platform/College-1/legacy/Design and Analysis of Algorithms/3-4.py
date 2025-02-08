def findSubsetSum(nums, target):
    def backtrack(start, currentSum, path):
        if currentSum == target:
            return True, path
        if currentSum > target or start == len(nums):
            return False, []
        
        # Include the current number
        found, result = backtrack(start + 1, currentSum + nums[start], path + [nums[start]])
        if found:
            return True, result
        
        # Exclude the current number
        found, result = backtrack(start + 1, currentSum, path)
        if found:
            return True, result
        
        return False, []
    
    found, subset = backtrack(0, 0, [])
    if found:
        print("Subset found:", subset)
    else:
        print("No subset found")
    return found

def main():
    nums = [3, 34, 4, 12, 5, 2]
    target = 9
    findSubsetSum(nums, target) # Print the first subset formed.
 
main()
