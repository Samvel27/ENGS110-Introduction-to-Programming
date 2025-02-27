#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare (const void *a, const void *b) {
    return (*(char *)a - *(char *)b); // rules for qsort function
}

int main() {
	char str1[100], str2[100]; // initializing both strings
	printf("Please input first string: ");
	scanf("%s", str1); // obtaining str1
        printf("\nPlease input second string: ");
        scanf("%s", str2); // obtaining str2

	if (strlen(str1) != strlen(str2)) { // if their length is different they cannot be anagrams
		printf("\nStrings are not anagrams\n");
		return 0;
	}

	qsort(str1, strlen(str1), sizeof(char), compare); // sorting str1 to compare later
        qsort(str2, strlen(str2), sizeof(char), compare); // sorting str2 to compare letter
	
	if (!strcmp(str1, str2)) printf("\nStrings are anagrams\n"); // if the sorted versions are identical they were anagrams
	else printf("\nStrings are not anagrams\n"); // else, they are not anagrams

	return 0;
}
