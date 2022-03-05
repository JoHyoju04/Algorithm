#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, x;
	cin >> n >> x;
	int sum = 0;
	int arr[250000];
	for (int i = 0; i < x; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	int answer = sum;
	int cnt = 1;
	for (int i = x; i < n; i++) {
		cin >> arr[i];
		sum += arr[i] - arr[i - x];
		if (sum >= answer) {
			if (sum == answer) {
				cnt++;
			}
			else {
				answer = sum;
				cnt = 1;
			}
		}
	}
	if (answer == 0) {
		cout << "SAD";
	}
	else
		cout << answer << '\n' << cnt;
	return 0;
}
/*
#include <iostream>
using namespace std;

int visit[250001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    long long maxS, sum = 0, num = 1;
    int start = 0, end = 0;
    int N, X;
    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        cin >> visit[i];
        if (i < X) sum += visit[i];
    }
    end = X - 1;
    maxS = sum;

    while (end < N-1) {
        sum += visit[++end];
        sum -= visit[start++];
        if (maxS == sum)   num++;
        if (maxS < sum) {
            maxS = sum;
            num = 1;
        }
    }
    if (maxS == 0) cout << "SAD";
    else cout << maxS << "\n" << num;

    return 0; 
}
*/