#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N = 0, num;
    vector<int> array;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        array.push_back(num);
    }
    sort(array.begin(), array.end());
    for (int k = 0; k < N; k++) {
        cout << array[k] << '\n';
    }
}