#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "sort_algorithms.h"

int main() {
    srand(time(NULL));
    int sizes[] = {1000, 10000, 100000};
    
    printf("�����㷨���ܱȽϣ�\n");
    printf("----------------------------------------\n");
    
    for (int i = 0; i < sizeof(sizes)/sizeof(sizes[0]); i++) {
        int n = sizes[i];
        printf("\n�����С: %d\n", n);
        printf("----------------------------------------\n");
        int *original = (int*)malloc(n * sizeof(int));
        int *arr = (int*)malloc(n * sizeof(int));

        generateRandomArray(original, n);

        copyArray(original, arr, n);
        testSortingAlgorithm("ð������", bubbleSort, arr, n);

        copyArray(original, arr, n);
        testSortingAlgorithm("��������", quickSortWrapper, arr, n);

        copyArray(original, arr, n);
        testSortingAlgorithm("Shell����", shellSort, arr, n);

        copyArray(original, arr, n);
        testSortingAlgorithm("������  ", heapSort, arr, n);

        free(original);
        free(arr);
    }
    
    printf("\n�����㷨���Ӷȷ�����\n");
    printf("----------------------------------------\n");
    printf("ð������ - ʱ�临�Ӷȣ�O(n?)     �ռ临�Ӷȣ�O(1)\n");
    printf("�������� - ʱ�临�Ӷȣ�O(nlogn)  �ռ临�Ӷȣ�O(logn)\n");
    printf("Shell���� - ʱ�临�Ӷȣ�O(n^1.3) �ռ临�Ӷȣ�O(1)\n");
    printf("������   - ʱ�临�Ӷȣ�O(nlogn)  �ռ临�Ӷȣ�O(1)\n");
    
    return 0;
}