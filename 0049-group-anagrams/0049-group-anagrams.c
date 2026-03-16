#include <stdlib.h>
#include <string.h>

int cmpChar(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}

char* sortString(const char* str) {
    int len = strlen(str);
    char* sorted = (char*)malloc((len + 1) * sizeof(char));
    strcpy(sorted, str);
    qsort(sorted, len, sizeof(char), cmpChar);
    return sorted;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    char*** result = (char***)malloc(strsSize * sizeof(char**));
    *returnColumnSizes = (int*)malloc(strsSize * sizeof(int));

    char** keys = (char**)malloc(strsSize * sizeof(char*));
    int groups = 0;

    for (int i = 0; i < strsSize; i++) {
        char* sorted = sortString(strs[i]);

        int found = -1;

        for (int j = 0; j < groups; j++) {
            if (strcmp(keys[j], sorted) == 0) {
                found = j;
                break;
            }
        }

        if (found == -1) {
            keys[groups] = sorted;
            result[groups] = (char**)malloc(strsSize * sizeof(char*));
            (*returnColumnSizes)[groups] = 0;
            found = groups;
            groups++;
        } else {
            free(sorted);
        }

        result[found][(*returnColumnSizes)[found]] = strs[i];
        (*returnColumnSizes)[found] += 1;
    }

    *returnSize = groups;

    free(keys);
    return result;
}