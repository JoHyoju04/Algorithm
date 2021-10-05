#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    string A, B;
    int answer = 51;
    cin >> A >> B;

    for (int i = 0; i <= B.size() - A.size(); i++) {
        int bIdx = i,cnt=0;
        for (int j = 0; j < A.size(); j++) {
            if (B[bIdx++] != A[j])   cnt++;
        }
        answer = answer < cnt ? answer : cnt;
    }

    cout << answer;
    return 0;
}