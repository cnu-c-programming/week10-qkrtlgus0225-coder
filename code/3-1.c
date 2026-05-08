#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    int score;
    struct Node* next;
} Node;

Node* head = NULL;

void add(char* name, int score) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void deleteNode(char* name) {
    Node* current = head;
    Node* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                head = current->next; 
            } else {
                prev->next = current->next; 
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void printList() {
    Node* current = head;
    while (current != NULL) {
        printf("%s %d\n", current->name, current->score);
        current = current->next;
    }
}

void quit() {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp); 
    }
    head = NULL;
}

int main() {
    char command[20];
    char name[50];
    int score;

    while (1) {
        scanf("%s", command);
        
        if (strcmp(command, "add") == 0) {
            scanf("%s %d", name, &score);
            add(name, score);
        } else if (strcmp(command, "delete") == 0) {
            scanf("%s", name);
            deleteNode(name);
        } else if (strcmp(command, "print") == 0) {
            printList();
        } else if (strcmp(command, "quit") == 0) {
            quit();
            break;
        }
    }
    
    return 0;
}
