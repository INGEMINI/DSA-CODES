#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} node;

// Function to create and insert a new node at the beginning of the linked list
node* createnode(node* head) {
    int data;
    node* newnode = (node*)malloc(sizeof(node));

    if (newnode == NULL) {  // Check for malloc failure
        printf("Memory allocation failed!\n");
        return head;  // Return the current head if allocation fails
    }

    printf("Enter value: ");
    scanf("%d", &data);

    newnode->data = data;
    newnode->next = head;  // Insert the new node at the beginning
    return newnode;        // Return the new head of the list
}

// Function to delete nodes with even values from the linked list
node* deleteEvenNodes(node* head) {
    while (head != NULL && head->data % 2 == 0) {
        // If the head itself is even, move the head to the next node
        node* temp = head;
        head = head->next;  // Update head to point to the next node
        free(temp);         // Free memory of the deleted node
    }

    node* current = head;  // Set current pointer to the new head
    while (current != NULL && current->next != NULL) {
        if (current->next->data % 2 == 0) {  // Check if the next node is even
            node* temp = current->next;  // Store the node to be deleted
            current->next = temp->next;   // Skip the even node
            free(temp);                    // Free memory of the deleted node
        } else {
            current = current->next;  // Move to the next node if not deleting
        }
    }

    return head;  // Return the updated head of the list
}

// Function to print the entire linked list
void printll(node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked list: ");
    node* current = head;  // Use a single pointer to traverse the list
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;  // Move to the next node
    }
    printf("NULL\n");
}

int main() {
    int num = 1;
    node* head = NULL;  // Head pointer to the linked list

    // Create the linked list
    while (num) {
        head = createnode(head);  // Insert new node and update head
        printf("Want to insert more? Type 1 for yes, 0 for no: ");
        scanf("%d", &num);
    }

    // Display the entire linked list before deletion
    printll(head);

    // Delete nodes with even values
    head = deleteEvenNodes(head);

    // Display the linked list after deletion
    printll(head);

    return 0;
}
