# Homework 03 Readme
Name: Jiawei Zhou

Github Account name: jwzhou1

Link to Assignment on Github: (copy and paste the link to your assignment repo here)

   https://github.com/jwzhou1/hw03.git

How many hours did it take you to complete this assignment (estimate)? 

   25 hours

Did you collaborate with any other students/TAs/Professors? If so, tell us who and in what capacity.  
- one per row, add more if needed

   No.

Did you use any external resources (you do not have to cite in class material)? (Cite them below)  
- one row per resource

   For question 1:
   https://www.quora.com/What-are-the-real-life-applications-of-stack-data-structure

   For question 2:
   https://www.geeksforgeeks.org/applications-of-queue-data-structure/#

   For question 3:
   https://www.geeksforgeeks.org/implement-a-stack-using-singly-linked-list/  
   https://www.simplilearn.com/tutorials/data-structure-tutorial/stack-implementation-using-array

   For question 5:
   https://www.geeksforgeeks.org/linked-list-vs-array/  
   https://staffwww.fullcoll.edu/aclifton/cs241/lecture-dynamic-mem-linked-lists.html
   https://towardsdatascience.com/linked-lists-vs-arrays-78746f983267


(Optional) What was your favorite part of the assignment? 

   We can study to use linkedlist to implement the Stack.

(Optional) How would you improve the assignment? 

   I will add more provided tests in the assignment.

## Further Thinking Questions

1. What are some cases you would use a stack?

   * Browser history: One case of using stacks is implementing the navigation functionality, such as back and forward buttons, in web browsers. A stack data structure can be utilized to maintain the browsing history. Each time a user visits a webpage, it can be pushed onto the stack. When the user wants to go back to the previous page, the most recent page is popped from the stack. This stack-based approach enables web browsers to efficiently track and manage the browsing history.

   * Undo/Redo functionality: By using a stack data structure, it becomes possible to track and manage user actions within the application. Each user action can be recorded and pushed onto the stack. When the user wishes to undo an action, the most recent action is popped from the stack, effectively returning the application state to a previous point. This stack-based approach enables users to easily undo and redo their actions, enhancing the user experience and providing greater flexibility in interacting with the application.


2. What are some cases you would use a queue?

   * Task scheduling: I would use a queue in managing job scheduling within operating systems or task scheduling in various applications. In this context, newly arrived jobs or tasks are enqueued into the queue, and the system processes them in the same order they were added. By following to the First-In-First-Out principle, queues ensure that jobs or tasks are executed in a sequential and orderly manner, maintaining the original order of arrival.

   * Printer queues: Printer queues use queues to manage the order of print jobs in printing systems. Print jobs are added to the queue as they are submitted, and the printer processes them in the order they were received.

   * Web servers: Web servers commonly utilize queues to handle incoming requests from clients. These requests are enqueued as they arrive and are then processed by the server in the same order that they were received.


3. Why is a linked list useful for implementing a stack? In your reply, consider if a stack was implemented with an array, and the values kept getting added to the front of the area, what would you have to do?

   A linked list is useful for implementing a stack because a stack follows the Last-In-First-Out (LIFO) principle. With a linked list, new items can be easily added or removed at the head of the list, which corresponds to the top of the stack. The head pointer points to the top of the stack, and pushing a new item onto the stack involves simply creating a new node and updating the head pointer to point to the new node. Similarly, popping an item off the stack involves updating the head pointer to point to the next item in the list.

   When implementing a stack with an array and continuously adding values to the front of the array, it becomes necessary to shift all existing elements in the array by one position to accommodate the new element at the front. However, this operation becomes very inefficient, particularly for larger arrays, and its performance becomes worse as the array size increases. In contrast, utilizing a linked list for implementing a stack offers the advantage of efficient insertion and removal at the head of the list. This makes the linked list a better choice for implementing a stack compared to an array-based implementation that requires shifting elements.

   Therefore, a linked list is a more suitable choice for implementing a stack due to its efficient insertion and deletion operations at the top, while arrays would require expensive shifting operations if values are added to the front.


4. Adding to the end of a singly linked list is expensive, because you have to cycle through the whole list. What is one thing you could change that would make adding to the end just as easy as adding to the front?

   One thing I could change that would make adding to the end just as easy as adding to the front is to use a **tail pointer** that always points to the last node in the linked list so that I can directly access the last node without traversing the entire list. By keeping track of both the head and the tail of the list, I can easily add or remove nodes from either end, making the singly linked list more efficient.

5. Thinking about memory, what is the difference between an array and a linked list? What is the advantage of each?

   Differences between an array and a linked list:

   * Memory allocation: Arrays allocate memory at compile time, whereas linked lists allocate memory at runtime.

   * Memory efficiency: Linked lists require additional memory for storing a reference to the next node along with the data, making them less memory-efficient than arrays for the same number of elements. However, the flexibility in size that linked lists offer may result in overall lower memory usage. This can be beneficial when dealing with data of uncertain or varying sizes.
   In contrast, when using arrays, memory is allocated up to the upper limit of their size, even if not all of it is being used. This can be wasteful when dealing with small amounts of data. On the other hand, linked lists can incrementally increase their size as needed, which can result in more efficient memory usage.

   Advantages of arrays:

   * Memory allocation: Arrays allocate memory at compile time, which can be advantageous in the case where the size of the data structure is known and fixed. This allows for efficient memory allocation and direct access to elements based on their index.

   * Memory efficiency: Arrays provide constant-time random access to elements, as each element's memory address can be calculated using its index. This makes arrays suitable for situations where frequent and immediate access to elements by index is needed.

   Advantages of linked lists:

   * Memory allocation: Linked lists offer flexibility in size, as memory for each node is allocated at runtime. This dynamic allocation enables efficient insertion and removal of elements at any position in the list, making linked lists suitable for the case where the size of the data structure may vary or is unknown in advance.

   * Memory efficiency: Although linked lists require additional memory for storing the reference to the next node, they can use memory more efficiently than arrays when dealing with varying or uncertain data sizes. Linked lists allocate memory on-demand, which means only the necessary memory is used. This can result in lower overall memory usage, particularly in scenarios where the size of the data structure fluctuates significantly.

## Reflection

There is a ton of research directly relating reflection to performance in Computer Science. The research has even gone as far as to show that reflection helps with job interviews and future promotions. Every few homeworks (and the midterm) we are going to have you write a reflection. When you write a reflection, you should focus on these key points (it should be a few paragraphs). DO NOT just bullet point your answer! This is counter productive! Instead, construct your answer into a proper paragraphs. 

1. Write a brief summary of the key learning points from this class, what you learned, both in and out of class.
2. Discuss how you feel about the usefulness and challenges in this class.
   * What was challenging for you?
   * What did you enjoy the most?
   * Can you apply your learning directly now or in the future?
3. Discuss how you can make future experiences in this area even more valuable. What are your social, personal and intellectual goals in this area?
   * How can you further expand upon your skills?
   * What do you need to do to improve study habits?
   * What areas do you need to work specifically related to coding?

For this reflection, we encourage you to focus on challenges, study habits, and ways you can improve. 