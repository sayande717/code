# LeetCode
## 387
- Q.**387**: First Unique Character in a String
- **Problem Statement**: [Link](https://leetcode.com/problems/first-unique-character-in-a-string/description/)
- **Description**: Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
- **Constraints**: 
    - `s.length` -> $1$ to $10^5$
- **Example**:
    | Input: *String* | Output: *Integer* |
    | :---: | :---: |
    | $leetcode$ | $0$ |
    | $loveleetcode$ | $2$ |
    | $aabb$ | $-1$ |
- **Data Structure**: `Hashmap`
- **Logic**:
    1. Use the hashmap to store the frequency of all the elements.
    2. Traverse the hashmap. Return the first element whose frequency is 1.
- **Implementation**: [Code](./code/1.java)

## 26
- Q.**26**: Remove Duplicates from Sorted Array
- **Problem Statement**: [Link](https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/)
- **Description**: Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums. Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
    - Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
    - Return k.
- **Constraints**: 
    - `nums.length` -> $1$ to $3*10^4$
    - `nums[i]` -> $-100$ to $100$
- **Example**:
    | Input: *Integer Array* | Output: *Integer, Integer Array* |
    | :---: | :---: |
    | $[1,1,2]$ | $2$, $[1,2,\_]$ |
    | $[0,0,1,1,1,2,2,3,3,4]$ | $5$, $[0,1,2,3,4,\_,\_,\_,\_,\_]$ |
- **Data Structure**: `Array`
- **Logic**:
    1. If length of array is 1, return 1.
    2. Initialize index where unique elements should be placed, `addIndex`, as `1`. It it set to 1 to accomodate the first element (at index 0) of the array.
    3. Traverse through the array in the range (0 to nums.length-2).
        1. If nums[index] is less than nums[index+1], the elements are unique. In this case, place nums[index+1] in index `addIndex`.
        2. Increment `addIndex` by 1.
    4. Return `addIndex`.
- **Implementation**: [Code](./code/2.java)

## 121
- Q.**121**: Best Time to Buy and Sell Stock
- **Problem Statement**: [Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)
- **Description**: You are given an array prices where prices[i] is the price of a given stock on the ith day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return `0`.
- **Constraints**: 
    - `prices.length` -> $1$ to $10^5$
    - `prices[i]` -> $1$ to $10^4$

- **Example**:
    | Input: *Integer Array* | Output: *Integer* |
    | :---: | :---: |
    | $[7,1,5,3,6,4]$ | $5$ |
    | $[7,6,4,3,1]$ | $0$ |
- **Data Structure**: `Array`
- **Logic**:
    1. Assume lowest price to be the `current price` at `day 1`.
    2. Traverse through the `price[]` array.
        1. If the `price at the current index` is less than `lowest price`, replace it.
        2. Calculate the current profit at every step. It is the difference between the `price at the current index` & the `current lowest price`.
        3. If `current profit` is higher than `highest profit`, replace it.
    3. At the end, we will have the `highest profit` we can earn, which is the value to be returned.
- **Implementation**: [Code](./code/3.java)

## 1281
- Q.**1281**: Subtract the Product and Sum of Digits of an Integer
- **Problem Statement**: [Link](https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/)
- **Description**: Given an integer number n, return the difference between the product of its digits and the sum of its digits.
- **Constraints**: 
    - `n` -> $1$ to $10^5$
- **Example**:
    | Input: *Integer* | Output: *Integer* |
    | :---: | :---: |
    | $234$ | $15$ |
    | $4421$ | $21$ |
- **Data Structure**: `N/A`
- **Logic**:
    1. While `n` is not `0`, extract the digits one by one.
    2. Calculate the sum & product step-by-step.
    3. At the end, calculate the result, and return it.
- **Implementation**: [Code](./code/4.cpp)

## 976
- Q.**976**: Largest Perimeter Triangle
- **Problem Statement**: [Link](https://leetcode.com/problems/largest-perimeter-triangle/)
- **Description**: Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.
- **Constraints**: 
    - `nums.length` -> $3$ to $10^4$
    - `nums[i]` -> $1$ to $10^6$
- **Example**:
    | Input: *Integer Array* | Output: *Integer* |
    | :---: | :---: |
    | $[2,1,2]$ | $5$ |
    | $[1,2,1,10]$ | $0$ |
- **Data Structure**: `Vector Array`
- **Logic**:
    1. We first sort the input vector in ascending order. Then we traverse it in reverse ie from the largest element.
    2. We apply the geometry principle of the triangle: The sum of the lengths of any 2 sides of a triangle is greater than the length of the 3rd side.
    3. We check for this condition as we traverse through the vector. If it becomes true, we return the permeter of those 3 sides.
- **Implementation**: [Code](./code/5.cpp)

## 1779
- Q.**1779**: Find Nearest Point That Has the Same X or Y Coordinate
- **Problem Statement**: [Link](https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/)
- **Description**: You are given two integers, x and y, which represent your current location on a Cartesian grid: (x, y). You are also given an array points where each points[i] = [ai, bi] represents that a point exists at (ai, bi). A point is valid if it shares the same x-coordinate or the same y-coordinate as your location. Return the index (0-indexed) of the valid point with the smallest Manhattan distance from your current location. If there are multiple, return the valid point with the smallest index. If there are no valid points, return -1. <br>
    `The Manhattan distance between two points (x1, y1) and (x2, y2) is abs(x1 - x2) + abs(y1 - y2).`
- **Constraints**: 
    - `points.length` -> $1$ to $10^4$
    - `points[i].length` -> $2$
    - `x`, `y`, `a`<sub>`i`</sub>, `b`<sub>`i`</sub> -> $1$ to $10^4$
- **Example**:
    | Input: *Integer, Integer, Nested Integer Array* | Output: *Integer* |
    | :---: | :---: |
    | $3$, $4$, $[[1,2],[3,1],[2,4],[2,3],[4,4]]$ | $2$ |
    | $3$, $4$, $[[3,4]]$ | $0$ |
    | $3$, $4$, $[[2,3]]$ | $-1$ |
- **Data Structure**: `Vector Array`
- **Logic**:
    1. Initialise position & answer. Assume that answer is the maximum possible integer value (`INT_MAX`).
    2. Traverse through the input vector, array by array.
    3. For each array `[a,b]`, check if the point is valid, ie if `a` is equal to input `x`, or if `b` is equal to input `y`. If it is, then calculate the Manhattan distance.
    4. If the distance is less than the current answer, set the old position & answer to the current one.
- **Implementation**: [Code](./code/6.cpp)

## 1822
- Q.**1822**: Sign of the Product of an Array
- **Problem Statement**: [Link](https://leetcode.com/problems/sign-of-the-product-of-an-array/)
- **Description**: There is a function `signFunc(x)` that returns:
    ```
    1, if x is positive.
    -1, if x is negative.
    0, if x is equal to 0.
    ```
    You are given an integer array nums. Let product be the product of all values in the array nums. Return `signFunc(product)`.
- **Constraints**: 
    - `nums.length` -> $1$ to $1000$
    - `nums[i]` -> $-100$ to $100$
- **Example**:
    | Input: *Integer Array* | Output: *Integer* |
    | :---: | :---: |
    | $[-1,-2,-3,-4,3,2,1]$ | $1$ |
    | $[1,5,0,2,-3]$ | $0$ |
    | $[-1,1,-1,1,-1]$ | $-1$ |
- **Data Structure**: `Array`
- **Logic**:
    1. The logic is that if the number of negative elements is `odd`, the resultant product is `negative`, otherwise `positive`.
    2. Traverse through the array.
    3. If any element is `0`, return `0`.
    4. Count all elements that are negative.
    5. At last, return `1` is the count is even, otherwise return `-1`.
- **Implementation**: [Code](./code/7.cpp)

## 1502
- Q.**1502**: Can Make Arithmetic Progression From Sequence
- **Problem Statement**: [Link](https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/)
- **Description**: A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same. Given an array of numbers `arr`, return `true` if the array can be rearranged to form an arithmetic progression. Otherwise, return `false`.
- **Constraints**: 
    - `arr.length` -> $2$ to $1000$
    - `arr[i]` -> $-10^6$ to $10^6$
- **Example**:
    | Input: *Integer Array* | Output: *Boolean* |
    | :---: | :---: |
    | $[3,5,1]$ | $true$ |
    | $[1,2,4]$ | $false$ |

- **Data Structure**: `Array`
- **Logic**:
    1. Sort the input array.
    2. Calculate the difference between element 0 & 1.
    3. For the rest of the elements (ie index 1 to last), check if the difference is the same as the initially calculated difference.
    4. If at any point the condition becomes false, return `false`.
    5. If the loop completes without terminating, return `true`.
- **Implementation**: [Code](./code/8.py)

## 1295
- Q.**1295**: Find Numbers with Even Number of Digits
- **Problem Statement**: [Link](https://leetcode.com/problems/find-numbers-with-even-number-of-digits/)
- **Description**: Given an array nums of integers, return how many of them contain an even number of digits.
- **Constraints**: 
    - `nums.length` -> $1$ to $500$
    - `nums[i]` -> $1$ to $10^5$
- **Example**:
    | Input: *Integer Array* | Output: *Integer* |
    | :---: | :---: |
    | $[12,345,2,6,7896]$ | $2$ |
    | $[555,901,482,1771]$ | $1$ |

- **Data Structure**: `Array`
- **Logic**:
    1. Traverse through every element in the array.
    2. For each element, convert it to string using the in-built function.
    3. If it's length is even, then increment the counter.
    4. At last, return the counter.
- **Implementation**: [Code](./code/9.java)

## 1672
- Q.**1672**: Richest Customer Wealth
- **Problem Statement**: [Link](https://leetcode.com/problems/richest-customer-wealth/)
- **Description**: You are given an `m x n` integer grid accounts where `accounts[i][j]` is the amount of money the `i​​​​​​​​​​​th​​​​ customer` has in the `j​​​​​​​​​​​th​​​​ bank`. Return the wealth that the richest customer has. A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.
- **Constraints**: 
    - `m` -> $1$ to $unspecified$
    - `n` -> $unspecified$ to $50$
    - `accounts[i][j]` -> $1$ to $100$
- **Example**:
    | Input: *Nested Integer Array* | Output: *Integer* |
    | :---: | :---: |
    | $[[1,2,3],[3,2,1]]$ | $6$ |
    | $[[1,5],[7,3],[3,5]]$ | $10$ |
    | $[[2,8,7],[7,1,3],[1,9,5]]$ | $17$ |
- **Data Structure**: `Array`
- **Logic**:
    1. Traverse through every element in the array.
    2. For each element, convert it to string using the in-built function.
    3. If it's length is even, then increment the counter.
    4. At last, return the counter.
- **Implementation**: [Code](./code/10.java)

## 1
- Q.**1**: Two Sum
- **Problem Statement**: [Link](https://leetcode.com/problems/two-sum/)
- **Description**: Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`. You may assume that each input would have exactly one solution, and you may not use the same element twice. You can return the answer in any order.
- **Constraints**: 
    - `nums.length` -> $2$ to $10^4$
    - `nums[i]` -> $-10^9$ to $10^9$
    - `target` -> $-10^9$ to $10^9$
- **Example**:
    | Input: *Integer Array, Integer* | Output: *Integer Array* |
    | :---: | :---: |
    | $[2,7,11,15]$, $9$ | $[0,1]$ |
    | $[3,2,4]$, $6$ | $[1,2]$ |
    | $[3,3]$, $6$ | $[0,1]$ |
- **Data Structure**: `Array`
- **Logic**:
    1. We check every element with every other element for the condition. Element `0` is paired with element `1` to `last`, element `1` is paired with elements `2` to `last`, etc.
    2. We run 2 loops to accomplish the task.
    3. We also avoid checking the elements in the same index (`0` with `0`, or `1` with `1`) by performing a check prior to evaluating them.
- **Implementation**: [Code](./code/11.java)

## 9
- Q.**9**: Palindrome Number
- **Problem Statement**: [Link](https://leetcode.com/problems/palindrome-number/)
- **Description**: Given an integer `x`, return `true` if `x` is a palindrome, and `false` otherwise.
- **Constraints**: 
    - `x` -> $-2^{31}$ to $2^{31}-1$
- **Example**:
    | Input: *Integer* | Output: *Boolean* |
    | :---: | :---: |
    | $121$ | $true$ |
    | $-121$ | $false$
    | $10$ | $false$
- **Data Structure**: `String`
- **Logic**:
    1. Convert the input integer to a string using the in-built function.
    2. Setup 2 pointers, one traversing the input from the beginning (`head`), the other from the end (`tail`).
    3. While traversing, at any point, if the character at `head` found to be different from the character at `tail`, it means the string isn't palindrome. In that case, return `false` immediately and exit.
    4. If the for loop completes without terminating, return `true`.
- **Implementation**: [Code](./code/12.java)

## 26
- Q.**26**: Remove Duplicates from Sorted Array
- **Problem Statement**: [Link](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)
- **Description**: Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums. <br>
    Consider the number of unique elements of nums to be `k`, to get accepted, you need to do the following things: Change the array nums such that the first `k` elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums. Return k.
- **Constraints**: 
    - `nums.length` -> $1$ to $3*10^4$
    - `nums[i]`-> $-100$ to $100$
    - `nums` is sorted in **ascending** order.
- **Example**:
    | Input: *Integer* | Output: *Boolean* |
    | :---: | :---: |
    | $[1,1,2]$ | $2$, $[1,2,\_]$ |
    | $[0,0,1,1,1,2,2,3,3,4]$ | $5$, $[0,1,2,3,4,\_,\_,\_,\_,\_]$ |
- **Data Structure**: `Array`
- **Logic**:
    1. EDGE Case: If length of the array is 1, no duplicates exist.
    2. Initialize the index to add elements, `addIndex`, as 1.    1. Run a loop through the sorted input array.
    3. If the $i^{th}$ element is same as the $(i+1)^{th}$ element, `addIndex` stays in the location of the 1st instance of the duplicate element. Meanwhile, we keep incrementing the `i`.
    4. The first iteration where $i^{th}$ element becomes less than the $(i+1)^{th}$ element, we replace the larger element `nums[i+1]` with the duplicate element in location `addIndex`.
- **Implementation**: [Code](./code/13.java)

## 605
- Q.**605**: Can Place Flowers
- **Problem Statement**: [Link](https://leetcode.com/problems/can-place-flowers/)
- **Description**: You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots. Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return `true` if `n` new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and `false` otherwise.
- **Constraints**: 
    - `flowerbed.length` -> $1$ to $2*10^4$
    - `flowerbed[i]`-> $0$ or $1$
    - There are no adjacent flowers in `flowerbed`.
    - `n` -> $0$ to $flowerbed.length$
- **Example**:
    | Input: *Integer Array, Integer* | Output: *Boolean* |
    | :---: | :---: |
    | $[1,0,0,0,1]$, $1$ | $true$ |
    | $[1,0,0,0,1]$, $2$ | $false$ |
- **Data Structure**: `Array`
- **Logic**:
    1. Traverse through the input array.
        1. If any one of these conditions is true, the flower can be planted in the current `index`.
        2. If a flower is not present already.
        3. If there are no flowers before `index` **and** (if index **either** points to the `last element` **or** there are no flowers just after it).
        4. In the last point, 2 checks are needed in the 2nd part because if `index` points to the last element, `flowerbed[index+1]` is going to return an `ArrayIndexOutOfBoundsException`.
    2. If a flower can be planted, plant it. Decrease `n` by `1`, because 1 flower has already been planted.
- **Implementation**: [Code](./code/14.java)

## 20
- Q.**20**: Valid Parentheses
- **Problem Statement**: [Link](https://leetcode.com/problems/valid-parentheses/)
- **Description**: Given a string s containing just the characters `'(', ')', '{', '}', '[' and ']'`, determine if the input string is valid.
    An input string is valid if:
    ```
    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.
    ```
- **Constraints**: 
    - `s.length` -> $1$ to $10^4$
    - `s` -> $($, $[$, $\{$, $)$, $]$ or $\}$
- **Example**:
    | Input: *String* | Output: *Boolean* |
    | :---: | :---: |
    | $"()"$ | $true$ |
    | $"()[]{}"$ | $true$ |
    | $"(]"$ | $false$ |
- **Data Structure**: `Stack`
- **Logic**:
1.  We traverse through the string.
    1. For every `(` we encounter, we push `)` into the stack.
    2. For every `[` we encounter, we push `]`.
    3. For every `{` we encounter, we push `}`.
2. If we encounter none of these 3, we check if:
    1. **either** the stack is empty [which means no opening brace was encountered earlier],
    2. **or** if the topmost element (after popping from the stack) isn't equal to the character at the current index [The opening brace was probably encountered before but isn't being closed in order]. If either of these conditions is true, return `false`.
3. If the loop completes without interruptions, then there can be 2 conditions:
    1. The stack is empty, which means all braces present were closed in order. Return `true`.
    2. The stack is not empty, which means some braces weren't closed at all. Return `false`.
- **Implementation**: [Code](./code/15.java)

## 21
- Q.**21**: Merge Two Sorted Lists
- **Problem Statement**: [Link](https://leetcode.com/problems/merge-two-sorted-lists/)
- **Description**: You are given the heads of two sorted linked lists list1 and list2. Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists. Return the head of the merged linked list.
- **Constraints**: 
    - `Node.val` -> $-100$ to $100$
    - `list1`, `list2` -> sorted in ascending order
- **Example**:
    | Input: *Integer Array, Integer Array* | Output: *Integer Array* |
    | :---: | :---: |
    | $[1,2,4]$, $[1,3,4]$ | $[1,1,2,3,4,4]$ |
    | $[]$, $[]$ | $[]$ |
    | $[]$, [0] | $[0]$ |
- **Data Structure**: `Custom [ListNode]`
- **Logic**:
    1. We initialise 2 pointers which point to the head of `list1` and `list2` respectively.
        1. While `list1` **and** `list2` are not null, check the current elements of both lists.
        2. Put the smaller element in the output list, and move the pointer 1 step ahead (`current = current.next`).
        3. At last, move the output list pointer 1 step ahead.
    2. After the loop ends, there may still be elements left since the lists aren't of the same size. So, we need to re-check both of them.
- **Implementation**: [Code](./code/16.java)

## 744
- Q.**744**: Find Smallest Letter Greater Than Target
- **Problem Statement**: [Link](https://leetcode.com/problems/find-smallest-letter-greater-than-target/)
- **Description**: You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters. Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.
- **Constraints**: 
    - `letters.length` -> $2$ to $10^4$
    - `letters[i]` -> lowercase English letter
    - `letters` -> sorted in ascending order, contains $>=2$ different characters
    - `target` -> lowercase English letter
    - 
- **Example**:
    | Input: *Character Array, Character* | Output: *Character* |
    | :---: | :---: |
    | $["c","f","j"]$, $a$ | $c$ |
    | $["c","f","j"]$, $c$ | $f$ |
    | $["x","x","y","y"]$, $z$ | $x$ |

- **Data Structure**: `Array`
- **Logic**:
    1. We will use `Binary Search` to solve the problem.
    2. EDGE Case: If there's only 1 element in the input array, there's no point in searching for anything, so we simply return that element.
    3. SPECIAL Case: Interestingly, after the loop ends, `start` always lands at the 2nd largest character, which is the result we want.
- **Implementation**: [Code](./code/17.java)

## 34
- Q.**34**: Find First and Last Position of Element in Sorted Array
- **Problem Statement**: [Link](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
- **Description**: Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value. If target is not found in the array, return `[-1, -1]`. You must write an algorithm with `O(log n)` runtime complexity.
- **Constraints**: 
    - `nums.length` -> $0$ to $10^5$
    - `nums[i]` -> $-10^9$ to $10^9$
    - `nums` -> sorted in ascending order
    - `target` -> $-10^9$ to $10^9$
- **Example**:
    | Input: *Integer Array, Integer* | Output: *Integer Array* |
    | :---: | :---: |
    | $[5,7,7,8,8,10]$, $8$ | $[3,4]$ |
    | $[5,7,7,8,8,10]$, $6$ | $[-1,-1]$ |
    | $[]$, $0$ | $[-1,-1]$ |

- **Data Structure**: `Array`
- **Logic**:
    1. We use Binary Search to solve the problem.
    2. When we fine the `target`, we have 2 possible cases.
        1. We find the 1st occurence of the `target`. In this case, we have to find the last (or next) occurence of the `target`. `startIndex` = `true`.
        2. We find the last occurence of the `target`. In this case, we have to find the 1st occurence of the `target`. `startIndex` = `false`.
    3. First, we initialise the output array to `[-1,-1]`.
    4. Then, we proceed to search for the 1st occurence, by setting `startIndex` to `true`.
    5. If the 1st occurence is not found, there's no point in searching further because the element does not exist.
    6. If the 1st occurenct is found, we proceed to search for the last occurence by searching further, ie by setting `searchIndex` to `false`.
    7. Finally, we return `answer`, which is the solution to our problem.
- **Implementation**: [Code](./code/18.java)

## 88
- Q.**88**: Merge Sorted Array
- **Problem Statement**: [Link](https://leetcode.com/problems/merge-sorted-array/)
- **Description**: You are given two integer arrays `nums1` and `nums2`, sorted in non-decreasing order, and two integers `m` and `n`, representing the number of elements in `nums1` and `nums2` respectively. Merge `nums1` and `nums2` into a single array sorted in non-decreasing order. <br>
    The final sorted array should not be returned by the function, but instead be stored inside the array `nums1`. To accommodate this, `nums1` has a length of `m + n`, where the first `m` elements denote the elements that should be merged, and the last `n` elements are set to `0` and should be ignored. `nums2` has a length of `n`.
- **Constraints**: 
    - `nums1.length` -> $m+n$
    - `nums2.length` -> $n$
    - `m` >= $0$
    - `n` <= $200$
    - $1$ <= `m+n` <= $200$
    - `nums1[i]` >= $-10^9$
    - `nums2[j]` <= $10^9$
- **Example**:
    | Input: *$Integer Array^2$, $Integer^2$* | Output: *Integer Array* |
    | :---: | :---: |
    | $[1,2,3,0,0,0]$, $3$, $[2,5,6]$, $3$ | $[1,2,2,3,5,6]$ |
    | $[1]$, $1$, $[]$, $0$ | $[1]$ |
    | $[0]$, $0$, $[1]$, $1$ | $[1]$ |

- **Data Structure**: `Array`
- **Logic**:
    1. We use Binary Search to solve the problem.
    2. When we fine the `target`, we have 2 possible cases.
        1. We find the 1st occurence of the `target`. In this case, we have to find the last (or next) occurence of the `target`. `startIndex` = `true`.
        2. We find the last occurence of the `target`. In this case, we have to find the 1st occurence of the `target`. `startIndex` = `false`.
    3. First, we initialise the output array to `[-1,-1]`.
    4. Then, we proceed to search for the 1st occurence, by setting `startIndex` to `true`.
    5. If the 1st occurence is not found, there's no point in searching further because the element does not exist.
    6. If the 1st occurenct is found, we proceed to search for the last occurence by searching further, ie by setting `searchIndex` to `false`.
    7. Finally, we return `answer`, which is the solution to our problem.
- **Implementation**: [Code](./code/18.java)

## 88
- Q.**83**: Remove duplicates from sorted list
- **Problem Statement**: [Link](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)
- **Description**: Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
- **Constraints**:
    - Number of nodes is in the range [0, 300].
    - -100 <= `Node.val` <= 100
    - List is sorted in ascending order.
- **Example**:
    | Input: *Integer Linked List* | Output: *Integer Linked List* |
    | :---: | :---: |
    | $[1,1,2]$ | $[1,2]$ |
    | $[1,1,2,3,3]$ | $[1,2,3]$ |

- **Data Structure**: `Linked List`
- **Logic**:
    1. If head is `null` or there's only 1 element in the list, return head.
    2. Run a loop till `current.next` is not `null`.
    3. Check if the value at current node is same as the value at the next node.
        1. If true, make current node point to the next's next node (`current.next == current.next.next`).
        2. If false, move current to the next node (`current=current.next`).
    4. Return head.
- **Implementation**: [Code](./code/32.java)

## 35
- Q.**83**: Remove duplicates from sorted list
- **Problem Statement**: [Link](https://leetcode.com/problems/search-insert-position/)
- **Description**: Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order. You must write an algorithm with $O(log n)$ runtime complexity.

- **Constraints**:
    - $1 \leq nums.length \leq 10^4$
    - $-10^4 \leq nums[i] \leq 10^4$
    - $nums$ contains distinct values sorted in ascending order.
    - $-10^4 \leq target \leq 10^4$

- **Example**:
    | Input: *Integer Array*, *Integer* | Output: *Integer Array* |
    | :---: | :---: |
    | $[1,3,5,6]$, $5$ | $2$ |
    | $[1,3,5,6]$, $2$ | $1$ |
    | $[1,3,5,6]$, $7$ | $4$ |

- **Data Structure**: `Array`
- **Logic**:
    1. Implement the usual Binary Search.
    2. If `nums[mid]` matches the target, return `mid`.
    3. If the while loop ends without returning anything, `low` will point to the index where it would be if it were inserted in order. So, return `low`.

- **Implementation**: [Code](./code/33.java)

<!-- ## 1523
- Q.**1523**: Count Odd Numbers in an Interval Range
- **Problem Statement**: [Link](https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/)
- **Description**: Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
- **Data Structure**: `Hashmap`
- **Logic**:
    1. Use the hashmap to store the frequency of all the elements.
    2. Traverse the hashmap. Return the first element whose frequency is 1.
-->
