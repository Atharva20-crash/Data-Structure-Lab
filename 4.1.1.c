#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

/* Create a new node */
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Insert at given position */
void insertAtPosition(int data, int pos) {
    struct Node* newNode = createNode(data);

    if (pos < 0) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    if (pos == 0) {
        newNode->next = head;
        head = newNode;
        printf("Element %d inserted at position %d\n", data, pos);
        return;
    }

    struct Node* temp = head;
    int i = 0;

    while (temp != NULL && i < pos - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Element %d inserted at position %d\n", data, pos);
}

/* Delete at given position */
void deleteAtPosition(int pos) {
    if (head == NULL || pos < 0) {
        printf("Invalid position\n");
        return;
    }

    struct Node* temp = head;

    if (pos == 0) {
        head = temp->next;
        free(temp);
        printf("Element at position %d deleted\n", pos);
        return;
    }

    int i = 0;
    struct Node* prev = NULL;

    while (temp != NULL && i < pos) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Element at position %d deleted\n", pos);
}

/* Display list */
void displayList() {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Reverse only for display (do not modify original list) */
void displayReversed() {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    printf("Reversed List: ");
    struct Node* temp = prev;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    /* Restore original list */
    curr = prev;
    prev = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main() {
    int n;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        insertAtPosition(x, i);
    }

    int choice;
    while (1) {
        printf("Linked List Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Reverse\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int data, pos;
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter position to insert: ");
            scanf("%d", &pos);
            insertAtPosition(data, pos);
        }
        else if (choice == 2) {
            int pos;
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            deleteAtPosition(pos);
        }
        else if (choice == 3) {
            displayReversed();
        }
        else if (choice == 4) {
            displayList();
        }
        else if (choice == 5) {
            printf("Exiting program\n");
            break;
        }
    }

    return 0;
}
