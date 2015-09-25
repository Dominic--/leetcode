int lengthOfLongestSubstring(char *s) {
    int n = strlen(s);
    int chars[127];
    for (int i = 0; i < 127; i++) {
        chars[i] = -1;
    }

    int l = 0, u = 1;
    chars[s[l]] = 0;
    int longest = 1;
    while (u < n) {
        int repeat = chars[s[u]];
        chars[s[u]] = u;
        
        if (repeat >= l) {
            l = repeat + 1;
        }
        
        u++;
        if (longest < u - l) {
            longest = u - l;
        }
    }
    
    return n ? longest : 0;
}