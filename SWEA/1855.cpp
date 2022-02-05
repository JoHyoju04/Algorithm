#include<iostream
>
#define MAX_N 100000
#define MAX_DE 16 // MAX Depth

typedef struct _list { int v; struct _list* next; } list;

int N, P[MAX_N + 2], BS[MAX_N + 2], AC[20][MAX_N + 2], DE[MAX_N + 2]; // AC[i][j]=j번 node의 2^i번째 조상, P[i]=i노드의 부모, Bfs Sequeuce, Depth

list pool[1000000]; int pool_idx; list E[MAX_N + 2];
int Q[MAX_N + 1000], front, rear, visited[MAX_N + 2];

void enqueue(int v) { Q[++rear] = v; };

int dequeue() { return Q[++front]; }

int queue_empty() { return front == rear; }

void init_list(list* l) { for (int i = 1; i <= N; i++) l[i].next = NULL; }

void insert_list(list* l, int x, int y) {
    list* p, * e, * n;
    e = pool + (++pool_idx); e->v = y;
    p = l + x; n = p->next;
    p->next = e; e->next = n;
}

void bfs() {
    int u, v, idx = 0; list* e;
    front = rear = -1; enqueue(1); visited[1] = 1; BS[++idx] = 1; DE[1] = 0;
    while (!queue_empty()) {
        u = dequeue();
        for (e = E[u].next; e; e = e->next) { v = e->v; enqueue(v); visited[v] = 1; BS[++idx] = v; DE[v] = DE[u] + 1; }
    }
}

void makeAC() {
    int i, j;
    for (j = 2, AC[0][1] = 0; j <= N; j++) AC[0][j] = P[j];
    for (i = 1; (1 << (i - 1)) <= N; i++) for (j = 2, AC[i][1] = 0; j <= N; j++) AC[i][j] = AC[i - 1][AC[i - 1][j]];
}

int calcDIST(int u, int v) {
    int i, j = 0, de, u1 = u, v1 = v;
    if (DE[u1] > DE[v1]) { // u, v depth 맞추기
        j = DE[u1] - DE[v1];
        for (i = 0; i <= MAX_DE; i++) {
            if ((1 << i) > j) break; if (!(j & (1 << i))) continue;
            u1 = AC[i][u1];
        }
    }
    else if (DE[u1] < DE[v1]) {
        j = DE[v1] - DE[u1];
        for (i = 0; i <= MAX_DE; i++) {
            if ((1 << i) > j) break; if (!(j & (1 << i))) continue;
            v1 = AC[i][v1];
        }
    }
    if (u1 == v1) return j;
    for (de = MAX_DE; de >= 0; de--) if ((1 << de) & DE[u1]) break;
    if ((1 << de) < DE[u1]) de++;
    for (i = de - 1; i >= 0; i--) if (AC[i][u1] != AC[i][v1]) { u1 = AC[i][u1]; v1 = AC[i][v1]; }
    u1 = AC[0][u1];
    return DE[u] + DE[v] - 2 * DE[u1];
}

long long calcD() {
    long long sum = 0; int i;
    for (i = 2; i <= N; i++) sum += calcDIST(BS[i - 1], BS[i]);
    return sum;
}

int main() {
    int t, T, i;
    scanf("%d\n", &T);
    for (i = 0; i <= MAX_DE + 1; i++) AC[i][0] = 0;
    for (t = 1; t <= T; t++) {
        scanf("%d\n", &N); for (i = 2; i <= N; i++) scanf("%d ", &P[i]);
        pool_idx = -1; init_list(E); for (i = N; i >= 2; i--) insert_list(E, P[i], i);
        bfs(); makeAC(); printf("#%d %lld\n", t, calcD());
    }
}