import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int R;
    static List<Node>[] tree;
    static boolean[] visited;
    static int gigaNode;
    static int maxSumEdge =0;
    static int trunkLen = 0;

    static void getTrunk(int nodeNum){
        visited[nodeNum] = true;
        if(tree[nodeNum].size()>2 || (tree[nodeNum].size()==1 && nodeNum!=R) || (tree[nodeNum].size()>=2 && nodeNum==R)){
            gigaNode = nodeNum;
            return;
        }
        for(Node adj : tree[nodeNum]){
            if(!visited[adj.num]){
                trunkLen += adj.edge;
                getTrunk(adj.num);

            }
        }
    }

    static void getLongBranch(int nodeNum,int edgeSum){
        visited[nodeNum] = true;
        for(Node adj : tree[nodeNum]){
            if(!visited[adj.num]){
                getLongBranch(adj.num,edgeSum+ adj.edge);
            }
        }
        maxSumEdge = Math.max(maxSumEdge,edgeSum);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N= Integer.parseInt(st.nextToken());
        R=Integer.parseInt(st.nextToken());
        if(N==1){
            System.out.println("0 0");
            return;
        }
        tree = new ArrayList[N+1];
        for(int i=0;i<=N;i++)   tree[i] = new ArrayList<>();
        visited = new boolean[N+1];

        for(int i=0;i<N-1;i++){
            st = new StringTokenizer(br.readLine());
            int a=Integer.parseInt(st.nextToken());
            int b=Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            tree[a].add(new Node(b,d));
            tree[b].add(new Node(a,d));
        }
        getTrunk(R);
        getLongBranch(gigaNode,0);
        System.out.println(trunkLen+" "+maxSumEdge);


    }
}
class Node{
    int num;
    int edge;

    public Node(int num,int edge){
        this.num = num;
        this.edge = edge;
    }
}