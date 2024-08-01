#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int isDelimiter(char ch) {
    return ch == ' ' || ch == ',' || ch == '.' || ch == '?' || ch == '!' || ch == ';' || ch == ':' || ch == '\n' || ch == '\t';
}

void countWordFrequencies(char *paragraph) {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int frequencies[MAX_WORDS] = {0};
    int wordCount = 0;

    char *word = strtok(paragraph, " ,.?;:!\n\t");

    while (word != NULL) {
        toLowerCase(word);

        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i], word) == 0) {
                frequencies[i]++;
                found = 1;
                break;
            }
        }

        if (!found && wordCount < MAX_WORDS) {
            strcpy(words[wordCount], word);
            frequencies[wordCount]++;
            wordCount++;
        }

        word = strtok(NULL, " ,.?;:!\n\t");
    }

    printf("Word Frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i], frequencies[i]);
    }
}

int main() {
    char paragraph[5000];

    printf("Enter a paragraph: ");
    fgets(paragraph, sizeof(paragraph), stdin);

    countWordFrequencies(paragraph);

    return 0;
}
