// .c to walk the single geniric link list and printing it:w
#include "2_1_generic_linkList.h"




/* inserting node by node to single link list*/
void insertNode(struct Node** head_ref, void *new_data, size_t data_size)
{
    //allocate memory for node
    struct Node* new_node;

    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = malloc(data_size);
   
    new_node->next = (*head_ref);


    // Copy new_data to new_node memory allocated
    int i;
    for (i=0; i<data_size; i++)
    {
        *(char *)(new_node->data + i) = *(char *)(new_data + i);
    }

    // move the head ref ptr to new added node at the beginning
    (*head_ref) = new_node;

}


/* Walking the single link List */
void walkAndPrintList(struct Node *node, void (*fptr)(void *))
{
    while (node != NULL)
    {
       (*fptr)(node->data);
       node = node->next;
    }
}

// Fuction printing data integer
void printInteger(void *n)
{
   printf("%d \n", *(int *)n);

}

/* Driver program to test the above function */
int main()
{
    struct Node *start = NULL;

   
    // Create and print an int single linked List
    unsigned size = sizeof(int);
    int array[] = {10, 20, 30, 40, 50}, i;

    printf("Create and printing integer single linked list: \n\n");
    for (i=4; i>=0; i--)
    {
        insertNode(&start, &array[i], size);
    }
    walkAndPrintList(start, printInteger);
    
        
    return 0;
}
