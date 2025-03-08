// 605. https://leetcode.com/problems/can-place-flowers/

class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        for(int index = 0; index < flowerbed.length;index++) {
            if(flowerbed[index] == 0) {
                if((index == 0 || flowerbed[index-1] == 0) && (index == flowerbed.length-1 || flowerbed[index+1] == 0)) {
                    flowerbed[index] = 1;
                    n--;
                }
            }
        }
        if(n > 0) {
            return false;
        }
        return true;
    }
}