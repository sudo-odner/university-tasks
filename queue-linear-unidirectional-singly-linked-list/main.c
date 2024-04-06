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

struct Queue {
    struct TList* front;
    struct TList* rear;
};

struct Queue* createQueue() {
    struct Queue* newQueue = (struct Queue*)malloc(sizeof(struct Queue));
    if (newQueue == NULL) {
        printf("Ошибка: Не удалось выделить память для новой очереди\n");
        exit(1);
    }

    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

void appendInQueue(struct Queue* q, int data) {
    struct TList* newElement = createElement(data);

    if (q->rear == NULL) {
        q->front = q->rear = newElement;
    } else {
        q->rear->next = newElement;
        q->rear = newElement;
    }
}

int removeElementQueue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Очередь пуста\n");
        return -1;
    }

    struct TList* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return data;
}

int minElementQueue(struct Queue* q) {
    int minElement = 999999999;
    struct TList* temp = q->front;
    while (temp != NULL) {
        if (temp->data < minElement) {
            minElement = temp->data;
        }
        temp = temp->next;
    }

    return minElement;
}

void printQueue(struct Queue* q) {
    struct TList* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue* queueList = createQueue();

    appendInQueue(queueList, 1);
    appendInQueue(queueList, 2);
    appendInQueue(queueList, 3);
    appendInQueue(queueList, 1);
//     removeElementQueue(queueList);
    printf("%d \n", minElementQueue(queueList));

    printQueue(queueList);

    return 0;
}