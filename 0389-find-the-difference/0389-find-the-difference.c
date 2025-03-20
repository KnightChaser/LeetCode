char findTheDifference(char* s, char* t) {
    char hashTable[256] = {0, };
    
    // Store the count of each character in s
    for (int i = 0; s[i] != '\0'; i++) {
        hashTable[s[i]]++;
    }

    // Check the count of each character in t.
    // If the count is less than 0, return the character.
    for (int i = 0; t[i] != '\0'; i++) {
        hashTable[t[i]]--;
        if (hashTable[t[i]] < 0) {
            return t[i];
        }
    }

    // To pass the compilation, just return 0. (actually unreachable)
    return 0;
}
