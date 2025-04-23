#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

double calculate_mean(int arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    return sum / n;
}

double calculate_median(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);
    if (n % 2 == 0)
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    else
        return arr[n / 2];
}

void calculate_mode(int arr[], int n) {
    int max_count = 0;
    printf("Mode: ");
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++)
            if (arr[j] == arr[i]) count++;
        if (count > max_count) max_count = count;
    }

    int printed[201] = {0};
    for (int i = 0; i < n; i++) {
        int count = 0;
        if (printed[arr[i] + 100]) continue;
        for (int j = 0; j < n; j++)
            if (arr[j] == arr[i]) count++;
        if (count == max_count) {
            printf("%d ", arr[i]);
            printed[arr[i] + 100] = 1;
        }
    }
    printf("\n");
}

int main() {
    int arr[100], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Mean: %.2f\n", calculate_mean(arr, n));
    printf("Median: %.2f\n", calculate_median(arr, n));
    calculate_mode(arr, n);

    return 0;
}
