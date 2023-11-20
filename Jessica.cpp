#include <stdio.h>
#include <string.h>

#define HASH_TABLE_SIZE 10000

unsigned int customHash(char* key) {
    unsigned int hashValue = 0;
    
    for (int i = 0; key[i] != '\0'; ++i) {
        hashValue = (hashValue * 29) + key[i];
    }
    
    return hashValue % HASH_TABLE_SIZE;
}

int main() {
    char key[101];
    while (1) {
        scanf("%s", key);

        if (strcmp(key, "exit") == 0) {
            break;
        }

        unsigned int hashValue = customHash(key);
        printf("%u\n", hashValue);
    }

    return 0;
}
