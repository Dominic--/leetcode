int myAtoi(char *str) {
    int l = strlen(str);
    if (l == 0) {
        return 0;
    }
    
    // remove space and 0 at the first of string
    int start = 0;
    while (start < l && (str[start] == ' ' || str[start] == '0')) {
        start++;
    }
    
    // get the -/+ first if exist
    bool positive = true;
    if (start < l && str[start] == '-') {
        positive = false;
        start += 1;
    } else if (start < l && str[start] == '+') {
        start += 1;
    }
    
    // avoid for int max/min overflow
    long long ret = 0;
    for (int i = start; i < l; i++) {
        if (str[i] < 48 || str[i] > 57) {
            break;
        }
        
        ret = ret * 10 + str[i] - 48;
        
        // avoid for long long int max/min overflow
        if (positive && ret > INT_MAX || (!positive && -ret < INT_MIN)) {
            break;
        }
    }
    
    // it seems when overflow return the INT_MAX or INT_MIN;
    if (positive) {
        return ret > INT_MAX ? 2147483647 : ret;
    } else {
        return -ret < INT_MIN ? -2147483648 : -ret;
    }
}