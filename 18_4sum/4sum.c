#include <stdio.h>
#include <stdlib.h>

int prev_index(int * nums, int n, int i) {
    int key = i;
    for (; i >= 0; i--) {
        if (nums[i] != nums[key]) return i;
    }
    return 0;
}

int next_index(int * nums, int n, int i) {
    int key = i;
    for (; i < n; i++) {
        if (nums[i] != nums[key]) return i;
    }

    return n - 1;
}

void swap(int * nums, int a, int b) {
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}

void sort(int * nums, int l, int r) {
    if (l >= r) return;

    swap(nums, l, (l + r) / 2);
    int m = l;

    for(int i = l + 1; i <= r; i++) {
        if (nums[i] < nums[l]) swap(nums, ++m, i);
    }

    swap(nums, m, l);
    sort(nums, l, m - 1);
    sort(nums, m + 1, r);
}


/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    sort(nums, 0, numsSize - 1);

    int ** ret = (int **) malloc(1000 * sizeof(int *));
    for (int i = 0; i < numsSize - 3; i = next_index(nums, numsSize, i)) {
        int sum3 = target - nums[i];
        for (int j = i + 1; j < numsSize - 2; j = next_index(nums, numsSize, j)) {
            int sum2 = sum3 - nums[j];
            int l = j + 1, r = numsSize - 1;

            while (l < r) {
                int tmp = nums[l] + nums[r];
                if (tmp == sum2) {
                    int * one_ret = (int *) malloc(4 * sizeof(int));
                    one_ret[0] = nums[i];
                    one_ret[1] = nums[j];
                    one_ret[2] = nums[l];
                    one_ret[3] = nums[r];

                    ret[(*returnSize)++] = one_ret;
                    l = next_index(nums, numsSize, l);
                    r = prev_index(nums, numsSize, r);
                } else if (tmp < sum2) {
                    l = next_index(nums, numsSize, l);
                } else {
                    r = prev_index(nums, numsSize, r);
                }
            }
        }
    }

    return ret;
}

int main() {
    int nums[] = {-3, -1, 0, 2, 4, 5};
    //int nums[] = {1, 0, -1, 0, -2, 2};
    int numsSize = 6;

    int returnSize = 0;
    int ** ret = fourSum(nums, numsSize, 2, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d, %d, %d, %d\n", ret[i][0], ret[i][1], ret[i][2], ret[i][3]);
    }

    return 0;
}
