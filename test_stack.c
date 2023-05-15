/*  ========== H03 - Personal Queue Implementation ============
 *
 *   Student: Jiawei Zhou
 *   Semester: Summer 2023
 *
 * A simple queue unit-tst implementation
 *
 */

#include "mystack.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.

// A sample test of your program
// You can add as many unit tests as you like
// We will be adding our own to test your program.

// Tests the capacity of a stack
int unitTest1(int status)
{
    int passed = 0;

    neu_stack *test_s = create_stack(MAX_DEPTH);
    if (MAX_DEPTH == test_s->capacity)
    {
        passed = 1;
    }

    free_stack(test_s);

    return passed;
}

// Enqueu several items into a stack and test the size
int unitTest2(int status)
{
    int passed = 0;

    neu_stack *test_s = create_stack(MAX_DEPTH);
    stack_enqueue(test_s, 1);
    stack_enqueue(test_s, 2);
    stack_enqueue(test_s, 3);
    stack_enqueue(test_s, 4);
    stack_enqueue(test_s, 5);
    stack_enqueue(test_s, 6);
    stack_enqueue(test_s, 7);
    stack_enqueue(test_s, 8);
    stack_enqueue(test_s, 9);
    stack_enqueue(test_s, 10);

    if (10 == stack_size(test_s))
    {
        passed = 1;
    }

    free_stack(test_s);

    return passed;
}

// Tests enqueuing and fully dequeing a stack
int unitTest3(int status)
{
    int passed = 0;

    neu_stack *test_s = create_stack(MAX_DEPTH);
    int i = 0;
    for (i = 0; i < MAX_DEPTH; i++)
    {
        stack_enqueue(test_s, 1);
    }
    for (i = 0; i < MAX_DEPTH; i++)
    {
        stack_dequeue(test_s);
    }

    if (0 == stack_size(test_s))
    {
        passed = 1;
    }

    free_stack(test_s);

    return passed;
}

// Tests enqueuing and fully dequeing a stack multiple times
int unitTest4(int status)
{
    int passed = 0;

    neu_stack *test_s = create_stack(MAX_DEPTH);
    int i = 0;
    for (i = 0; i < MAX_DEPTH; i++)
    {
        stack_enqueue(test_s, 1);
    }
    for (i = 0; i < MAX_DEPTH; i++)
    {
        stack_dequeue(test_s);
    }
    for (i = 0; i < MAX_DEPTH; i++)
    {
        stack_enqueue(test_s, 1);
    }
    for (i = 0; i < MAX_DEPTH; i++)
    {
        stack_dequeue(test_s);
    }
    if (0 == stack_size(test_s))
    {
        passed = 1;
    }

    free_stack(test_s);

    return passed;
}

// Simple enqueu and deque stack test
// Also confirms that a stack is full
int unitTest5(int status)
{
    int passed = 0;
    neu_stack *test_s = create_stack(1);
    stack_enqueue(test_s, 1);
    if (1 == stack_full(test_s))
    {
        passed = 1;
    }
    else
    {
        free_stack(test_s);
        return 0;
    }
    stack_dequeue(test_s);
    if (0 == stack_full(test_s))
    {
        passed = 1;
    }
    else
    {
        passed = 0;
    }
    free_stack(test_s);
    return passed;
}

// One test for create_stack function to make sure the function works as expected.
// Here we make the capacity = 10.
int unitTest6(int status)
{
    int passed = 0;
    unsigned int cap1 = 10;
    neu_stack *test_s = create_stack(cap1);
    if (test_s != NULL && test_s->capacity == cap1 && test_s->count == 0 && test_s->head == NULL)
    {
        passed = 1;
    }
    else
    {
        passed = 0;
    }

    free_stack(test_s);
    return passed;
}

// Another test for create_stack function to make sure the function works as expected.
// Here we make the capacity = 5.
int unitTest7(int status)
{
    int passed = 0;
    unsigned int cap1 = 5;
    neu_stack *test_s = create_stack(cap1);
    if (test_s != NULL && test_s->capacity == cap1 && test_s->count == 0 && test_s->head == NULL)
    {
        passed = 1;
    }
    else
    {
        passed = 0;
    }
    free_stack(test_s);
    return passed;
}

// One test for stack_empty function to make sure the function works as expected.
// Here we test an empty stack.
int unitTest8(int status)
{
    int passed = 0;
    neu_stack *test_s = (neu_stack *)malloc(sizeof(neu_stack));
    test_s->count = 0;
    test_s->capacity = 10;
    test_s->head = NULL;
    if (stack_empty(test_s))
    {
        passed = 1;
    }
    free(test_s);
    return passed;
}

// Another test for stack_empty function to make sure the function works as expected.
// Here we test an non-empty stack.
int unitTest9(int status)
{
    int passed = 0;
    neu_stack *test_s = (neu_stack *)malloc(sizeof(neu_stack));
    node_t *test_n = (node_t *)malloc(sizeof(node_t));
    test_n->data = 10;
    test_n->next = NULL;
    test_s->count = 1;
    test_s->capacity = 10;
    test_s->head = test_n;
    if (!stack_empty(test_s))
    {
        passed = 1;
    }
    free(test_n);
    free(test_s);
    return passed;
}

// One test for stack_full function to make sure the function works as expected.
// Here we test a stack with count less than capacity.
int unitTest10(int status)
{
    int passed = 0;
    neu_stack *test_s = create_stack(12);
    test_s->count = 6;
    int test = stack_full(test_s);
    if (test == 0)
    {
        passed = 1;
    }
    free(test_s);
    return passed;
}

// Another test for stack_full function to make sure the function works as expected.
// Here we test a stack with count equal to capacity.
int unitTest11(int status)
{
    int passed = 0;
    neu_stack *test_s = create_stack(8);
    test_s->count = 8;
    int test = stack_full(test_s);
    if (test == 1)
    {
        passed = 1;
    }
    free_stack(test_s);
    return passed;
}

// One test for stack_enqueue function to make sure the function works as expected.
// Here we enqueue item into an empty stack.
int unitTest12(int status)
{
    int passed = 0;
    neu_stack *test_s = create_stack(MAX_DEPTH);
    int item = 30;
    int test = stack_enqueue(test_s, item);
    if (test == 0 && test_s->count == 1 && test_s->head->data == item)
    {
        passed = 1;
    }
    else
    {
        free_stack(test_s);
        passed = 0;
    }
    return passed;
}

// Another test for stack_enqueue function to make sure the function works as expected.
// Here we enqueue one item into a MAX_DEPTH - 1 stack.
int unitTest13(int status)
{
    int passed = 0;
    neu_stack *test_s = create_stack(MAX_DEPTH);
    int item = 32;
    for (int i = 0; i < MAX_DEPTH - 1; i++)
    {
        stack_enqueue(test_s, i);
    }
    int test = stack_enqueue(test_s, item);
    if (test == 0 && test_s->count == MAX_DEPTH)
    {
        passed = 1;
    }
    else
    {
        free_stack(test_s);
        passed = 0;
    }
    return passed;
}

// // One test for stack_size function to make sure the function works as expected.
// int unitTest13(int status)
// {
//     int passed = 0;

//     neu_stack myStack;
//     myStack.count = 3;
//     myStack.capacity = 10;
//     myStack.head = (node_t*)malloc(sizeof(node_t));

//     unsigned int size = stack_size(&myStack);
//     if (size == 3)
//     {
//         passed = 1;

//     }
//     else
//     {
//         passed = 0;
//     }
//     free(myStack.head);
//     return passed;
// }

// // One test for free_stack function to make sure the function works as expected.
// // Here we test a stack with capacity = 10.
// int unitTest15(int status)
// {
//     int passed = 0;
//     neu_stack *test_s = create_stack(10);
//     free_stack(test_s);
//     if (test_s == NULL)
//     {
//        passed = 1;
//     }
//     else
//     {
//         passed = 0;
//     }

//     return passed;
// }

// TODO: Add more tests here
// add your own, and uncomment the provided tests as
// things are implemented
int (*unitTests[])(int) = {
    unitTest1,
    unitTest2,
    unitTest3,
    unitTest4,
    unitTest5,
    unitTest6,
    unitTest7,
    unitTest8,
    unitTest9,
    unitTest10,
    unitTest11,
    unitTest12,
    unitTest13};

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main()
{
    unsigned int testsPassed = 0;
    // List of Unit Tests to test your data structure
    int counter = 0;
    while (unitTests[counter] != NULL)
    {
        printf("========unitTest %d========\n", counter);
        if (1 == unitTests[counter](1))
        {
            printf("passed test\n");
            testsPassed++;
        }
        else
        {
            printf("failed test, missing functionality, or incorrect test\n");
        }
        counter++;
    }

    printf("%d of %d tests passed\n", testsPassed, counter);

    return 0;
}