bool isValid(char* s) {
    char parentheses[1000];
    int position = 0;
    
    char c = *s;
    while (c != '\0') {
        switch (c) {
            case '{':
            case '(':
            case '[':
                parentheses[position++] = c;
                break;
            case ')':
                if (parentheses[--position] != '(') return false;
                break;
            case '}':
                if (parentheses[--position] != '{') return false;
                break;
            case ']':
                if (parentheses[--position] != '[') return false;
                break;
            default:
                break;
        }
        c = *(++s);
    }
    
    return position == 0 ? true : false;
}