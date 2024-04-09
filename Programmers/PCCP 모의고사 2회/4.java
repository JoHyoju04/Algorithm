import java.util.Queue;
import java.util.LinkedList;


class Solution {
    public int solution(int n, int m, int[][] hole) {

        Queue<Node> queue = new LinkedList<>();
        boolean[][][] visited = new boolean[m][n][2];
        int[] dr = {1, 0, -1, 0};
        int[] dc = {0, 1, 0, -1};

        // 함정 체크 표시
        for (int[] h: hole){
            visited[h[1]-1][h[0]-1][0] = true;
            visited[h[1]-1][h[0]-1][1] = true;
        }

        // 시작지점
        queue.offer(new Node(0, 0, 0, 1));
        visited[0][0][1] = true;

        while (!queue.isEmpty()){
            Node node = queue.poll();

            if (node.r == m-1 && node.c == n-1){
                return node.cnt;
            }

            for (int i=0; i<4; i++){
                int newR = node.r + dr[i];
                int newC = node.c + dc[i];
                int doubleR = node.r + (dr[i] * 2);
                int doubleC = node.c + (dc[i] * 2);

                if (0 <= newR && newR < m && 0 <= newC && newC < n){
                    if (!visited[newR][newC][node.chance]){
                        visited[newR][newC][node.chance] = true;
                        queue.offer(new Node(newR, newC, node.cnt+1, node.chance));
                    }
                }

                if (node.chance == 1 && 0 <= doubleR && doubleR < m){
                    if (0 <= doubleC && doubleC < n && !visited[doubleR][doubleC][0]){
                        visited[doubleR][doubleC][0] = true;
                        queue.offer(new Node(doubleR, doubleC, node.cnt+1, 0));
                    }
                }
            }
        }

        return -1;
    }
}

class Node{
    int r;
    int c;
    int cnt;
    int chance;

    public Node(int r, int c, int cnt, int chance){
        this.r = r;
        this.c = c;
        this.cnt = cnt;
        this.chance = chance;
    }
}