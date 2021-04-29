#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool check[8];

set<string> _set;

void dfs(vector<string> u_id, vector<string> b_id, int b_ind) {
	int b_size = b_id.size();
	int u_size = u_id.size();
	if (b_ind >= b_size) {
		string temp = ""; 
		for (int i = 0; i < u_id.size(); i++) {
			if (check[i]) {
				temp += i;
			}
		}
		_set.insert(temp);
		return;

	}
	for (int i = 0; i < u_size; i++) {
		if (b_id[b_ind].size() != u_id[i].size() || check[i]) {
			continue;
		}
		bool tmp = true;

		for (int j = 0; j < u_id[i].size(); j++) {
			if (b_id[b_ind][j] == '*') {
				continue;
			}
			if (u_id[i][j] != b_id[b_ind][j]) {
				tmp = false;
				break;
			}
		}

		if (tmp) {
			check[i] = true;
			dfs(u_id, b_id, b_ind + 1);
			check[i] = false;
		}
	}
}

int solution(vector<string> u_id, vector<string> b_id) {

	dfs(u_id, b_id, 0);
	int answer = _set.size();
	return answer;
}

