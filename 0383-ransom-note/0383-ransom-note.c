bool canConstruct(char* ransomNote, char* magazine) {
    // frequency[x] = y means ASCII x can be appeared at most y times
    int frequency[256] = {0};

    // Make the hashmap with `magazine`.
    char *currMagazinePtr = (char *)magazine;
    while (*currMagazinePtr != NULL) {
        unsigned char currChar = currMagazinePtr[0];
        frequency[currChar]++;
        currMagazinePtr += sizeof(char);
    }

    // Check if `ransomNote` can be constructed only with `magazine`
    char *currRansomNotePtr = ransomNote;
    while (*currRansomNotePtr != NULL) {
        unsigned char currChar = currRansomNotePtr[0];
        if (frequency[currChar] > 0) {
            frequency[currChar]--;
        } else {
            // We're running out of the character!
            return false;
        }
        currRansomNotePtr += sizeof(char);
    }

    // No problem so far? Then, We passed.
    return true;
}