class rmIntegersFromArray {
    private static boolean isEven(int input) {
        return (input%2 == 0);
    }

    private static int countNotEven(int[] inArr) {
        int count = 0;
        for(int index=0;index<inArr.length;index++) {
            if(!isEven(inArr[index])) {
                count++;
            }
        }
        return count;
    }

    private static void printArray(int[] inArr) {
        for(int index=0;index<inArr.length;index++) {
            System.out.print(inArr[index]+" ");
        }
    }

    public static void main(String[] args) {
        int[] inArr = {3,2,4,7,10,6,5};
        int[] outArr = new int[countNotEven(inArr)];
        int outArrIndex = 0;
        for(int inArrIndex = 0;inArrIndex<inArr.length;inArrIndex++) {
            if(!isEven(inArr[inArrIndex])) {
                outArr[outArrIndex] = inArr[inArrIndex];
                outArrIndex++;
            }
        }
        printArray(outArr);
    }
}
