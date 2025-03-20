char* mergeAlternately(char* word1, char* word2){
    char* result = (char*)malloc(strlen(word1) + strlen(word2) + 1);
    memset(result, 0, strlen(word1) + strlen(word2) + 1);
    int resultIndex = 0;
    
    while (*word1 || *word2) {
        if (*word1) {
            result[resultIndex++] = *word1++;
        }

        if (*word2) {
            result[resultIndex++] = *word2++;
        }
    }

    return result;
}
