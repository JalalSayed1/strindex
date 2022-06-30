//* gcc -o output strindex_lastoccurrence.c && output

#include <stdio.h>

#define MAXLINE 1000

int mygetline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; // search for this

int main(int argc, char const *argv[]) {
    char line[MAXLINE];
    int found = 0;

    while (mygetline(line, MAXLINE) > 0) {
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    }
    return found;
}

int mygetline(char s[], int lim) {
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}

/**
 * @brief Find last occurrence of a substring searchfor in a string source.
 *
 * @param source The string to search in.
 * @param searchfor The substring to search for.
 * @return int The index of the last occurrence of searchfor in source. index of the last character of searchfor in source..
 */
int strindex(char source[], char searchfor[]) {
    int i, j, k, last, currentindex;

    currentindex = 0;
    last = -1;

    for (i = 0; source[i] != '\0'; i++) {

        k = 0;
        for (j = i; searchfor[k] != '\0' && source[j] == searchfor[k]; j++) {
            k++;
            if (k == strlen(searchfor)) {
                last = i + k;
            }
        }
    }

    printf("%d\n", last);
    return last;
}
