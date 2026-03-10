#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node *NODE;

// Create a new node with given data
NODE createNodeInCLL(int data) {
    NODE temp = (NODE) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Create CLL with n nodes
NODE createCLL(  int n   ) {
	if (n <= 0)
        return NULL;

    NODE head = NULL, last = NULL;
    int value;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        NODE newNode = createNodeInCLL(value);

        if (head == NULL) {
            head = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }
    last->next = head;  // Make circular
    return head;
// write your code here...


}

// Traverse CLL
void traverseListInCLL(  NODE head    ) {
  if (head == NULL)
        return;

    NODE temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Count nodes
int countNodes(NODE head) {
    if (head == NULL)
        return 0;

    int count = 0;
    NODE temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
// write your code here...


}

// Insert at given position in CLL
NODE insertAtPositionInCLL(   NODE head, int pos, int data   ) {
	int n = countNodes(head);

    if (pos < 1 || pos > n + 1) {
        printf("Position not found\n");
        return head;
    }

    NODE newNode = createNodeInCLL(data);

    if (pos == 1) {
        if (head == NULL) {
            newNode->next = newNode;
            return newNode;
        }

        NODE temp = head;
        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
        return head;
    }

    NODE temp = head;
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;

    return head; 
//write your code here..


	
}

// Delete node at given position in CLL
NODE deleteAtPositionInCLL(  NODE head, int pos    ) {
	 int n = countNodes(head);

    if (pos < 1 || pos > n) {
        printf("Position not found\n");
        return head;
    }

    if (pos == 1) {
        if (n == 1) {
            printf("Deleted element: %d\n", head->data);
            free(head);
            return NULL;
        }

        NODE temp = head;
        while (temp->next != head)
            temp = temp->next;

        NODE del = head;
        printf("Deleted element: %d\n", del->data);
        temp->next = head->next;
        head = head->next;
        free(del);
        return head;
    }

    NODE temp = head, prev = NULL;
    for (int i = 1; i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);

    return head;
	
	
}

// Reverse CLL
NODE reverseCLL(   NODE head   ) {
	 NODE prev = NULL, current = head, next = NULL;

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);

    head->next = prev;
    head = prev;

    return head;
//write your code here...


}

// Concatenate two CLLs
NODE concatCLL(   NODE first, NODE second       ) {
 if (first == NULL)
        return second;
    if (second == NULL)
        return first;

    NODE temp1 = first;
    while (temp1->next != first)
        temp1 = temp1->next;

    NODE temp2 = second;
    while (temp2->next != second)
        temp2 = temp2->next;

    temp1->next = second;
    temp2->next = first;

    return first;
//write your code here..



}

int main() {
    NODE first = NULL, second = NULL;
    int x, pos, op, n;

    while (1) {
        printf("1.Create 2.Insert 3.Delete 4.Display 5.Reverse 6.Concat 7.Exit\n");
        printf("choice: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("How many nodes? ");
                scanf("%d", &n);
                first = createCLL(n);
                break;
            case 2:
                printf("Position: ");
                scanf("%d", &pos);
                if (pos <= 0) {
                    printf("Position not found\n");
                } else {
                    printf("Element: ");
                    scanf("%d", &x);
                    first = insertAtPositionInCLL(first, pos, x);
                }
                break;
            case 3:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Position: ");
                    scanf("%d", &pos);
                    first = deleteAtPositionInCLL(first, pos);
                }
                break;
            case 4:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Elements in CLL are: ");
                    traverseListInCLL(first);
                }
                break;
            case 5:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    first = reverseCLL(first);
                    printf("CLL reversed\n");
                    traverseListInCLL(first);   // <-- display reversed list
                }
                break;
            case 6:
                printf("Creating second CLL to concatenate...\n");
                printf("How many nodes in second CLL? ");
                scanf("%d", &n);
                second = createCLL(n);
                first = concatCLL(first, second);
                printf("Concatenated CLL:\n");
                traverseListInCLL(first);
                break;
            case 7:
                exit(0);
        }
    }
}
