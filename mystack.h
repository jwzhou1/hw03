/*  ========== H03 - Personal Stack Implementation ============
 *
 *   Student: Jiawei Zhou
 *   Semester: Summer 2023
 *
 * A simple stack implementation to hold int values.
 *
 */

#ifndef MYSTACK_H
#define MYSTACK_H
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

/** Stores the maximum 'depth' of our stack.
(i.e. capacity cannot exceed MAX_DEPTH for any stack) **/
#define MAX_DEPTH 32

/** Create a node data structure to store data within
our stack. In our case, we will stores 'integers' */
typedef struct node
{
    int data;
    struct node *next;
} node_t;

/** Create a stack data structure
* Our stack holds a single pointer to a node, which
* is a linked list of nodes. 
**/
typedef struct stack
{
    int count;             // count keeps track of how many items
                           // are in the stack.
    unsigned int capacity; // Stores the maximum size of our stack
    node_t *head;          // head points to a node on the top of our stack.
} neu_stack;

/**  Creates a stack
* Returns a pointer to a newly created stack.
* The stack should be initialized with data on the heap.
* (Think about what the means in terms of memory allocation)
* The stacks fields should also be initialized to default values.
*/
neu_stack *create_stack(unsigned int capacity)
{
    neu_stack *myStack = (neu_stack *)malloc(sizeof(neu_stack));
    if (myStack != NULL)
    {
        myStack->count = 0;
        myStack->capacity = capacity;
        myStack->head = NULL;
    }
    return myStack;
}

/** Check if the stack is empty
* Returns 1 if true (The stack is completely empty)
* Returns 0 if false (the stack has at least one element enqueued)
*/
int stack_empty(neu_stack *s)
{
    if (s->head == NULL || s->count == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/** Check if the stack is full
* Returns 1 if true (The Stack is completely full, i.e. equal to capacity)
* Returns 0 if false (the Stack has more space available to enqueue items)
**/
int stack_full(neu_stack *s)
{
    if (s == NULL || s->count == s->capacity)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/** Enqueue a new item
* i.e. push a new item into our data structure
* Returns a -1 if the operation fails (otherwise returns 0 on success).
*    -> if the Stack is full that is an error, but does not crash the program.
**/
int stack_enqueue(neu_stack *s, int item)
{
    if (s == NULL || stack_full(s))
    {
        return -1;
    }

    node_t *newIteam = (node_t *)malloc(sizeof(node_t));

    if (newIteam != NULL)
    {
        newIteam->data = item;
        newIteam->next = s->head;
        s->head = newIteam;
        s->count++;

        return 0;
    }
    else
    {
        return -1;
    }
}

/** Dequeue an item
*   Returns the item at the front of the stack and
*   removes an item from the stack.
*   Removing an item from the empty stack should
*   print to stderr, and return the EXIT_FAILURE value
*   Example:
     fputs("no items to dequeue!\n", stderr);
     return EXIT_FAILURE
**/
int stack_dequeue(neu_stack *s)
{
    if (s == NULL || s->head == NULL)
    {
        fputs("no items to dequeue!\n", stderr);
        return EXIT_FAILURE;
    }
    int item = s->head->data;
    node_t *temp = s->head;
    s->head = temp->next;
    s->count--;
    free(temp);
    return item;
}

/** returns the size of the stack. If the
 * stack hasn't been properly recreated, print to stderr, 
 * and return -1 
*/
unsigned int stack_size(neu_stack *s)
{
    if (s == NULL)
    {
        fputs("Stack has not been properly created.\n", stderr);
        return -1;
    }
    return s->count;
}

/** Removes a stack and ALL of its elements from memory.
 *  This should be called before any program terminates.
 *  Simple ignores if an invalid stack is passed to it.
 **/
void free_stack(neu_stack *s)
{
    if (s == NULL)
    {
        return;
    }
    node_t *current = s->head;
    while (current != NULL)
    {
        node_t *next = current->next;
        free(current);
        current = next;
    }
    free(s);
}

#endif