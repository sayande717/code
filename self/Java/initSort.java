import java.util.Arrays;
class initSort{
    public String bubbleSort(int[] inArr) {
        // Here, at every iteration, we check if the element in the current index is greater than the next one. If it is, we swap the two.
        // After every pass, the end part of the array gets sorted. After the first pass, the last element is sorted, after the 2nd pass, the last 2 elements are sorted, etc.
        // Consequently, we remember to exclude the part that is sorted.
        // IMPROVEMENT: Add a `isSwapped` variable to the mix. If no swaps have taken place in the current pass, it means the array is already sorted, so break out.
        int pass=1;
        // for inArr.length=5:
        // > outer loop runs from 0 to 3
        // > inner loop runs from 4 to 1
        for(int i=0;i<(inArr.length-1);i++) {
            boolean isSwapped=false;
            for(int index=0;index<(inArr.length-1-i);index++) {
                if(inArr[index]>inArr[index+1]) {
                    int temp = inArr[index];
                    inArr[index] = inArr[index+1];
                    inArr[index+1] = temp;
                    isSwapped=true;
                }
            }
            
            // Print Intermediate result
            System.out.println("Pass "+(pass)+": "+Arrays.toString(inArr));
            pass++;

            if(!isSwapped) {
                break;
            }
        }
        return Arrays.toString(inArr);
    }

    public static void main(String[] args) {
        initSort ob = new initSort();
        int[] array0 = {9,8,7,4,1,0};
        int[] array1 = {1,2,3,4,5,6};
        System.out.println("Pass 0 [Unsorted]: "+Arrays.toString(array0));
        System.out.println("Result: "+ob.bubbleSort(array0));

        System.out.println("\nPass 0 [Sorted]: "+Arrays.toString(array1));
        System.out.println("Result: "+ob.bubbleSort(array1));

    }
}
