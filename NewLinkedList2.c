#include<stdio.h>
#include<stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert at the beginning
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

// Function to insert at the end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));

    // Handle the empty list case
    if (head == NULL) {
        head = ptr;
        ptr->data = data;
        ptr->next = NULL;
        return head;
    }

    struct Node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }

    p->next = ptr;
    ptr->data = data;
    ptr->next = NULL;
    return head;
}

// Function to insert at a specific index
struct Node* InsertAtIndex(struct Node* head, int index, int data) {
    if (index < 0) {
        printf("Invalid index: Negative index is not allowed.\n");
        return head;
    }

    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));

    // Special case for inserting at the beginning
    if (index == 0) {
        ptr->data = data;
        ptr->next = head;
        head = ptr;
        return head;
    }

    struct Node* p = head;
    int i = 0;

    // Traverse the list to find the node before the desired index
    while (p != NULL && i < index - 1) {
        p = p->next;
        i++;
    }

    // Check if the index is out of bounds
    if (p == NULL) {
        printf("Invalid index: Index exceeds list size. Current list size is %d.\n", i);
        free(ptr);
        return head;
    }

    // Insert the new node at the valid index
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

// Function to delete the first node
struct Node* DeleteFirstNode(struct Node* head) {
    if (head == NULL) {
        printf("The linked list is empty. Nothing to delete.\n");
        return head;
    }

    struct Node* p = head;
    head = head->next;
    free(p);
    return head;
}

// Function to delete a node at a specific index
struct Node* DeleteAtIndex(struct Node* head, int index) {
    if (head == NULL) {
        printf("The linked list is empty. Nothing to delete.\n");
        return head;
    }

    if (index == 0) {
        // Delete the first node
        struct Node* p = head;
        head = head->next;
        free(p);
        return head;
    }

    struct Node* p = head;
    struct Node* q = head->next;

    for (int i = 0; i < index - 1; i++) {
        if (q == NULL) {
            // Check if index is out of bounds
            printf("Invalid index: %d. Index exceeds list size.\n", index);
            return head;
        }
        p = p->next;
        q = q->next;
    }

    // Remove the node at the given index
    p->next = q->next;
    free(q);

    return head;
}

// Function to delete the last node
struct Node* DeleteAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("The linked list is empty. Nothing to delete.\n");
        return head;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* p = head;
    struct Node* q = head->next;

    while (q->next != NULL) {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
    return head;
}

// Function to print the list
void printList(struct Node* head) {
    struct Node* p = head;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value, index;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at index\n");
        printf("4. Delete first node\n");
        printf("5. Delete at index\n");
        printf("6. Delete last node\n");
        printf("7. Display linked list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;
            case 3:
                printf("Enter index to insert: ");
                scanf("%d", &index);
                printf("Enter value to insert at index: ");
                scanf("%d", &value);
                head = InsertAtIndex(head, index, value);
                break;
            case 4:
                head = DeleteFirstNode(head);
                break;
            case 5:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                head = DeleteAtIndex(head, index);
                break;
            case 6:
                head = DeleteAtEnd(head);
                break;
            case 7:
                printf("Linked List: ");
                printList(head);
                break;
            case 8:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
