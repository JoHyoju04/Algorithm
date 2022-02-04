#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_set>

using namespace std;

typedef long long ll;

int n, k;
queue<int> q;
unordered_set<int> s;
int dx[] = { 1, -1 };

ll bfs()
{
    ll distance = 1, cnt = 0, ans = 0;
    while (!q.empty())
    {
        int q_size = q.size();
        while (q_size--)
        {
            int cur = q.front();
            q.pop();

            for (int i = 0; i < 2; i++)
            {
                int next = cur + dx[i];
                if (!(s.count(next) >= 1))
                {
                    s.insert(next);
                    q.push(next);

                    cnt++; 
                    ans += distance; 

                    if (cnt == k) 
                        return ans; 
                }
            }
        }
        distance++; 
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        q.push(a);
        s.insert(a); 
    }

    ll ans = bfs();

    cout << ans << "\n";

    return 0;
}