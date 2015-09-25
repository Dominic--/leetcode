int reverse(int x) {
    int xx = x;
    long long int y = x;
    y = y > 0 ? y : -y;
    
    long long ret = 0;
    int digit = 0;
    while (y != 0) {
        digit = y % 10;
        y = y / 10;
        
        ret = ret * 10 + digit;
    }
    
    if (ret > INT_MAX || -ret < INT_MIN) {
        return 0;
    }
    
    return xx < 0 ? -ret : ret;
}