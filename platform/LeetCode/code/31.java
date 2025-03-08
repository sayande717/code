// 118. https://leetcode.com/problems/pascals-triangle/

import java.util.List;
import java.util.ArrayList;

class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> output = new ArrayList<>();

        // ADD: 1st Row
        List<Integer> row1 = new ArrayList<>();
        row1.add(1);
        output.add(row1);

        // EDGE: Number of rows: 1
        if (numRows == 1) {
            return output;
        }

        // ADD: Rest of the rows
        for (int row = 1; row < numRows; row++) {
            List<Integer> currentRow = new ArrayList<>();
            currentRow.add(1); // 1st 1
            for (int cell = 1; cell < row; cell++) {
                currentRow.add(output.get(row - 1).get(cell - 1) + output.get(row - 1).get(cell));
            }
            currentRow.add(1); // Last 1
            output.add(currentRow);
        }
        return output;
    }
}