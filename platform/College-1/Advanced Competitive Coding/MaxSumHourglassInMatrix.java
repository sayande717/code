public class MaxSumHourglassInMatrix {
    private static int findSum(int[][] mat) {
        int rows = mat.length;
        int columns = mat[0].length;
        if(rows<3 || columns<3) {
            return -1;
        }
        int maxSum = Integer.MIN_VALUE;
        for(int i=0;i<(rows-2);i++) {
            int sum = 0;
            for(int j=0;j<(columns-2);j++) {
                sum = mat[i][j] + mat[i][j+1] + mat[i][j+2] + mat[i+1][j+1] + mat[i+2][j] + mat[i+2][j+1] + mat[i+2][j+2];
            }
            maxSum = Math.max(maxSum,sum);
        }
        return maxSum;
    }
    public static void main(String[] args) {
        int[][] arr = {{2,4,0,0},{0,1,1,0},{0,3,0,1}};
        System.out.println("Maximum Sum: "+findSum(arr));
    }
}