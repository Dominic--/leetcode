char *longestCommonPrefix(char *strs[], int n) {
    char *empty = (char *) malloc(1);
    empty[0] = '\0';
    if (n == 0) {
        return empty;
    }
    
    int longest = 0;
    
    while (1) {
        
        int exist = 0;
        for (int i = 0; i < n; i++) {
            
            
            if (!(longest < strlen(strs[i]) && longest < strlen(strs[0]) && strs[i][longest] == strs[0][longest])) {
                
                exist = 1;
            }
            
        }
        if (exist == 0) {
            longest++;
        } else {
            if (longest == 0 || longest > strlen(strs[0])) {
                
                return empty;
            } else {
                if (longest < strlen(strs[0])) {
                    strs[0][longest] = '\0';
                }
                
                return strs[0];
            }
        }
    }
}
