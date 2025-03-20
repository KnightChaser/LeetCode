bool isAnagram(char* s, char* t) {
    // If strings s and t have different lengths, they cannot be anagrams.
    if (strlen(s) != strlen(t)) {
        return false;
    }

    // Build the hashmap
    int hashmap[256] = {0, };

    // Store the frequency of each character in s
    for (int i = 0; s[i] != '\0'; i++) {
        hashmap[(unsigned char)s[i]]++;
    }

    // Check if t is an anagram of s.
    // If hashmap[t[i]] is 0, it means that t[i] is not in s.
    for (int i = 0; s[i] != '\0'; i++) {
        if (hashmap[(unsigned char)t[i]] == 0) {
            return false;
        }
        hashmap[(unsigned char)t[i]]--;
    }

    return true;
}
