#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	string s, t;
	while (cin >> s >> t) {
		int sIdx = 0;
		int tIdx = 0;
		for (; tIdx < t.size(); tIdx++) {
			if (s[sIdx] == t[tIdx]) {
				sIdx++;
				if (sIdx == s.size()) {
					cout << "Yes" << '\n';
					break;
				}
			}
		}
		if (tIdx == t.size())
			cout << "No" << '\n';
	}
	return 0;