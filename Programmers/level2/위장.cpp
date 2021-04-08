#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map <string, int> map; //옷종류,개수
    //옷 종류 개수 세기
    for (auto type : clothes)   ++map[type[1]];
    //경우의 수 *= 종류 개수+1(안 입는 경우)
    for (auto c : map) answer *= c.second + 1;

    //모두 안 입는 경우의 수 1만 뺴기
    return answer - 1;
}