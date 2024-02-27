class findMissing {
    private static int findSum(int input) {
        return (input*(input+1))/2;
    }
    public static void main(String[] args) {
        int[] inArr={1,2,3,5};
        int targetNum=findSum(inArr.length+1);    // There should've been a total of 4+1 elements in the array, including the missing element.
        for (int index = 0; index < inArr.length; index++) {
            targetNum=targetNum-inArr[index];
        }

        System.out.println("Target: "+targetNum);
    }
}
