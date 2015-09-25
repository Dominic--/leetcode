int lengthOfLongestSubstring(char *s) {
    int n = strlen(s);
    int l = 0, u = 1;
    int longest = 1;
    while (u < n) {
        int repeat = -1;
        for (int i = u - 1; i >= l; i--) {
            if (s[u] == s[i]) {
                repeat = i;
                break;
            }
        }
        
        if (repeat > -1) {
            l = repeat + 1;
        }
        
        u++;
        if (longest < u - l) {
            longest = u - l;
        }
    }
    
    return n ? longest : 0;
}