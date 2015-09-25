struct my {
    int id;
    int index;
    UT_hash_handle hh;
};

struct my *hash_numbers = NULL;

void add_number(int id, int index) {
    struct my *s = NULL;
    
    HASH_FIND_INT(hash_numbers, &id, s);
    if (s == NULL) {
        s = (struct my *) malloc(sizeof(struct my));
        s->id = id;
        s->index = index;
        HASH_ADD_INT(hash_numbers, id, s);
    }
}

struct my *find_number(int id) {
    struct my *s;
    HASH_FIND_INT(hash_numbers, &id, s);
    return s;
}

int *twoSum(int numbers[], int n, int target) {
    hash_numbers = NULL;
    
    struct my * s = NULL;
    int result[2];
    for (int i = 0; i < n; i++) {
        s = find_number(target - numbers[i]);
        if (s != NULL) {
            if (s->index > i) {
                result[0] = i + 1;
                result[1] = s->index + 1;
            } else {
                result[0] = s->index + 1;
                result[1] = i + 1;
            }
            
            return result;
        }
        
        add_number(numbers[i], i);
    }
    
}