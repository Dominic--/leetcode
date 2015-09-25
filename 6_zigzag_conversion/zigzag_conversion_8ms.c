char *convert(char *s, int nRows) {
    int l = strlen(s);
    char * result = (char *) malloc(l + 1);
    
    if (nRows == 1 || l == 0) {
        strcpy(result, s);
        return result;
    } else {
        int tmp = 0, c = 0;
        for (int i = 0; i < nRows; i++) {
            tmp = i;
            if (i == 0 || i == nRows - 1) {
                while (tmp < l) {
                    result[c++] = s[tmp];
                    tmp += 2 * nRows - 2;
                }
            } else {
                int up = 1;
                int left = 2 * nRows - 2 * i - 2, right = 2 * i;
                while (tmp < l) {
                    result[c++] = s[tmp];
                    tmp = up == 1 ? tmp + left : tmp + right;
                    up = up == 1 ? 0 : 1;
                }
            }
        }
        result[c] = '\0';
    }
    
    return result;
}
