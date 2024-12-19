#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "sort_algorithms.h"

int main() {
    srand(time(NULL));
    int sizes[] = {1000, 10000, 100000};
    
    printf("排序算法性能比较：\n");
    printf("----------------------------------------\n");
    
    for (int i = 0; i < sizeof(sizes)/sizeof(sizes[0]); i++) {
        int n = sizes[i];
        printf("\n数组大小: %d\n", n);
        printf("----------------------------------------\n");
        int *original = (int*)malloc(n * sizeof(int));
        int *arr = (int*)malloc(n * sizeof(int));

        generateRandomArray(original, n);

        copyArray(original, arr, n);
        testSortingAlgorithm("冒泡排序", bubbleSort, arr, n);

        copyArray(original, arr, n);
        testSortingAlgorithm("快速排序", quickSortWrapper, arr, n);

        copyArray(original, arr, n);
        testSortingAlgorithm("Shell排序", shellSort, arr, n);

        copyArray(original, arr, n);
        testSortingAlgorithm("堆排序  ", heapSort, arr, n);

        free(original);
        free(arr);
    }
    
    printf("\n排序算法复杂度分析：\n");
    printf("----------------------------------------\n");
    printf("冒泡排序 - 时间复杂度：O(n?)     空间复杂度：O(1)\n");
    printf("快速排序 - 时间复杂度：O(nlogn)  空间复杂度：O(logn)\n");
    printf("Shell排序 - 时间复杂度：O(n^1.3) 空间复杂度：O(1)\n");
    printf("堆排序   - 时间复杂度：O(nlogn)  空间复杂度：O(1)\n");
    
    return 0;
}