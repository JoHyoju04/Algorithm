import java.io.*;
import java.util.*;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    public static int N, M;
    public static int[] parent;
    public static int[] depth;
    public static boolean[] visited;
    public static ArrayList<Integer>[] adjs;

    public static void pro() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        parent = new int[N+1];
        depth = new int[N+1];
        visited = new boolean[N+1];
        adjs = new ArrayList[N+1];
        for(int i = 0; i <= N; i++) adjs[i] = new ArrayList<Integer>();

        for(int i = 0; i < N-1; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n1 = Integer.parseInt(st.nextToken());
            int n2 = Integer.parseInt(st.nextToken());
            adjs[n1].add(n2);
            adjs[n2].add(n1);
        }

        // dfs로 parent, depth 업데이트 하기
        // root, depth
        depth[1] = 1;
        parent[1] = -1;
        visited[1] = true;
        dfs(1);

        M = Integer.parseInt(br.readLine());
        for(int i = 0; i < M; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            System.out.println(findLCA(a, b));
        }

    }

    public static int findLCA(int a, int b){
        // depth를 비교
        while(depth[a] > depth[b]){
            // a의 depth가 더 크다면 a의 parent depth로 다시 비교
            // depth가 같아질 때까지 반복
            a = parent[a];
        }
        while(depth[b] > depth[a]){
            b = parent[b];
        }

        // a 와 b의 depth가 같아졌다면
        // 차례대로 올라가면서 공통조상을 찾는다
        while(a != b){
            a = parent[a];
            b = parent[b];
        }
        return a;
//        if(a==b) return a;
//        if(parent[a] != parent[b])
//            return findLCA(parent[a],parent[b]);
//
//        return parent[a];
    }

    public static void dfs(int node){
        for(int adj : adjs[node]){
            if(visited[adj]) continue;
            visited[node] = true;
            depth[adj] = depth[node]+1;
            parent[adj] = node;
            dfs(adj);
        }
    }

    public static void main(String[] args) throws Exception {
        pro();
    }

}