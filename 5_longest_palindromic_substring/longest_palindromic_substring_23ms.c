int check_palindrome(char *s, int i, int j) {
    int len = 0;
    int l = strlen(s);
    
    if (i == j) {
        len = 1;
        while (i > 0 && j < l - 1 && s[--i] == s[++j]) {
            len = len + 2;
        }
    } else {
        while (i >= 0 && j <= l - 1 && s[i--] == s[j++]) {
            len = len + 2;
        }
    }
    
    return len;
}

char *longestPalindrome(char *s) {
    int l = strlen(s);
    int length[10000];
    
    for (int i = 0; i < l - 1; i++) {
        length[2 * i] = check_palindrome(s, i, i);
        
        length[2 * i + 1] = check_palindrome(s, i, i + 1);
    }
    
    int max_l = 0;
    int center = 0;
    for (int i = 0; i < 2 * l - 1; i++) {
        if (length[i] > max_l) {
            max_l = length[i];
            center = i;
        }
    }
    
    if (center % 2 == 0) {
        s[center / 2 + max_l / 2 + 1] = '\0';
        return s + center / 2 - max_l / 2;
    } else {
        s[center / 2 + max_l / 2 + 1] = '\0';
        return s + center / 2 - max_l / 2 + 1;
    }
}
