#include <stdio.h>

void min_heap(int *a, int m, int n) {
    int j, temp;
    temp = a[m];
    j = 2 * m;
    while (j <= n) {
        if (j < n && a[j + 1] < a[j]) {
            j = j + 1;
        }
        if (temp < a[j]) {
            break;
        } else if (temp >= a[j]) {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = temp;
    return;
}

void build_minheap(int *a, int n) {
    int k;
    for (k = n / 2; k >= 1; k--) {
        min_heap(a, k, n);
    }
}

int main() {
    int n, i;
    scanf("%d", &n);
    int a[n + 1];  // Adjusted array size to start from index 1
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    int element;
    scanf("%d", &element);
    
    if (element < 1 || element > n) {
        printf("Invalid entry\n");
        return 0;
    }

    build_minheap(a, n);
    
    printf("Min heap is: ");
    for (i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    
    printf("\nKth element in min heap is %d\n", a[element]);

    return 0;
}

