class reverseArray {
    private static void reverseArrayInPlace(int[] inArr) {
        int fwdIndex, revIndex;
        for(fwdIndex=0,revIndex=inArr.length-1;fwdIndex<revIndex;fwdIndex++,revIndex--) {
            int temp = inArr[fwdIndex];
            inArr[fwdIndex] = inArr[revIndex];
            inArr[revIndex] = temp;
        }
    }

    private static void printArray(int[] inArr) {
        for(int index=0;index<inArr.length;index++) {
            System.out.print(inArr[index]+" ");
        }
    }

    public static void main(String[] args) {
        int[] inArr = {2,11,5,10,7,8};
        for(int index=(inArr.length-1);index>=0;index--) {
            System.out.print(inArr[index]+" ");
        }

        System.out.println();
        // Reverse in-place
        reverseArrayInPlace(inArr);
        printArray(inArr);        
    }
}
