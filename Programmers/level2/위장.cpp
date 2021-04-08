#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map <string, int> map; //������,����
    //�� ���� ���� ����
    for (auto type : clothes)   ++map[type[1]];
    //����� �� *= ���� ����+1(�� �Դ� ���)
    for (auto c : map) answer *= c.second + 1;

    //��� �� �Դ� ����� �� 1�� ����
    return answer - 1;
}