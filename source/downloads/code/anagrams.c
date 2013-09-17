/*
 * 1.4 Write a method to decide if two strings are anagrams (易位构词或同构词) or not. 
 */

#include <stdio.h>
#include <string.h>


/**
 * assume ASCII string
 */
int anagram(const char *str1, const char *str2) {
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2) return 0;
	if (str1 == str2) return 1;
	int letters[256];

	return 0;
}


int main() {

	/**
	 * Composer and crossword geek Stephen Sondheim once noted, brilliantly, that "Cinerama" is an anagram of "American".
	 */

	const char *str1 = "cinerama";
	const char *str2 = "american";

	printf("Composer and crossword geek Stephen Sondheim once noted, brilliantly, that %s is an anagram of %s, this is: %d\n", str1, str2, anagram(str1, str2));
	return 0;
}
