#include <stdio.h>

int lowerBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, x;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array (sorted in non-decreasing order): ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value to find the lower bound for: ");
    scanf("%d", &x);

    int result = lowerBound(arr, n, x);
    if(result < n) {
        printf("The lower bound of %d is at index: %d\n", x, result);
    } else {
        printf("No element is greater than or equal to %d\n", x);
    }

    return 0;
}
