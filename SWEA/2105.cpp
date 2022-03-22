#include <stdio.h>

#define MAX (25 + 5)

int T, N;
int MAP[MAX][MAX];

int dessert[100 + 20];
int MAXANS;

void input()
{
	scanf("%d", &N);
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
			scanf("%d", &MAP[r][c]);
}

/* 순서대로 오른쪽 아래, 왼쪽 아래, 왼쪽 위, 오른쪽 위 */
int dr[] = { 1, 1, -1, -1 };
int dc[] = { 1, -1, -1, 1 };

void DFS(int L, int R, int C, int sr, int sc, int dir)
{
	if (dir == 4) return;

	if (R == sr && C == sc)
	{
		if (MAXANS < L) MAXANS = L;
		return;
	}

	/* MAP의 범위를 벗어나는 경우 */
	if (R > N || C > N || R < 1 || C < 1) return;

	if (dessert[MAP[R][C]] == 0)
	{
		dessert[MAP[R][C]] = 1;

		/* 현재 방향으로 진행 */
		DFS(L + 1, R + dr[dir], C + dc[dir], sr, sc, dir);

		/* 시계 방향으로 진행 */
		DFS(L + 1, R + dr[dir + 1], C + dc[dir + 1], sr, sc, dir + 1);

		dessert[MAP[R][C]] = 0;
	}
	else
		return;
}

int main(void)
{
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		input();

		MAXANS = -1;
		for (int r = 1; r <= N - 2; r++)
		{
			for (int c = 2; c <= N - 1; c++)
			{
				dessert[MAP[r][c]] = 1;
				DFS(1, r + 1, c + 1, r, c, 0);
				dessert[MAP[r][c]] = 0;
			}
		}

		printf("#%d %d\n", tc, MAXANS);
	}

	return 0;
}