char* toLowerCase(char* s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            // small letter is 32 greater than capital letter in ASCII
            s[i] = s[i] + 32;
        }
    }
    return s;
}
