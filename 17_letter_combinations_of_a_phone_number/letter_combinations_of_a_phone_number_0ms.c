#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char maps[][4] = {
                {' '},
                {},
                {'a', 'b', 'c'},
                {'d', 'e', 'f'},
                {'g', 'h', 'i'},
                {'j', 'k', 'l'},
                {'m', 'n', 'o'},
                {'p', 'q', 'r', 's'},
                {'t', 'u', 'v'},
                {'w', 'x', 'y', 'z'}
                };   
int maps_size[] = {1, 0, 3, 3, 3, 3, 3, 4, 3, 4};
int * nums;

int increase(int * index, int len) {
    int carry = 1;
    int cur = len - 1;
    while (carry == 1 && cur != -1) {
        index[cur] += 1;
        carry = 0;

        if (index[cur] == maps_size[nums[cur]]) {
            carry = 1;
            index[cur--] = 0;
        } 
    }

    return cur == -1 ? -1 : 1;
}


char** letterCombinations(char* digits, int* returnSize) {
    int len = strlen(digits);
    if (len == 0) {
        char ** empty = (char **) malloc(1);
        *returnSize = 0;
        return empty;
    }


    nums = (int *) malloc(len * sizeof(int));
    int totalsize = 1;
    for (int i = 0; i < len; i++) {
        nums[i] = (int) (digits[i] - '0');
        totalsize *= maps_size[nums[i]];
    }
    char ** ret = (char **) malloc(totalsize * sizeof(char *));
    int * index = (int *) malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        index[i] = 0;
    }

    int count = 0;
    while (1) {
        char * tmp = (char *) malloc(len + 1);
        for (int i = 0; i < len; i++) {
            tmp[i] = maps[nums[i]][index[i]];
        }
        tmp[len] = '\0';

        ret[count++] = tmp;
        if (increase(index, len) == -1) break;
    }

    *returnSize = count;
    return  ret;
}
