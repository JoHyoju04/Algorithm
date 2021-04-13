#include <string>
#include <vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first)	return a.second > b.second;
		else return a.first < b.first;
	}
};

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> m;
	for (int i = 0; i < genres.size(); i++) {
		m[genres[i]] += plays[i];
	}
	vector<pair<string, int> >sorted(m.begin(), m.end());
	sort(sorted.begin(), sorted.end(), cmp);
	for (auto g : sorted) {
		priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq;
		for (int i = 0; i < genres.size(); i++) {
			if (g.first == genres[i])	pq.push({ plays[i],i });
		}
		for (int j = 0; j < 2; j++) {
			if (!pq.empty()) {
				answer.push_back(pq.top().second);
				pq.pop();
			}
		}
	}
	return answer;
}