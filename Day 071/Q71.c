/*Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int hash_table[MAX_SIZE];
int m; // Size of the hash table
int hash_function(int key) {
    return key % m;
}

int quadratic_probe(int key, int i) {
    return (hash_function(key) + i * i) % m;
}

void insert(int key) {
    int i = 0;
    int index;
    while (i < m) {
        index = quadratic_probe(key, i);
        if (hash_table[index] == -1) { // Empty slot found
            hash_table[index] = key;
            return;
        }
        i++;
    }
    printf("Hash table is full. Cannot insert key: %d\n", key);
}
int search(int key) {
    int i = 0;
    int index;
    while (i < m) {
        index = quadratic_probe(key, i);
        if (hash_table[index] == -1) { // Key not found
            return -1;
        }
        if (hash_table[index] == key) { // Key found
            return index;
        }
        i++;
    }
    return -1; // Key not found after probing
}
int main() {
    // Initialize hash table
    for (int i = 0; i < MAX_SIZE; i++) {
        hash_table[i] = -1; // -1 indicates an empty slot
    }

    printf("Enter the size of the hash table (m): ");
    scanf("%d", &m);

    int n, key;
    printf("Enter the number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char operation[10];
        printf("Enter operation (INSERT/SEARCH) and key: ");
        scanf("%s %d", operation, &key);

        if (strcmp(operation, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(operation, "SEARCH") == 0) {
            int result = search(key);
            if (result != -1) {
                printf("Key %d found at index %d\n", key, result);
            } else {
                printf("Key %d not found in the hash table.\n", key);
            }
        } else {
            printf("Invalid operation. Please enter INSERT or SEARCH.\n");
        }
    }

    return 0;
}
