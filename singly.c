#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; temp && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp) {
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        printf("Position out of bounds.\n");
    }
}


void deleteatbegin(struct Node** head){
    struct Node* temp = *head;
    if(*head == NULL){
        printf("list is empty.");
        return;
    }
    *head = temp->next;
    free(temp);
}

void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (position == 1) {
        struct Node* temp = *head;
        *head = temp->next;
        free(temp);
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; temp && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp && temp->next) {
        struct Node* toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
    } else {
        printf("Position out of bounds.\n");
    }
}


int main() {
    struct Node* head = NULL;
    int choice, data, key, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Delete node\n");
        printf("3. insert at pos \n");
        printf("4. Delete at pos \n");
        printf("5. Print list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                deleteatbegin(&head);
                break;
            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 5:
                printf("Linked List: ");
                printList(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}