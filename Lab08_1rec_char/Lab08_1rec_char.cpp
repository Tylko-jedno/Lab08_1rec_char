#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int Count(const char* str) {
	if (*str == '\0') {
		return 0;
	}

	int count = (*str == '+' || *str == '-' || *str == '=') ? 1 : 0;

	return count + Count(str + 1);
}

int CalculateNewLength(const char* str) {
	if (*str == '\0') {
		return 0;  
	}

	if (*str == '+' || *str == '-' || *str == '=') {
		return 2 + CalculateNewLength(str + 1);
	}
	else {
		return 1 + CalculateNewLength(str + 1);
	}
}

void ChangeHelper(const char* str, char* newStr, int& j) {
	if (*str == '\0') {
		newStr[j] = '\0';
		return;
	}

	if (*str == '+' || *str == '-' || *str == '=') {
		newStr[j++] = '*';
		newStr[j++] = '*';
	}
	else {
		newStr[j++] = *str;
	}

	ChangeHelper(str + 1, newStr, j);
}

char* Change(const char* str) {
	int newLength = CalculateNewLength(str);

	char* newStr = new char[newLength + 1];
	int j = 0;

	ChangeHelper(str, newStr, j);

	return newStr;
}


int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << Count(str) << " symbols: +-=" << endl;
	char* dest = new char[151];
	dest = Change(str);
	cout << "Modified string (result): " << dest << endl;
	return 0;
}