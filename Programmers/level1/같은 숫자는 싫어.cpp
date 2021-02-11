#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    int num = 10;
    for (int i = 0; i < arr.size(); i++) {
        if (num != arr[i]) {
            num = arr[i];
            answer.push_back(num);
        }
    }

    return answer;
}