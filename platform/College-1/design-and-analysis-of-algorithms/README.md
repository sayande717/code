<ol type="1">
    <li> 1-1.c: You are given an undirected graph. The task is to assign colors to each vertex of the graph such that no two adjacent vertices share the same color, using the minimum number of colors. Implement the greedy coloring algorithm to solve this problem.
        <br><img src="./media/q1-1-1.png" alt="Graph" height="400px" />
    </li>
    <li> 1-2.c: You are given n jobs. Each job $J_i$ has a deadline $d_i$ and a profit $p_i$. Only one job can be scheduled at a time. The task is to find the sequence of jobs that maximizes the total profit while ensuring that no job is scheduled after its deadline.
        <table>
            <tr>
                <th>S. No.</th>
                <th>Jobs</th>
                <th>Deadlines</th>
                <th>Profits</th>
            </tr>
            <tr>
                <td>1</td>
                <td>J1</td>
                <td>2</td>
                <td>20</td>
            </tr>
            <tr>
                <td>2</td>
                <td>J2</td>
                <td>2</td>
                <td>70</td>
            </tr>
            <tr>
                <td>3</td>
                <td>J3</td>
                <td>1</td>
                <td>40</td>
            </tr>
            <tr>
                <td>4</td>
                <td>J4</td>
                <td>4</td>
                <td>110</td>
            </tr>
            <tr>
                <td>5</td>
                <td>J5</td>
                <td>5</td>
                <td>80</td>
            </tr>
        </table>
    <li> 2-1.py: Develop a Python program that use the divide and conquer technique to address the Domino Tiling Problem. Outline the process used in the divide and conquer approach for this particular problem. </li>
    <li> 2-2.py: Write a Python program to multiply two large integers using Karatsuba's fast multiplication method. Your implementation should demonstrate the efficiency of Karatsuba's algorithm compared to the standard multiplication method for large numbers.
        <ol type="a">
            <li> Use the `-lm` flag for compiling code having mathematical operations like pow(), log10(), etc. </li>
            <li> If either of the numbers is single-digit, perform a simple multiplication. Otherwise, use the algorithm.
            <li> $(\log_{10} 1234+1)$ gives us the number of digits in $1234$. </li>
        </ol>
    </li>
    <li> 2-3.py: Write a Python program to multiply two 4×4 matrices using Strassen's algorithm. Your program should be efficient and demonstrate the recursive nature of the algorithm. </li>
    <li> 2-4.py: You are given a sequence of matrices, and you need to determine the most efficient way to multiply these matrices together. Write a Python program that computes the minimum number of scalar multiplications needed to multiply the given chain of matrices using dynamic Programming. </li>
    <li> 2-5.py: You are given two sequences, and your task is to find the length of the longest subsequence that appears in both sequences. Write a Python program to compute the LCS and also to retrieve the actual subsequence.
        <ul>
            <li> Sequence names1 = ["Sachin","Virat","Dhoni","Rohit","Jadeja"] </li>
            <li> Sequence names2 = ["Virat","Sachin","Jadeja","Dhoni","Rohit"] </li>
        </ul>
    </li>
    <li> 3-1.py: Implement the Rabin-Karp algorithm to search for a given pattern in a large text string. Given a large string T of length n and a pattern P of length m, find all the starting indices where P appears as a substring in T using the Rabin-Karp algorithm. Assume that both the pattern P and the text T contain only lowercase English letters ('a' to 'z'). </li>
    <li> 3-2.py: You are given two strings: text and pattern. Your task is to find all occurrences of the pattern in the text using the Knuth-Morris-Pratt (KMP) algorithm and return the starting indices of these occurrences. </li>
    <li> 3-3.py: You are given an N×N chessboard. The objective is to place N queens on the board such that no two queens threaten each other. That is, no two queens should share the same row, column, or diagonal. </li>
    <li> 3-4.py: Given a set of integers and a target sum, determine if there is a subset of the given integers that adds up to the target sum. The solution must use backtracking to explore all possible subsets. </li>
</ol>
