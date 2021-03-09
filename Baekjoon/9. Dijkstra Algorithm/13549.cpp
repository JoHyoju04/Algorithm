/*
    < 13549 : ¼û¹Ù²ÀÁú3 >
*/
#include <iostream>
#include <vector>
#include <queue>
#define MAX 100000
using namespace std;
vector<bool> visited(MAX, 0);

int minSecond(int start, int end) {
    priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
    pq.push({ 0,start });
    visited[start] = true;
    while (!pq.empty()) {
        int time = pq.top().first;
        int loc = pq.top().second;
        pq.pop();

        if (loc == end)    return time;

        if (loc * 2 <= MAX && !visited[loc * 2]) {
            pq.push({ time,loc * 2 });
            visited[loc * 2] = true;
        }
        if (loc + 1 <= MAX && !visited[loc + 1]) {
            pq.push({ time + 1,loc + 1 });
            visited[loc + 1] = true;
        }
        if (loc - 1 >= 0 && !visited[loc - 1]) {
            pq.push({ time + 1,loc - 1 });
            visited[loc - 1] = true;
        }
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    cout << minSecond(N, K);
    return 0;
}