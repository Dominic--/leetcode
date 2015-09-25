double findMedianSortedArrays(int A[], int m, int B[], int n) {
    // when odd, median will be one element
    // otherwise, will be the average of two median elements
    int median = (m + n) / 2;
    int odd = (m + n) % 2;
    
    double val1 = 0, val2 = 0;
    if (m == 0) {
        val1 = B[median];
        val2 = B[median - 1];
    } else if (n == 0) {
        val1 = A[median];
        val2 = A[median - 1];
    } else {
        int i = 0, j = 0;
        int count = 0;
        
        // why median plus 1? we do not care what value our pointer points,
        // but care the value we have compared
        while (count < median + 1) {
            if (A[i] < B[j]) {
                if (i < m) {
                    val2 = val1;
                    val1 = A[i];
                    i++;
                } else {
                    if (j < n) {
                        val2 = val1;
                        val1 = B[j];
                        j++;
                    }
                }
            } else {
                if (j < n) {
                    val2 = val1;
                    val1 = B[j];
                    j++;
                } else {
                    if (i < m) {
                        val2 = val1;
                        val1 = A[i];
                        i++;
                    }
                }
            }
            
            count++;
        }
    }
    
    if (odd == 0) {
        return (val1 + val2) / 2;
    } else {
        return val1;
    }
}