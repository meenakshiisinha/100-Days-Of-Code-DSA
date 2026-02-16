/*Problem: Given an array of integers, count the frequency of each distinct element and print the result.

Input:
- First line: integer n (size of array)
- Second line: n integers

Output:
- Print each element followed by its frequency in the format element:count

Example:
Input:
5
1 2 2 3 1

Output:
1:2 2:2 3:1*/
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    scanf("%d", &n);
    
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int frequency[100] = {0}; 
    for (int i = 0; i < n; i++) {
        frequency[arr[i]]++;
    }

    for (int i = 0; i < 100; i++) {
        if (frequency[i] > 0) {
            printf("%d:%d ", i, frequency[i]);
        }
    }
    
    free(arr);
    return 0;
}