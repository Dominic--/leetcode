void swap(int *y, int a, int b) {
    int tmp = y[a];
    y[a] = y[b];
    y[b] = tmp;
}

void quicksort(int *x, int *y, int l, int u) {
    if (l >= u) {
        return;
    }
    
    swap(y, l, (l + u) / 2);
    
    int m = l;
    for (int i = l + 1; i <= u; i++) {
        if (x[y[i]] < x[y[l]]) {
            swap(y, ++m, i);
        }
    }
    
    swap(y, l, m);
    
    quicksort(x, y, l, m - 1);
    quicksort(x, y, m + 1, u);
}

int *twoSum(int numbers[], int n, int target) {
    // let indices be the index of numbers
    const int N = n;
    int indices[N];
    for (int i = 0; i < N; i++) {
        indices[i] = i;
    }
    
    // resort the numbers, change the numbers of indices rather than numbers
    quicksort(numbers, indices, 0, N - 1);
    
    // find the pair who add up to the target
    int l = 0, u = N - 1;
    int result[2];
    while (l != u) {
        int tmp = numbers[indices[l]] + numbers[indices[u]];
        if (tmp < target) {
            l++;
        } else if (tmp > target) {
            u--;
        } else {
            if (indices[l] > indices[u]) {
                result[0] = indices[u] + 1;
                result[1] = indices[l] + 1;
            } else {
                result[0] = indices[l] + 1;
                result[1] = indices[u] + 1;
            }
            return result;
        }
    }
}