#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    long long key;
    int value;
    struct Node* next;
} Node;

typedef struct HashMap {
    Node** buckets;
    int size;
} HashMap;

unsigned int hash(long long key, int size) {
    return (unsigned int)(key % size + size) % size;
}

HashMap* createHashMap(int size) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->size = size;
    map->buckets = (Node**)calloc(size, sizeof(Node*));
    return map;
}

void insert(HashMap* map, long long key, int value) {
    unsigned int index = hash(key, map->size);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = map->buckets[index];
    map->buckets[index] = newNode;
}

Node* find(HashMap* map, long long key) {
    unsigned int index = hash(key, map->size);
    Node* current = map->buckets[index];
    while (current != NULL) {
        if (current->key == key) return current;
        current = current->next;
    }
    return NULL;
}

void freeHashMap(HashMap* map) {
    for (int i = 0; i < map->size; i++) {
        Node* current = map->buckets[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(map->buckets);
    free(map);
}

typedef struct {
    int start;
    int end;
} Subarray;

Subarray* subarrayzsum(const int* arr, int size, int* count) {
    *count = 0;
    int capacity = 10;
    Subarray* result = (Subarray*)malloc(capacity * sizeof(Subarray));
    HashMap* prefixMap = createHashMap(size * 2);

    long long prefixSum = 0;
    insert(prefixMap, 0, -1);

    for (int i = 0; i < size; i++) {
        prefixSum += arr[i];
        Node* current = find(prefixMap, prefixSum);
        while (current != NULL) {
            if (*count >= capacity) {
                capacity *= 2;
                result = (Subarray*)realloc(result, capacity * sizeof(Subarray));
            }
            result[*count].start = current->value + 1;
            result[*count].end = i;
            (*count)++;
            current = current->next;
        }
        insert(prefixMap, prefixSum, i);
    }
    freeHashMap(prefixMap);
    return result;
}

void testcase(const int* arr, int size) {
    int count = 0;
    Subarray* subarrays = subarrayzsum(arr, size, &count);

    printf("Input: [ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");

    printf("Subarrays with Zero Sum: ");
    if (count == 0) {
        printf("[]\n");
    } else {
        for (int i = 0; i < count; i++) {
            printf("(%d, %d) ", subarrays[i].start, subarrays[i].end);
        }
        printf("\n");
    }
    printf("-----------------------------------\n");

    free(subarrays);
}

int main() {
    int arr1[] = {1, 2, -3, 3, -1, 2};
    testcase(arr1, 6);

    int arr2[] = {4, -1, -3, 1, 2, -1};
    testcase(arr2, 6);

    int arr3[] = {1, 2, 3, 4};
    testcase(arr3, 4);

    int arr4[] = {0, 0, 0};
    testcase(arr4, 3);

    int arr5[] = {-3, 1, 2, -3, 4, 0};
    testcase(arr5, 6);

    int bigArr[6 * 5];
    for (int i = 0; i < 5; i++) {
        int temp[] = {1, -1, 2, -2, 3, -3};
        for (int j = 0; j < 6; j++) {
            bigArr[i * 6 + j] = temp[j];
        }
    }
    testcase(bigArr, 30);

    return 0;
}
