To clone this repository, run:

```bash
git clone https://github.com/sayande717/code.git
```
## Notes
|ID| **Name** | **Notes** | **References** | **Progress** | **Status** |
|:--- | :---: | :---: | :---: | :---: | :---: |
|0| Theory | [Markdown](./notes/Theory.md) | null | null | `In Progress` |
|1| Languages/C++ | [Markdown](./notes/Languages.md#c++) | [FreeCodeCamp](https://youtu.be/8jLOx1hD3_o) | till 06:33:26 | `In Progress` |5|2| Languages/Java | null | [FreeCodeCamp](https://www.youtube.com/watch?v=2ZLl8GAk1X4&pp=ygUeZnJlZSBjb2RlIGNhbXAgZnVsbCBkc2EgY291cnNl) | till 10:05:10 | `In Progress` |
|2| Languages/Java | null | [FreeCodeCamp](https://www.youtube.com/watch?v=2ZLl8GAk1X4&pp=ygUeZnJlZSBjb2RlIGNhbXAgZnVsbCBkc2EgY291cnNl) | till 10:55:57, 23:26:00-23:51:38 | `In Progress` |
|4| Platform/LeetCode | [Markdown](./platform/LeetCode/README.md) | null | [link](#platform-leetcode)  |`In Progress` |
|6| Platform/GeeksForGeeks | [Markdown](./platform/GeeksForGeeks/README.md) | null | [link](#platform-geeksforgeeks)  |`In Progress` |
|-1| Platform/Internship/Pinnacle Labs | null | 1/3 | null |`In Progress` |

## Self
### \[Syntax\] Name of programming language:
1. [title.ext](/path/to/title.ext) | `Data Structure 1` `Data Structure 2`
    - Description
    - Important Takeaways
### Data Structures
> [Notes](https://github.com/sayande717/notes/blob/main/topics/Data-Structures.md) (in notes repository)

### C++
> [Notes](./notes/Languages.md#c++)

1. [hello.cpp](./self/C++/hello.cpp)
    - Hello, World!
    - Why `return 0`?
1. [add.cpp](./self/C++/add.cpp)
    - Add 2 numbers using function
    - Use both function and direct assignment to add 2 numbers.
1. [input.cpp](./self/C++/input.cpp)
    - Take input & print output
    - Input Stream: std::cin, std::getline(std::cin,string)
    - Output Streams: std::cout, std::cerr, std::clog
    - Data Type: std::string
1. [numbersystems.cpp](./self/C++/numbersystems.cpp)
    - Represent the number systems in C++
    - Number Systems: `Binary` `Octal` `Decimel` `Hexadecimel`
1. [initVariables.cpp](./self/C++/initVariables.cpp)
    - Different ways of initializing integers
        - When implicit conversion occurs
        - Variable modifiers: signed, unsigned, short, long
    - sizeof(): Find the size of different variables
    - Different ways of initializing fractional numbers
        - Set number precision for output screen
        - Infinity (1.5/0), NaN (0.0/0.0)
    - Initializing boolean values
    - Initializing characters
        - ASCII notation of characters
        - static_cast<int>('c')
    - Initializing variables without data types (`auto`)
1. [operationsData.cpp](./self/C++/operationsData.cpp)
    - [Full list](https://en.cppreference.com/w/cpp/language/operator_precedence)
    - Basic: +,-,*,/,%
    - Increment: ++ | Decrement: --
    - Compound Assignment: +=, -=, *=, /=, %=
    - Relational: <,<=,>,>=,==,!=
    - Logical: &&,||,!
1. [formatOutput.cpp](./self/C++/formatOutput.cpp)
    - [Full list](https://en.cppreference.com/w/cpp/io/manip)
    - Header files: `ios`, `iomanip`
    - Formatting the output
    - Formatters: `std::endl`, `std::fixed`, `std::setprecision(50)`
1. [regex.cpp](./self/C++/regex.cpp)
    - Initialize a regex pattern.
    - Perform pattern matching using regex.
1. [vector.cpp](./self/C++/vector.cpp)
    - Initialize vectors.
    - Data Types: Integer, String

### Java
<!-- > [Notes](./notes/Languages.md#java) -->

1. [initArray.java](./self/Java/initArray.java) | `Array`
    - Get started with arrays.
1. [rmIntegersFromArray.java](./self/Java/rmIntegersFromArray.java) | `Array`
    - Remove integers from the array.
1. [reverseArray.java](./self/Java/reverseArray.java) | `Array`
    - Directly print array in reverse.
    - Reverse the array in-place.
1. [findMinInArray.java](./self/Java/findMinInArray.java) | `Array`
    - Find the minimum value in the array.
1. [findSecondMaxInArray.java](./self/Java/findSecondMaxInArray.java) | `Array`
    - Find the 2nd maximum value in the array.
1. [mvZeroArray.java](./self/Java/mvZeroArray.java) | `Array`
    - Move all zeroes to the end of the array.
1. [findMissing.java](./self/Java/findMissing.java) | `Array`
    - Given an array of $n-1$ distinct numbers in the range $1$ to $n-1$, find the missing number.
    - Time constraint: $O(n)$
    - Using formula: Sum of 1st n natural numbers = $n(n+1)/2$
1. [palindromeString.java](./self/Java/palindromeString.java) | `String`
    - Check if a string is palindrome or not.
    - A palindrome string is one which remains same even when reversed.
1. [initSinglyLinkedList.java](./self/Java/initSinglyLinkedList.java) | `Linked List`
    - Create a singly linked list. 
    - Print the node values.
    - Add a node to beginning of the linked list.
1. [modify2SinglyLinkedLists.java](./self/Java/modify2SinglyLinkedLists.java) | `Linked List`
    - Add to the beginning of a linked list.
    - Add to the end of a linked list.
    - Add to a particular position in a linked list.
    - Delete the head node.
    - Delete the tail node.
    - Delete the node at a particular position.
    - Search for an element in a linked list, and return it's position.
    - Reverse the linked list.
    - Remove duplicates from linked list.
    - Return the nth number from the end.
    - Insert an element in a sorted linked list.
    - Delete an element from a linked list.
    - Detect a loop in a linked list.
    - Detect the starting point of a loop.
    - Break the loop.
1. [modify2SinglyLinkedList.java](./self/Java/modify2SinglyLinkedList2.java) | `Linked List`
    - Operations on 2 Singly Linked Lists
    - Merge 2 sorted linked lists
    - Add 2 sorted linked Lists
1. [initDoublyLinkedList.java](./self/Java/initDoublyLinkedList.java) | `Linked List`
    - Initialize a Doubly Linked List
    - Initialize functions to print the length of the Linked List, and check if it is empty.
    - Print the list forwards, and backwards.
    - Insert a node at the beginning and end of the linked list.
    - Delete the first and last node of the linked list.
1. [initSearch.java](./self/Java/initSearch.java)
    - Linear Search
    - Binary Search

### Go
<!-- > [Notes](./notes/Languages.md#go) -->
1. [booking-app](./self/Go/booking-app/main.go)
    - Initialize Go project with `go mod init booking-app`
    - Main file: `main.go`
    - Variables, Constants, printing them.
    - Mininal variable definition
    - Defining variables without value (value will be added later)
    - Data type
    - Formatters:
        - %v: value
        - %T: data type 
    - Taking user input
    - Initializing Arrays, Performing operations on them
    - Using `len()` to find length
    - Initializing Slices
    - Using `strings.Fields(str)`


> In case you can't access the link, the **Problem Description** has been provided in the respective **Intuition** part.

<center>

| Question | Intuition | Difficulty | Solution | Time Taken [MM:SS] |
| :---: | :---: | :---: | :---: | :---: |
| [387](https://leetcode.com/problems/first-unique-character-in-a-string/description/) | [show](./platform/leetcode/README.md#387)| Easy | [Java](./platform/leetcode/code/1.java) | Not recorded |
| [26](https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/) | [show](./platform/leetcode/README.md#26) | Easy | [Java](./platform/leetcode/code/2.java) | Not recorded |
| [121](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/) | [show](./platform/leetcode/README.md#121) | Easy | [Java](./platform/leetcode/code/3.java) | Not recorded |
| [1281](https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/) | [show](./platform/leetcode/README.md#1281) | Easy | [C++](./platform/leetcode/code/4.cpp) | Not recorded |
| [976](https://leetcode.com/problems/largest-perimeter-triangle/) | [show](./platform/leetcode/README.md#976) | Easy | [C++](./platform/leetcode/code/5.cpp) | Not recorded |
| [1779](https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/) | [show](./platform/leetcode/README.md#1779) | Easy | [C++](./platform/leetcode/code/6.cpp) | Not recorded |
| [1822](https://leetcode.com/problems/sign-of-the-product-of-an-array/) | [show](./platform/leetcode/README.md#1822) | Easy | [C++](./platform/leetcode/code/7.cpp) | Not recorded |
| [1502](https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/) | [show](./platform/leetcode/README.md#1502) | Easy | [Python](./platform/leetcode/code/8.py) | Not recorded |
| [1295](https://leetcode.com/problems/find-numbers-with-even-number-of-digits/) | [show](./platform/leetcode/README.md#1295) | Easy | [Java](./platform/leetcode/code/9.java) | Not recorded |
| [1672](https://leetcode.com/problems/richest-customer-wealth/) | [show](./platform/leetcode/README.md#1672) | Easy | [Java](./platform/leetcode/code/10.java) | Not recorded |
| [1](https://leetcode.com/problems/two-sum/) | [show](./platform/leetcode/README.md#1) | Easy | [Java](./platform/leetcode/code/11.java) | Not recorded |
| [9](https://leetcode.com/problems/palindrome-number/) | [show](./platform/leetcode/README.md#9) | Easy | [Java](./platform/leetcode/code/12.java) | Not recorded |
| [26](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | [show](./platform/leetcode/README.md#26) | Easy | [Java](./platform/leetcode/code/13.java) | Not recorded |
| [605](https://leetcode.com/problems/place-flowers/) | [show](./platform/leetcode/README.md#605) | Easy | [Java](./platform/leetcode/code/14.java) | 17:00 |
| [20](https://leetcode.com/problems/valid-parentheses/) | [show](./platform/leetcode/README.md#20) | Easy | [Java](./platform/leetcode/code/15.java) | Not recorded |
| [21](https://leetcode.com/problems/merge-two-sorted-lists/) | [show](./platform/leetcode/README.md#21) | Easy | [Java](./platform/leetcode/code/16.java) | Not recorded |
| [744](https://leetcode.com/problems/find-smallest-letter-greater-than-target/) | [show](./platform/leetcode/README.md#744) | Easy | [Java](./platform/leetcode/code/17.java) | Not recorded |
| [83](https://leetcode.com/problems/remove-duplicates-from-sorted-list/) | [show](./platform/leetcode/README.md#83) | Easy | [Java](./platform/leetcode/code/32.java) | 26:00 |
| [35](https://leetcode.com/problems/search-insert-position/) | [show](./platform/leetcode/README.md#35) | Easy | [Java](./platform/leetcode/code/33.java) | 21:00 |

</center>

## Platform/LeetCode
> Not started

## Platform/Internship
### Pinnacle Labs
1. [basic-calculator](./platform/Internship/Pinnacle Labs/basicCalculator.cpp)
    - Headers: `iostream` `regex` `string` `vector`.
    - Data Types: `character vector` `integer vector`.
    - Insert value into vectors, after they match with an expression.
    - Define a REGEX pattern, iterate over the REGEX pattern .
    - Type convert to integer, using `static_cast`.

1. [quiz](./platform/Internship/Pinnacle Labs/quiz.cpp)
    - Headers: `iostream` `future` `string` `iterator` `chrono` `map` `ctdlib` `vector`.
    - Data Types: `std::string array[]` `<std::string:std::string> map`.
    - Define a `<std::string:std::string> map`, iterate over the map, return it's key and value.
    - Return a `std::string array` from a function, using pointers.
    - Use `rand()` to generate random integers.

<center>

| Question | Intuition | Difficulty | Solution | Time Taken [MM:SS] |
| :---: | :---: | :---: | :---: | :---: |
|null|null|null|null|null|

</center>
