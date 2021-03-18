#include<iostream>
using namespace std;
int main()
{
    int T, K, sum;
    bool key;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> K;
        int num = 2 * K;
        key = false;
        //1부터 44까지, n(n+1)/2 <= 1000 이므로 n의 최댓값은 44이다.
        for (int a = 1; a <= 44; a++) { 
            for (int b = 1; b <= 44; b++) {
                for (int c = 1; c <= 44; c++) {
                    sum = a * (a + 1) + b * (b + 1) + c * (c + 1);
                    if (sum == num) {
                        cout << "1\n";
                        key = true;
                        break;
                    }
                }
                if (key) break;
            }
            if (key) break;
        }
        if (!key)    cout << "0\n";
    }
    return 0;
}