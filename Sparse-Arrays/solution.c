#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* string;
    int count;
    struct Node* next;
} Node;

unsigned long hashFunction(char* str, int size) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash % size;
}

int* matchingStrings(int stringList_count, char** stringList,
                     int queries_count, char** queries,
                     int* result_count) {

    int tableSize = stringList_count * 2 + 1;

    Node** hashTable = calloc(tableSize, sizeof(Node*));

    for (int i = 0; i < stringList_count; i++) {
        unsigned long index = hashFunction(stringList[i], tableSize);

        Node* current = hashTable[index];

        while (current != NULL) {
            if (strcmp(current->string, stringList[i]) == 0) {
                current->count++;
                break;
            }

            current = current->next;
        }

        if (current == NULL) {
            Node* newNode = malloc(sizeof(Node));

            newNode->string = stringList[i];
            newNode->count = 1;
            newNode->next = hashTable[index];

            hashTable[index] = newNode;
        }
    }

    int* result = malloc(queries_count * sizeof(int));
    *result_count = queries_count;

    for (int i = 0; i < queries_count; i++) {
        unsigned long index = hashFunction(queries[i], tableSize);

        Node* current = hashTable[index];

        result[i] = 0;

        while (current != NULL) {
            if (strcmp(current->string, queries[i]) == 0) {
                result[i] = current->count;
                break;
            }

            current = current->next;
        }
    }

    for (int i = 0; i < tableSize; i++) {
        Node* current = hashTable[i];

        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    free(hashTable);

    return result;
}