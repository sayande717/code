<ol type="1">
    <li> Data Structure: <strong> Array </strong>:
        <ol type="a">
            <li> 1-1.c: Accept the age of `n` employees and search for a particular age using `Sentinel search`. </li>
            <li> 1-2.c: In an array, accept age of `n` students. Only display those numbers that are perfect. A perfect number is equal to the sum of its proper divisors. </li>
            <li> 1-3.c: Accept your name and reverse it using a `recursive function` (without using a built-in function). Display the reversed name in the main module. </li>
        </ol>
    </li>
    <li> Data Structure: <strong>Stack</strong>:
        <ol type="a">
            <li> 2-1.c: Accept your name and perform stack operations on it. 
                <ul>
                    <li> To take limited number of strings as input in C (example 5), `scanf("%5s",&inStr);`. </li>
                </ul>
            </li>
            <li> 2-2.c: Accept any decimel number and convert to binary using stack. </li>
            <li> 2-3.c: Accept any arithmetic expression and covert to postfix using stack. </li>
        </ol>
    </li>
    <li> Data Structure: <strong>Queue</strong>
        <ol type="a">
            <li> 2-4.c: Perform linear queue operations on the height of N students. </li>
            <li> 2-5.c: Accept N patients token no and perform circular queue operations.
                <ul>
                    <li> `(rear+1)%n` calculates the next position after rear. </li>
                    <li> `(rear+(n-1))%n` calculates the previous position before rear. </li>
                    <li> In a circular queue, rear can be at any position, due to which we cannot check for the condition `rear==(queue.length-1)`. </li>
                </ul>
            </li>
        </ol>
    </li>
    <li> Data Structure: <strong> Linked List </strong>
    <ol type="a">
            <li> 3-1.c: Create a linked list to accept n students name and reg.no. Display the details  of all students </li>
            <li> 3-2.c: Perform the stack operations on a single linked list of n employees such as employee no and salary. If salary is >3000 then pop from the linked stack. </li>
            <li> 3-3.c: Perform Queue operations on a single linked list of in-patient records such as patient name, hospital no and date of admission. Assume patient is allowed to stay for 3 days only. After that patient to be discharged. In other words the patient details to be removed from the queue. </li>
            <li> 3-4.c: Create a single linked list to accept cricket players details such as name, age,  run score with overs completed. After creating a players  list check if a player scored runs 50 and above in 8 overs then remove that player and add it in the middle. If a player scored 80 runs between 15 and 20 overs, then remove that player and add at the beginning. If a player scored zero runs irrespective of overs then add at the last. Display the players list after each operation. <li>
</ol>
