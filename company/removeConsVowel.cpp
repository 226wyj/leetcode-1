#include <bits/stdc++.h>

using namespace std;
bool isVowel(char c) {
	return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
}

int main() {
	string str;
	cin >> str;
	string str1 = "";
	str1 = str1 + str[0];
	for (int i = 1; i < (int)str.size(); ++i) {
		if ((!isVowel(str[i - 1])) || (!isVowel(str[i]))) {
			char c = str[i];
			str1 += c;
		}
	}
	cout << str1;
	return 0;
}