#include <stdio.h>
#include <stdlib.h>

// Structure for hash map entry
typedef struct Node {
    int key;
    int freq;
    struct Node* next;
} Node;

#define HASH_SIZE 10001

// Simple hash function
int hash(int key) {
    return abs(key) % HASH_SIZE;
}

// Insert or update frequency
void insert(Node** map, int key) {
    int h = hash(key);
    Node* temp = map[h];

    while (temp) {
        if (temp->key == key) {
            temp->freq++;
            return;
        }
        temp = temp->next;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->freq = 1;
    newNode->next = map[h];
    map[h] = newNode;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    Node* map[HASH_SIZE] = {NULL};

    // Step 1: Build frequency map
    for (int i = 0; i < numsSize; i++) {
        insert(map, nums[i]);
    }

    // Step 2: Create bucket array
    Node** buckets = (Node**)calloc(numsSize + 1, sizeof(Node*));

    for (int i = 0; i < HASH_SIZE; i++) {
        Node* temp = map[i];
        while (temp) {
            Node* next = temp->next;
            temp->next = buckets[temp->freq];
            buckets[temp->freq] = temp;
            temp = next;
        }
    }

    // Step 3: Collect top K
    int* result = (int*)malloc(sizeof(int) * k);
    int count = 0;

    for (int i = numsSize; i >= 0 && count < k; i--) {
        Node* temp = buckets[i];
        while (temp && count < k) {
            result[count++] = temp->key;
            temp = temp->next;
        }
    }

    *returnSize = k;
    return result;
}