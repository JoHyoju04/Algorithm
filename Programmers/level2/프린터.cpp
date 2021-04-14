#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0, idx = 0;
    vector<int> printer = priorities;
    while (true) {
        if (printer[idx] == *max_element(printer.begin() + idx, printer.end())) {
            answer++;
            if (location == idx)   break;
        }
        else {
            if (location == idx)   location = printer.size();
            printer.push_back(printer[idx]);
        }
        idx++;
    }
    return answer;
}