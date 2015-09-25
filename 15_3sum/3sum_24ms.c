#include <stdio.h>
#include <stdlib.h>
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int next_index(int* nums, int i, int n) {
    int j = i;
    for (; j < n; j++) {
        if (nums[j] != nums[i]) break;
    }
    return j;
}

int prev_index(int* nums, int i, int n) {
    int j = i;
    for (; j >= 0; j--) {
        if (nums[j] != nums[i]) break;
    }
    return j;
}

void swap(int * x, int a, int b) {
    int tmp = x[a];
    x[a] = x[b];
    x[b] = tmp;
}

void sort(int * x, int l, int r) {
    if (l >= r) return;

    swap(x, l, (l + r) / 2);
    int m = l;

    for (int i = l + 1; i <= r; i++) {
        if (x[i] < x[l]) {
            swap(x, ++m, i);
        }
    }

    swap(x, l, m);
    sort(x, l, m - 1);
    sort(x, m + 1, r);
}

int** threeSum(int* nums, int numsSize, int* returnSize) {
    sort(nums, 0, numsSize - 1);

    *returnSize = 0;
    int** ret = (int **) malloc(1000);

    for (int i = 0; i < numsSize;) {
        int l = i + 1, r = numsSize - 1;
        int sum = -nums[i];
        
        while (l < r) {
            if (nums[l] + nums[r] == sum) {
                int * triple = (int *) malloc(3);
                triple[0] = nums[i];
                triple[1] = nums[l];
                triple[2] = nums[r];
                ret[*returnSize] = triple;

                l = next_index(nums, l, numsSize);
                r = prev_index(nums, r, numsSize);
                *returnSize += 1;
            } else if (nums[l] + nums[r] < sum) {
                l++;
            } else {
                r--;
            }
        }

        i = next_index(nums, i, numsSize);
    }
    
    return ret;
}
