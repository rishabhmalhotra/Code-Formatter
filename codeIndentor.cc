#include <iostream>
#include <string>
using namespace std;

int bracketIndetSpaceCounter = 0;
int leftOverForFunc = 0;

void spacesAccordingToIndentation() {
	if (leftOverForFunc == 0) {
		int i = bracketIndetSpaceCounter;
		while (i > 0) {
			cout << " ";
			--i;
		}
		return;
	} else {
		while (leftOverForFunc > 0) {
			cout << " ";
			--leftOverForFunc;
		}
		return;
	}
	
}

int main() {
	string s;
	int counter = 1;
	int newline = 0;
	int lastWordOrNot = 0;

	while(cin >> s) {

	if (counter == 1) {
			if (s == "//") {
				cout << s;
				getline(cin, s);
				cout << s << endl;
			} else if (s == ";") {
				cout << s << endl;
				newline = 1;
			} else if (s == "{") {
				cout << s << endl;
				newline = 1;
				++bracketIndetSpaceCounter;
			} else if (s == "}") {
				cout << s << endl;
				newline = 1;
				--bracketIndetSpaceCounter;
			} else {
				cout << s;
				lastWordOrNot = 1;
			}
		++counter;

	} else {

		if (s == "//") {
			if (newline == 1) {
				if (bracketIndetSpaceCounter != 0) {
					spacesAccordingToIndentation();
				}
			} else {
				cout << " ";
			}
				cout << s;
				getline(cin, s);
				cout << s << endl;
				newline = 1;
				lastWordOrNot = 0;
		} else if (s == ";") {
			if (newline == 1) {
				if (bracketIndetSpaceCounter != 0) {
					spacesAccordingToIndentation();
				}
			} else {
				cout << " ";
				}
				cout << s << endl;
				newline = 1;
				lastWordOrNot = 0;
		} else if (s == "{") {
			if (newline == 1) {
				if (bracketIndetSpaceCounter != 0) {
					spacesAccordingToIndentation();
				}
				} else {
				cout << " ";
				}
				cout << s << endl;
				newline = 1;
				++bracketIndetSpaceCounter;
				lastWordOrNot = 0;
		} else if (s == "}") {
				leftOverForFunc = bracketIndetSpaceCounter - 1;
			if (leftOverForFunc != 0) {
					spacesAccordingToIndentation();
				}
			cout << s << endl;
			newline = 1;
			--bracketIndetSpaceCounter;
			lastWordOrNot = 0;
		} else {
			if (newline == 1) {
				if (bracketIndetSpaceCounter != 0) {
					spacesAccordingToIndentation();
				}
			} else {
				cout << " ";
				}
				cout << s;
				newline = 0;
				lastWordOrNot = 1;
			}
		
		}
	}
	if (lastWordOrNot == 1) {
		cout << endl;
	}
}