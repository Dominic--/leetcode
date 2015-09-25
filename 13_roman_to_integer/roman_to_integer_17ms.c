// M 1000
// D 500
// C 100
// L 50
// x 10
// V 5
// I 1

int romanToInt(char *s) {
    int len = strlen(s);
    
    char last = ' ';
    int res = 0;
    for (int i = 0; i < len; i++) {
        switch (s[i]) {
            case 'M':
                if (last == 'C') {
                    res  = res - 100 + 900;
                } else {
                    res += 1000;
                }
                last = 'M';
                break;
            case 'D':
                if (last == 'C') {
                    res  = res - 100 + 400;
                } else {
                    res += 500;
                }
                last = 'D';
                break;
            case 'C':
                if (last == 'X') {
                    res  = res - 10 + 90;
                } else {
                    res += 100;
                }
                last = 'C';
                break;
            case 'L':
                if (last == 'X') {
                    res  = res - 10 + 40;
                } else {
                    res += 50;
                }
                last = 'L';
                break;
            case 'X':
                if (last == 'I') {
                    res  = res - 1 + 9;
                } else {
                    res += 10;
                }
                last = 'X';
                break;
            case 'V':
                if (last == 'I') {
                    res  = res - 1 + 4;
                } else {
                    res += 5;
                }
                last = 'V';
                break;
            case 'I':
                res += 1;
                last = 'I';
                break;
            default:
                break;
        }
    }
    return res;
}
