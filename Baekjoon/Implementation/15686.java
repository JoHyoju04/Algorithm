import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static int[][] graph;
    static ArrayList<int[]> house = new ArrayList<>();
    static ArrayList<int[]> chicken = new ArrayList<>();
    static ArrayList<int[]> selected = new ArrayList<>();
    static int result = Integer.MAX_VALUE;
    static boolean[] visited;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        graph = new int[N][N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < N; j++) {
                graph[i][j] = Integer.parseInt(st.nextToken());
                if (graph[i][j] == 1) {
                    house.add(new int[]{i, j}); // 집의 좌표 저장
                } else if (graph[i][j] == 2) {
                    chicken.add(new int[]{i, j}); // 치킨집의 좌표 저장
                }
            }
        }
        visited = new boolean[chicken.size()];

        back(0, 0);
        System.out.println(result); // 출력
    }

    static void back(int depth, int start) {
        if (depth == M) { // M개를 뽑아서 selected 리스트에 M개 저장이 끝났다면
            int sum = 0;
            for (int[] h : house) { // 모든 집들과 치킨집과의 최소거리를 계산
                int min = Integer.MAX_VALUE;
                for (int[] s : selected) { // 선택한 M개의 치킨집과 집의 거리를 계산해 최소거리를 구함
                    int d = Math.abs(h[0] - s[0]) + Math.abs(h[1] - s[1]);
                    min = Math.min(d, min);
                }
                sum += min; // 그렇게 구한 최소거리를 sum에 저장
            }
            result = Math.min(result, sum); // 그렇게 구한 sum들중에 최소값만 저장
            return;
        }

        for (int i = start; i < chicken.size(); i++) { // 모든 치킨집들을 탐색함
            if (!visited[i]) {
                visited[i] = true;
                selected.add(chicken.get(i));
                back(depth + 1, i + 1);
                selected.remove(selected.size() - 1);
                // 탐색이 끝났다면 리스트를 비우기 위한 로직
                // 배열로 했다면 덮어씌울수 있지만 리스트라 제거해줘야함
                visited[i] = false;
            }
        }
    }
}