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

void append(struct TList** head, int data) {
    struct TList* newElement = createElement(data);
    if (*head == NULL) {
        *head = newElement;
    } else {
        struct TList* last = *head;
        while (last->next != NULL)
            last = last->next;

        last->next = newElement;
    }
}

void printList(struct TList* list) {
    while (list != NULL) {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}

int lenTList(struct TList* list) {
    int count = 0;
    while (list != NULL) {
        count++;
        list = list->next;
    }

    return count;
}

bool comparison(struct TList* first, struct TList* second) {
    if (lenTList(first) != lenTList(second)) {
        return false;
    } else {
        while (first != NULL) {
            if (first->data != second->data) {
                return false;
            }
            first = first->next;
            second = second->next;
        }
    }
    return true;
}

int main() {
    struct TList* headFirst = NULL;

    append(&headFirst, 1);
    append(&headFirst, 2);
    append(&headFirst, 3);
    append(&headFirst, 4);

    struct TList* headSecond = NULL;
    append(&headSecond, 1);
    append(&headSecond, 2);
    append(&headSecond, 3);
    append(&headSecond, 4);

    printf("%d", comparison(headFirst, headSecond));

//    printf("Список: ");
//    printList(head);
//    comparison

    return 0;
}