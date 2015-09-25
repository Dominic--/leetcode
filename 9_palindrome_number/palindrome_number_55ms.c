bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    
    int base = 1;
    while (x / base >= 10) {
        base *= 10;
    }
    
    int right = 0, left = 0;
    while (base > 1) {
        // compare the most left and right digit
        if (x / base != x % 10) {
            return false;
        }
        
        x = x % base;
        x = x / 10;
        base /= 100;
    }
    
    return true;
}