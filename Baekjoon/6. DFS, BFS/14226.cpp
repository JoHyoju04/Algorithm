#include <iostream>
#include <queue>
#include <stdio.h>
#include <cstring> // memset

using namespace std;

struct component {
    int display_c, clipboard_c, time_c;
};

#define MAX_SIZE 1000 + 1

int s;
bool visited[MAX_SIZE][MAX_SIZE]; // dispaly, clipboard

int bfs() {
    queue<component> q;
    q.push({ 1,0,0 });
    visited[1][0] = true;

    while (!q.empty()) {
        int display = q.front().display_c;
        int clipboard = q.front().clipboard_c;
        int time = q.front().time_c;
        q.pop();

        if (display == s) return time;

        if (0 < display && display < MAX_SIZE) {
            /* 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다.*/
            if (!visited[display][display]) {
                visited[display][display] = true;
                q.push({ display, display, time + 1 });
            }

            /* 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다. */
            if (clipboard > 0 && display + clipboard < MAX_SIZE) {
                if (!visited[display + clipboard][clipboard]) {
                    visited[display + clipboard][clipboard] = true;
                    q.push({ display + clipboard, clipboard, time + 1 });
                }
            }

            /* 화면에 있는 이모티콘 중 하나를 삭제한다. */
            if (!visited[display - 1][clipboard]) {
                visited[display - 1][clipboard] = true;
                q.push({ display - 1, clipboard, time + 1 });
            }
        }
    }
}

int main() {
    cin >> s;
    cout << bfs();
    return 0;
}