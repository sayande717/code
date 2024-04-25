public class initSearch {
    public int linearSearch(int[] inArr, int target) {
        for(int index=0;index<inArr.length;index++) {
            if(inArr[index]==target) {
                return index;
            }
        }
        return -1;
    }

    public int binarySearch(int[] inArr, int target) {
        int start = 0;
        int end = inArr.length;
        while(start<=end) {
            int mid = start+((end-start)/2);
            if(inArr[mid]<target) {
                start = mid+1;
            } else if(inArr[mid]>target) {
                end = mid-1;
            } else {
                return mid;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        initSearch ob = new initSearch();
        int[] array = {5,6,2,3,8,9};
        int[] sortedArray = {1,2,3,4,5,6,7,8,9};
        int[] sortedArrayRev = {9,8,7,6,5,4,3,2,1};

        byte target = 8;

        int linearSearch = ob.linearSearch(array,target);
        int binarySearch = ob.binarySearch(sortedArray,target);
    
        System.out.println(binarySearch);
    }
}
