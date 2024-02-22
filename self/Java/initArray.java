class initArray {
    public static void main(String[] args) {
        // Initialize
        int[] arr1 = new int[5]; // By default, the value is 0.
        int[] arr2 = {6,7,8,9,10};

        // Add/Update
        arr1[1] = 11;

        // Print
        for(int index = 0; index < arr1.length; index++) {
            System.out.print(arr1[index]+" ");
        }

        System.out.println();

        for(int index = 0; index < arr2.length; index++) {
            System.out.print(arr2[index]+" ");
        }

        // Functions
        int length = arr1.length;
        int lastElement = arr1[arr1.length-1];
    }
}
