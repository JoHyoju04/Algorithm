#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int answer = 0;
string str = "";
vector<int> list;
vector<bool> visited;
bool isPrime(int num) {
    int cnt = 0;
    if (num <= 1)  return false;
    for (int i = 2; i <= num; i++) {
        if (num % i == 0)    cnt++;
        if (cnt == 2)  return false;
    }
    return true;
}
void dfs(int num, string numbers) {
    if (num == numbers.size()) {
        return;
    }
    for (int i = 0; i < numbers.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            str += numbers[i];
            list.push_back(stoi(str));
            dfs(num + 1, numbers);
            visited[i] = false;
            str.pop_back();
        }

    }
}
int solution(string numbers) {
    visited.assign(numbers.size(), 0);
    dfs(0, numbers);
    sort(list.begin(), list.end());
    list.erase(unique(list.begin(), list.end()), list.end());
    for (int i = 0; i < list.size(); i++) {
        if (isPrime(list[i]))    answer++;
    }
    return answer;
}