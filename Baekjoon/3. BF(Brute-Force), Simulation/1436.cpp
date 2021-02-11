#include<iostream>
#include<string>
using namespace std;

int main()
{
    int N, num = 666, series = 0;
    string target;
    cin >> N;
    while (1)
    {
        target = to_string(num);
        for (int j = 0; j < target.length() - 2; j++)
            if (target[j] == '6' && target[j + 1] == '6' && target[j + 2] == '6')
            {
                series++;
                if (series == N) {
                    cout << num;
                    return 0;
                }
                break;
            }
        num++;
    }
    return 0;
}