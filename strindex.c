//* gcc -o output strindex.c && output

#include <stdio.h>

#define MAXLINE 1000

int mygetline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; // search for this

int main(int argc, char const *argv[])
{
    char line[MAXLINE];
    int found = 0;

    while (mygetline(line, MAXLINE) > 0)
    {
        if (strindex(line, pattern) >= 0)
        {
            printf("%s", line);
            found++;
        }
    }
    return found;
}

int mygetline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}

int strindex(char source[], char searchfor[])
{
    int i, j, k;

    for (i = 0; source[i] != '\0'; i++)
    {
        for (j = i, k = 0; searchfor[k] != '\0' && source[j] == searchfor[k]; j++, k++)
            ;

        if (k > 0 && searchfor[k] == '\0')
            return i;
    }

    return -1;
}
