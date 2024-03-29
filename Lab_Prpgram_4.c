#include <stdio.h>

// Function to calculate the length of a string
int stringLength(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}
// Function to reverse a string
void stringReverse(char *str) {
    int length = stringLength(str);
    int i, j;
    char temp;
    
    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to compare two strings
int stringCompare(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }

    if (*str1 == *str2) {
        return 0;   // Strings are equal
    } else {
        return (*str1 < *str2) ? -1 : 1;
    }
}

// Function to concatenate two strings
void stringConcatenate(char *dest, const char *src) {
    int destLength = stringLength(dest);
    int i;

    while (*src != '\0') {
        dest[destLength] = *src;
        destLength++;
        src++;
    }

    dest[destLength] = '\0';
}

// Function to copy one string to another
void stringCopy(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';
}

int main() {
    char str1[100], str2[100], result[200];

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    // String Length
    printf("Length of str1: %d\n", stringLength(str1));

    // String Reversal
    stringReverse(str1);
    printf("Reversed str1: %s\n", str1);

    // String Compare
    printf("Comparison result: %d\n", stringCompare(str1, str2));

    // String Concatenate
    stringCopy(result, str1);
    stringConcatenate(result, str2);
    printf("Concatenated string: %s\n", result);

    // String Copy
    stringCopy(result, str1);
    printf("Copied string: %s\n", result);

    return 0;
}
