#include <stdio.h>
#include <stdlib.h>
#include <malloc/_malloc.h>
#include <stdbool.h>

struct TList {
    int data;
    struct TList *next;
};

struct TList* createElement(int data) {
    struct TList* newElement = (struct TList*)malloc(sizeof(struct TList));
    if (newElement == NULL) {
        printf("Ошибка: Не удалось выделить память для нового узла\n");
        exit(1);
    }
    newElement->data = data;
    newElement->next = NULL;
    return newElement;
}

struct Stack {
    struct TList* top;
};

struct Stack* createStack() {
    struct Stack* newStack = (struct Stack*)malloc(sizeof(struct Stack));
    if (newStack == NULL) {
        printf("Ошибка: Не удалось выделить память для новой очереди\n");
        exit(1);
    }

    newStack->top = NULL;
    return newStack;
}

void appendInStack(struct Stack* stack, int data) {
    struct TList* newElement = createElement(data);

    newElement->next = stack->top;
    stack->top = newElement;
}

int removeElementStack(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Очередь пуста\n");
        return -1;
    }

    struct TList* temp = stack->top;

    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

struct Stack* intersectionStacks(struct Stack* firstStack, struct Stack* secondStack) {
    struct Stack* newStackList = createStack();

    struct TList* firstStackList = firstStack->top;
    struct TList* secondStackList = NULL;
    bool flagFirst = true;
    bool flagSecond = true;
    while (flagFirst) {
        if (firstStackList == NULL) {
            flagFirst = false;
        } else {
            secondStackList = secondStack->top;
            while (flagSecond) {
                if (secondStackList == NULL) {
                    flagSecond = false;
                } else {
                    if (firstStackList->data == secondStackList->data) {
                        appendInStack(newStackList, firstStackList->data);
                    }
                    secondStackList = secondStackList->next;
                }
            }
            firstStackList = firstStackList->next;
            flagSecond = true;
        }
    }

    return newStackList;
}


void tupleStack(struct Stack* inputStack, struct Stack* checkStack) {
    struct TList *ListInputStack = inputStack->top;
    struct TList *ListCheckStack = checkStack->top;
    bool flag;

    while (ListCheckStack != NULL) {
        flag = true;
        while (ListInputStack != NULL) {
            if (ListCheckStack->data != ListInputStack->data) {
                ListInputStack = ListInputStack->next;
            } else {
                flag = false;
                ListInputStack = NULL;
            }
        }

        if (flag) {
            appendInStack(inputStack, ListCheckStack->data);
        }

        ListCheckStack = ListCheckStack->next;
        ListInputStack = inputStack->top;
    }
}

struct Stack* tupleStacks(struct Stack* firstStack, struct Stack* secondStack) {
    struct Stack* newStackList = createStack();

    tupleStack(newStackList, firstStack);
    tupleStack(newStackList, secondStack);
    return newStackList;
}

void printStack(struct Stack* stack) {
    struct TList* temp = stack->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Stack* firstStackList = createStack();
    struct Stack* secondStackList = createStack();

    appendInStack(firstStackList, 1);
    appendInStack(firstStackList, 2);
    appendInStack(firstStackList, 3);
    appendInStack(firstStackList, 4);
    appendInStack(firstStackList, 5);

    appendInStack(secondStackList, 2);
    appendInStack(secondStackList, 3);
    appendInStack(secondStackList, 5);
    appendInStack(secondStackList, 6);
    appendInStack(secondStackList, 6);

    // removeElementStack(firstStackList);

    struct Stack* intersectionStacksList = intersectionStacks(firstStackList, secondStackList);
    struct Stack* tupleStacksList = tupleStacks(firstStackList, secondStackList);
    printf("First Stack: ");
    printStack(firstStackList);
    printf("Second Stack: ");
    printStack(secondStackList);
    printStack(intersectionStacksList);
    printStack(tupleStacksList);


    return 0;
}