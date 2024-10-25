# 1502. https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        arr = sorted(arr)
        diff = arr[0]-arr[1]
        for i in range(1,(len(arr)-1)):
            if arr[i]-arr[i+1] == diff:
                continue
            else:
                return False
        return True