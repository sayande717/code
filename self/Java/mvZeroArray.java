class mvZeroArray {
    private static int countZeroes(int[] inArr) {
        int zeroes=0;
        for(int index=0;index<inArr.length;index++) {
            if(inArr[index] == 0) {
                zeroes++;
            }
        }
        return zeroes;
    }

    private static void printArray(int[] inArr) {
        for(int index=0;index<inArr.length;index++) {
            System.out.print(inArr[index]+" ");
        }
    }

    private static int[] moveZeroes(int[] inArr) {
        int pointer1 = 0;
        int pointer2 = 0;
        while (pointer1<inArr.length) {
            // pointer1 is on the right of pointer2 if this is true
            if(inArr[pointer1]!=0 && inArr[pointer2]==0) {
                int temp=inArr[pointer1];
                inArr[pointer1]=inArr[pointer2];
                inArr[pointer2]=temp;
            }
            if(inArr[pointer2]!=0) {
                pointer2++;
            }

            pointer1++;
        }
        return inArr;
    }

    public static void main(String[] args) {
        int[] inArr1 = {0,1,0,0,12};
        int[] inArr2 = {8,1,2,1,0,0,3};
        int numberOfZeroes=countZeroes(inArr1);
        for(int iteration=0;iteration<numberOfZeroes;iteration++) {
        // We have to re-scan the array the same number of times as the number of zeroes in it.
            for(int index=0;index<(inArr1.length-1);index++) {
                if(inArr1[index+1] != 0) {
                    int temp = inArr1[index];
                    inArr1[index] = inArr1[index+1];
                    inArr1[index+1] = temp;
                }
            }
        }
        printArray(inArr1);
        System.out.println();
        printArray(moveZeroes(inArr2));
    }
}
