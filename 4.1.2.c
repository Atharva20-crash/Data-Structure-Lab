struct node {
    int data;
    struct node* next;
};

typedef struct node* NODE;

NODE createNode(int x) {
    
 NODE newNode;

    newNode = (NODE)malloc(sizeof(struct node));

    newNode->data = x;
    newNode->next = NULL;

    return newNode;  
    
    
    
}

NODE addNode(NODE first, int x) {
  NODE temp = first;
    NODE newNode = createNode(x);

    /* If list is empty */
    if (first == NULL)
    {
        return newNode;
    }

    /* Traverse till last node */
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    /* Link new node at end */
    temp->next = newNode;

    return first; 
    
    
    
    
}

NODE concatenate(NODE t1, NODE t2) {
   NODE temp = t1;

    /* If first list is empty */
    if (t1 == NULL)
        return t2;

    /* If second list is empty */
    if (t2 == NULL)
        return t1;

    /* Traverse till last node of first list */
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    /* Attach second list */
    temp->next = t2;

    return t1;
    
    
    
    
}

void displayList(NODE first) {
    //write your code here..
   NODE temp = first;

    while (temp != NULL)
    {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
    
    
    
}
