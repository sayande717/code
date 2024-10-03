import java.util.Arrays;

public class initSearch {
    private int linearSearch(int[] inArr, int target) {
        for(int index=0;index<inArr.length;index++) {
            if(inArr[index]==target) {
                return index;
            }
        }
        return -1;
    }

    private int binarySearch(int[] inArr, int target) {
        int start = 0;
        int end = inArr.length-1;

        while(start<=end) {
            if(inArr[start]==inArr[end]) {
                // All elements within the array are same.
                if(inArr[start]==target) { // OR (inArr[end]==target)
                    // All elements in the array:
                    // - are same.
                    // - are equal to the target.
                    return start;
                }
                // All elements in the array:
                // - are same.
                // - are not the target.
                return -1;
            }

            int mid = start+(end-start)/2;
            if(inArr[mid]<target) {
                start = mid+1;
            } else if(inArr[mid]>target) {
                end = mid-1;
            } else {
                return mid;
            }
        }

        return -1;
        // If element is not found, `start` points to the index where it would've been, if it was present in the array.
        // return start;
    }

    public static void main(String[] args) {
        initSearch ob = new initSearch();
        int[] array = {5,6,2,3,8,9};
        int[] sortedArray = {1,2,3,4,5,6,7,8,9};
        int[] sortedArrayRev = {9,8,7,6,5,4,3,2,1};

        int target = 8;

        int linearSearch = ob.linearSearch(array,target);
        int binarySearch = ob.binarySearch(sortedArray,target);
        System.out.println("Array: "+Arrays.toString(sortedArray));
        System.out.println("Index: "+binarySearch);
    }
}
