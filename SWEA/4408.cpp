#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct room {
    int start, finish;
};

int N;
vector<room> v;
bool visited[400];
int answer;

bool compare(room r1, room r2) {
    if (r1.start == r2.start) {
        return r1.finish < r2.finish;
    }
    return r1.start < r2.start;
}

bool allStudentReturn() {
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

int main() {

    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; test_case++) {

        N = 0;
        v.clear();
        answer = 0;

        cin >> N;
        for (int i = 0; i < N; i++) {

            int room1, room2;
            cin >> room1 >> room2;

            if (room1 > room2) {
                v.push_back({ room2, room1 });
            }
            else {
                v.push_back({ room1, room2 });
            }
        }

        sort(v.begin(), v.end(), compare);

        while (true) {

            if (allStudentReturn()) {
                break;
            }

            int finish = 0;

            for (int i = 0; i < N; i++) {

                if (!visited[i] && v[i].start > finish) {

                    visited[i] = true;

                    if (v[i].finish % 2 == 1) {
                        finish = v[i].finish + 1;
                    }
                    else {
                        finish = v[i].finish;
                    }
                }
            }

            answer++;
        }
        cout << "#" << test_case << " " << answer << "\n";
        for (int i = 0; i < 400; i++)	visited[i] = 0;
    }

    return 0;
}