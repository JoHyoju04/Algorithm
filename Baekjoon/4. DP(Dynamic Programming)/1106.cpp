#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct compare{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second>b.second;
    }
};

int solution(vector<int> &A) {
    priority_queue<pair<int,int>,vector<pair<int,int> >,cmp> pq;
	for(int i=0;i<A.size();i++){
		pq.push({i,A[i]});
	}
	answer=1
	int idx=0;
	pq.pop();

	while(!pq.empty()){
		int i=pq.top().first;
		if(idx<i){
			answer+=1;
			idx=i;
		}	
		pq.pop();
	}


}

//1<=C<=1000
//1<=n<=20
int dp[100001]; //돈을 i만큼 썼을때 최대 확보 고객
int answer = 987654321;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int c, n;
	cin >> c >> n;
	vector<pair<int, int>> vt(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vt[i] = { a,b };
	}

	for (int i = 1; i <= 100000; i++) {
		for (int j = 0; j < n; j++) {
			//나누어 떨어지는 경우
			if (i%vt[j].first == 0) {
				dp[i] = max(dp[i], (i / vt[j].first)*vt[j].second);
			}
			if (i - vt[j].first >= 0) {
				dp[i] = max(dp[i],dp[i-vt[j].first]+ vt[j].second);
			}
		}
		if (c<=dp[i]) {
			cout << i;
			return 0;
		}
	}

	return 0;
}