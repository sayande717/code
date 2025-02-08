// TODO: What if the array contains a `0` in it?
public class maxProductSubArray {
    public static void main(String[] args) {
        int[] arr = {1,2,3,4,5};
        int n = arr.length;
        int maxProd=1;
        for(int i=0;i<n;i++) {
            int currentProd = arr[i];
            for(int j=(i+1);j<n;j++) {
                currentProd=currentProd*arr[j];
                // check for max product
                if(currentProd>maxProd) {
                    maxProd=currentProd;
                }
            }
        }

        System.out.print("Maximum product: "+maxProd);
        System.exit(0);
    }
}
