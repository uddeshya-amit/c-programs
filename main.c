#include <stdio.h>
#define MAX 10
void maxHeapify(int arr[], int i, int n);
int main()
{
    int arr[] = {2, 3, 6, 1, 4, 5, 7};
    maxHeapify(arr, 2, 7);
    return 0;
}

// // 1, 2, 4, 5, 8, 3, 9

//         1
//     2       4
// 5       8 3

// 0 => left = 1 and right = 2
// 1 => left = 3 and right = 4
// 2 => left = 5 and right = 6

// left child = 2 * i + 1
// right child = 2 * i + 2


// last-internal-node = n/2 - 1; //n = number of nodes

void maxHeapify(int arr[], int i, int n) {
    if (i == -1) {
        i = n/2 - 1;
    }

    int lc = 2 * i + 1;
    int rc = 2 * i + 2;
    int largest = i;
    if (arr[lc] >= arr[largest] && arr[lc] >= arr[rc]) {
        largest = lc;
    } else if (arr[rc] >= arr[largest] && arr[rc] >= arr[lc]) {
        largest = rc;
    }

    int temp = arr[largest];
    arr[largest] = arr[i];
    arr[i] = temp;
    i = i - 1;
    for (int j = 0; j < n; j++) {
        printf(" %d", arr[j]);
    }

    printf("\n");
    maxHeapify(arr, i, n);
    
}