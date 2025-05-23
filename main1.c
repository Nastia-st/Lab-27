#include <stdio.h>
#define SIZE 12

typedef struct {
    int data[SIZE];
    int top;
} Stack;
void init(Stack *s) {
    s->top = -1;
}
int isFull(Stack *s) {
    return s->top == SIZE - 1;
}
int isEmpty(Stack *s) {
    return s->top == -1;
}
void push(Stack *s, int value) {
    if (!isFull(s)) {
        s->data[++s->top] = value;
    }
}
void printStack(Stack *s, const char *name) {
    printf("%s: ", name);
    if (isEmpty(s)) {
        printf("порожній\n");
        return;
    }
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main() {
    system("chcp 65001");
    Stack positiveStack, negativeStack;
    init(&positiveStack);
    init(&negativeStack);
    int num;
    printf("Введіть 12 цілих чисел:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Число %d: ", i + 1);
        scanf("%d", &num);
        if (num > 0) {
            push(&positiveStack, num);
        } else if (num < 0) {
            push(&negativeStack, num);
        }
    }
    printf("\nРезультат:\n");
    printStack(&positiveStack, "Додатні числа (стек)");
    printStack(&negativeStack, "Від’ємні числа (стек)");
    return 0;
}