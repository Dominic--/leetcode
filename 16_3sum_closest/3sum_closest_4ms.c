#include <stdlib.h>
#include <stdio.h>

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
        if (x[i] < x[l]) swap(x, ++m, i);
    }

    swap(x, m, l);
    sort(x, l, m - 1);
    sort(x, m + 1, r);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    sort(nums, 0, numsSize - 1);

    int dist = 0;
    for (int i = 0; i < numsSize - 2; i++) {
        int l = i + 1, r = numsSize - 1;
        while (l < r) {
            int diff = nums[i] + nums[l] + nums[r] - target;
            // dist should not equal to 0 (it will return directly)
            // so we take dist == 0 as a initial condition
            if (abs(diff) < abs(dist) || dist == 0) {
                dist = diff;
            }
            
            if (diff > 0) {
                r--;
            } else if (diff < 0) {
                l++;
            } else {
                return target;
            }
        }
    }

    return target + dist;
}
