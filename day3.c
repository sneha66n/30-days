#include <stdio.h>
#include <stdlib.h>

int repeated_number(int arr[], int n_arr) {
    for (int i = 0; i < n_arr; i++) {
        for (int j = i + 1; j < n_arr; j++) { // start from i+1 (avoid i==j check)
            if (arr[i] == arr[j]) {
                return arr[i];
            }
        }
    }
    return -1; // in case no duplicate
}

int main() {
    int n = 4;           
    int n_arr = n + 1;
    int arr[] = {3, 1, 3, 4, 2};

    for (int i = 0; i < n_arr; i++) {
        if (arr[i] < 1 || arr[i] > n) {  // check valid range
            printf("%d indexed element with value %d is out of range [1,%d]\n", i, arr[i], n);
            exit(0);
        }
    }

    int repeated = repeated_number(arr, n_arr);
    printf("Repeated number = %d\n", repeated);
    return 0;
}
