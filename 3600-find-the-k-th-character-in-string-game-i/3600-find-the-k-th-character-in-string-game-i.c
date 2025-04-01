#include <memory.h>
#include <stdio.h>

char kthCharacter(int k) {
    // Base case
    char word[512 + 1];
    char temp[512 + 1];
    int currentLength = 1;

    // Base case: start with 'a':
    word[0] = 'a';
    word[1] = '\0';

    // Rpeatedly generate the word
    while (currentLength < 512) {
        // Transform each character in the word
        for (int i = 0; i < currentLength; i++) {
            temp[i] = (word[i] == 'z') ? 'a' : word[i] + 1;
        }

        // Append the transformed word to the original word
        strncpy(word + currentLength, temp, currentLength);
        currentLength *= 2;
        word[currentLength] = '\0';
    }

    printf("word: %s\n", word);

    // Note that the array index starts from 0, so we need to subtract 1 from k
    return word[k - 1];
}
