class findMinInArray {
    private static void printArray(int[] inArr) {
        for(int index=0;index<inArr.length;index++) {
            System.out.print(inArr[index]+" ");
        }
    }

    public static void main(String[] args) {
        int[] inArr = {5,9,3,15,1,2};
        int minValue = inArr[0];
        for(int index=0;index<inArr.length;index++) {
            if(inArr[index] < minValue) {
                minValue = inArr[index];
            }
        }
        System.out.println("Minimum value: "+minValue);
    }
}
