#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for (int mod = n - 1; mod > 1; mod--) {
        if ((n - 1) % mod == 0)    answer = mod;
    }
    return answer;
}