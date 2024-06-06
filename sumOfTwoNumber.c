#include <stdio.h>
#include <omp.h>

int has_sum(int arr[], int n, int target) {
    int flag = 0;
    #pragma omp parallel for shared(arr, n, target, flag)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                flag = 1; // true
                #pragma omp atomic
                {
                    break;
                }
            }
        }
    }
    return flag;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    if (has_sum(arr, n, target)) {
        printf("Sum found\n");
    } else {
        printf("Sum not found\n");
    }
    return 0;
}

