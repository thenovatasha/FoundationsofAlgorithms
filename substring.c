/* Exercise 7.s1: Determine if a string is a subsequence of another string
 * Scaffold by Alistair Moffat, October 2013.
 * (c) University of Melbourne */

/* Write a function that returns 1 if the characters in s1 appear within
  s2 in the same order as they appear in s1.*/
/*For example, is_subsequence("bee", "abbreviate") should be 1, whereas 
  is_subsequence("bee", "acerbate") should be 0.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTR 100

/* function prototypes */

int is_subsequence(char s1[], char s2[]);
int read_line(char str[], int max);

/* scaffolding to test the required function */
int
main(int argc, char *argv[]) {
    char s1[MAXSTR], s2[MAXSTR];
    printf("Enter two strings, one string per line:\n");
    while ((read_line(s1, MAXSTR) == 1) && (read_line(s2, MAXSTR) == 1)) {
        printf("\"%s\" is ", s1);
        if (!is_subsequence(s1, s2)) {
            printf("**not** ");
        }
        printf("a subsequence of \"%s\"\n", s2);
    }
    return 0;
}

/* returns 1 if s1 is a subsequence of s2:
 * that is, all chars in s1 appear in the same order in s2 */
int
is_subsequence(char s1[], char s2[]) {
    // TODO: Implement this function.
    int j = 0;
    int strlen1 = strlen(s1);
    int strlen2 = strlen(s2);
    for(int i = 0; i < strlen2 && j < strlen1; i++) {
        if(s1[j] == s2[i]) {
            j++;
        }
    }
    if(j == strlen1) {
        return 1;
    }
    return 0;
}


/* read one line of input into a string of maximum length.
 * returns 1 if there still is text to be read (no EOF sent), 0 otherwise */
int
read_line(char str[], int max) {
    int n = 0, c;
    while ((c = getchar()) != EOF && c != '\n') {
        str[n++] = c;
        if (n == max - 1) {
            str[n++] = '\0';
            return 1;
        }
    }
    if (c == EOF && n == 0) {
        return 0;
    }
    str[n++] = '\0';
    return 1;
}
