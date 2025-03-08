class findSecondMaxInArray {
    public static void main(String[] args) {
        int[] inArr = {13,34,2,34,33,1};
        int max=inArr[0], secondMax=inArr[0];
        for(int index=0;index<inArr.length;index++) {
            if(inArr[index] > max) {
                secondMax = max;    // Backup the value of max before changing it.
                max=inArr[index];
            } else if (inArr[index]>secondMax && inArr[index]!=max) { // check if current element is greater than secondMax. Also check if it is equal to max, in which case, don't do anything.
                secondMax=inArr[index];
            }
        }
        System.out.println("2nd Max: "+secondMax);
    }
}
