// 88. 

import java.util.Arrays;
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int[] inArr1 = Arrays.copyOfRange(nums1,0,m);
        // inArr2 = nums2.
        
        int arr1Index = 0;
        int arr2Index = 0;
        int numsIndex = 0;
        while(arr1Index<m && arr2Index<n) {
            if(inArr1[arr1Index] <= nums2[arr2Index]) {
                nums1[numsIndex] = inArr1[arr1Index];
                arr1Index++;
                
            }
            else {
                nums1[numsIndex] = nums2[arr2Index];
                arr2Index++;
                // numsIndex++;
            }

            numsIndex++;
        }

        while(arr1Index<m) {
            nums1[numsIndex] = inArr1[arr1Index];
            arr1Index++;
            numsIndex++;
        }


        while(arr2Index<n) {
            nums1[numsIndex] = nums2[arr2Index];
            arr2Index++;
            numsIndex++;
        }
    }
}