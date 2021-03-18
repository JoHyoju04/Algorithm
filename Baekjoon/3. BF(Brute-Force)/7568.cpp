#include<iostream>
using namespace std;
int main()
{
    int N, cnt, x[51] = { 0, }, y[51] = { 0, };   cin >> N; //x,y¸¦ pair<int,int> person[50]
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];  //cin>>person[i].first>>person[i].second;
    }
    for (int i = 0; i < N; i++) {
        cnt = 1;
        for (int j = 0; j < N; j++) {
            if (i != j && x[i] < x[j] && y[i] < y[j])  cnt++;       //if(i!=j && person[i].first<person[j].first && person[i].second<person[j].second)
        }
        cout << cnt << " ";
    }
    return 0;
}