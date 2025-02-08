// 1281. https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0,product=1;
        while(n!=0) {
            int mod = n%10;
            sum=sum+mod;
            product=product*mod;
            n=n/10;
        }
        int result = product-sum;
        return result;
    }
};