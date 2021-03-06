#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;
using namespace System;


template <typename T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

template <>
char * Max(char * a, char * b)
{
	cout << "char * Max<char*>(char *a, char * b)" << endl;
	return strlen(a) > strlen(b) ? a : b;
	// strlen 문자열의 길이 반환
}

template <>
const char * Max(const char * a, const char * b)
{
	cout << "const char* Max<const char*>(const char* a, const char* b)" << endl;
	return strcmp(a, b) > 0 ? a : b;
	// strcmp(str1, str2) str1이 크면 양수반환, 작으면 음수 반환 같으면 0반환
}

int main()
{
	cout << Max(11, 15) << endl;
	cout << Max('T', 'Q') << endl;
	cout << Max(3.5, 7.5) << endl;
	cout << Max("Simple", "Best") << endl;

	char str1[] = "Simple";
	char str2[] = "Best";

	cout << Max(str1, str2) << endl;
    return 0;
}
