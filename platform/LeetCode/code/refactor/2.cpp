// 1491. https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/
class Solution {
public:
    double average(vector<int> &salary) {
        int i, min, max, sum, len;
        len = salary.size();
        min = max = salary[0];
        sum = 0;
        for (i = 0; i < len; i++) {
            if (salary[i] < min) {
                min = salary[i];
            }
            if (salary[i] > max) {
                max = salary[i];
            }
        }

        for (i = 0; i < len; i++) {
            sum = sum + salary[i];
        }
        sum = sum - min - max;
        double average = sum / (len - 2.0);
        return average;
    }
};