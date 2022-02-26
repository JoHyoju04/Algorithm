#include<iostream>
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

/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
const int MAXN = 100005;
int n;
int d[MAXN],p[MAXN][23];
bool check[MAXN];
vector<vector<int>> Graph;

void sparse(){
    for(int i=1;i<=20;i++){
        for(int j=0;j<n;j++){
            p[j][i] = p[p[j][i-1]][i-1];
        }
    }
}

int lca(int x,int y){
    if(d[y]>d[x]) swap(x,y);
    for(int i=19;i>=0;i--){
        if((d[x]-d[y])>=(1<<i)) x = p[x][i];
    }
    if(x==y) return x;
    for(int i=19;i>=0;i--){
        if(p[x][i] != p[y][i]){
            x = p[x][i];
            y = p[y][i];
        }
    }
    return p[x][0];
}

int main(){
    //freopen("input.txt","r",stdin);
    int tcase; scanf(" %d",&tcase); int c=1;
    while(tcase--){
        memset(check,0,sizeof(check));
        memset(d,0,sizeof(d));
        memset(p,0,sizeof(p));
        Graph.clear();

        scanf(" %d",&n);
        Graph.resize(n+3);

        for(int i=1;i<n;i++){
            int x; scanf(" %d",&x);
            Graph[x-1].push_back(i);
        }
        for(int i=0;i<n;i++) sort(Graph[i].begin(),Graph[i].end());

        queue<pair<int,int>> dq;
        dq.push({0,0});
        check[0]=true;

        while(!dq.empty()){
            int now = dq.front().first;
            int depth = dq.front().second;
            dq.pop();
            d[now]=depth;

            for(int i=0;i<Graph[now].size();i++){
                int next = Graph[now][i];
                if(!check[next]){
                    check[next]=true;
                    p[next][0]=now;
                    dq.push({next,depth+1});
                }
            }
        }

        sparse();

        ll ret=0;
        memset(check,0,sizeof(check));
        vector<int> vt;
        queue<int> q;
        q.push(0);
        check[0]=true;

        while(!q.empty()){
            int now = q.front();
            q.pop();

            vt.push_back(now);
            for(int i=0;i<Graph[now].size();i++){
                int next = Graph[now][i];
                if(!check[next]){
                    check[next]=true;
                    q.push(next);
                }
            }
        }
        for(int i=0;i<n-1;i++){
            int LCA = lca(vt[i],vt[i+1]);
            ll a = d[vt[i]] - d[LCA];
            ll b = d[vt[i+1]] - d[LCA];
            ret+=a; ret+=b;
        }

        printf("#%d %lld\n",c++,ret);
    }
}

*/