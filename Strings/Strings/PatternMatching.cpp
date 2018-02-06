#include <iostream>
#include "PatternMatching.h"

bool match_TxtNormal_PatWithRegExp(char *first, char *second) {
	if (*first == '\0' && *second == '\0')
		return true;

	if (*first == '*' && *(first + 1) != '\0' && *second == '\0')
		return false;

	if (*first == '?' && *second == '\0')
		return false;

	if (*first == '?' || *first == +*second)
		return match_TxtNormal_PatWithRegExp(first + 1, second + 1);

	if (*first == '*')
		return match_TxtNormal_PatWithRegExp(first + 1, second) || match_TxtNormal_PatWithRegExp(first, second + 1);

	return false;
}