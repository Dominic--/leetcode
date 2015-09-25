char *intToRoman(int num) {
    char * symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    
    char *roman = (char *) malloc(100);
    for (int i = 0; i < sizeof(value)/sizeof(int); i++) {
        while (num >= value[i]) {
            num -= value[i];
            strcat(roman, symbols[i]);
        }
    }
    
    return roman;
}