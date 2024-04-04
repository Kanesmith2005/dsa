#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 10

void push(int element);
void pop();
void display();

int stack[MAX_SIZE];
int top = -1;

int main() {
    int choice, element;
    do {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        if(scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                if(scanf("%d", &element) != 1) {
                    printf("Invalid input. Please enter a number.\n");
                    while (getchar() != '\n');
                    continue;
                }
                push(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);
    return 0;
}

void push(int element) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow. Cannot push element.\n");
    } else {
        top++;
        stack[top] = element;
        printf("%d pushed to the stack.\n", element);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack underflow. Cannot pop element.\n");
    } else {
        printf("%d popped from the stack.\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Elements in the stack are:\n");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
