#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int kthSmallest(int arr[], int n, int k) {
    if (k < 1 || k > n) {
        printf("Invalid value of K. K should be between 1 and %d.\n", n);
        return -1;
    }
    
    selectionSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return arr[k - 1];
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int K = 2;
    int result = kthSmallest(arr, arr_size, K);
    if (result != -1)
        printf("The %dth smallest element is: %d\n", K, result);
    return 0;
}
