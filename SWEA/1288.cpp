#include<iostream>
#include<string>
using namespace std;

int cnt[10];

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int N, k = 1;
        cin >> N;
        string str = "";
        while (true) {
            str = to_string(N * k);
            k++;
            for (int i = 0; i < str.size(); i++) {
                cnt[str[i] - '0']++;
            }
            bool check = false;
            for (int i = 0; i <= 9; i++) {
                if (cnt[i] == 0) {
                    check = true;
                    break;
                }
            }
            if (check == false) {
                break;
            }
        }

        for (int i = 0; i <= 9; i++)
            cnt[i] = 0;

        cout << "#" << test_case << " " << str << "\n";

    }
    return 0;
}


/*
#include<iostream>
using namespace std;

int main()
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int N;
        int check = 0;
        int CN = 0;

        cin >> N;

        while (true) {
            CN += N;

            int tmp = CN;

            while (tmp > 0) {
                check |= 1 << (tmp % 10);
                tmp /= 10;
            }

            if (check == (1 << 10) - 1) break;
        }

        cout << '#' << test_case << ' ' << CN << endl;
    }
    return 0;
}
*/