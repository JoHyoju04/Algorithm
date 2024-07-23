import java.io.*;
import java.util.*;

public class Main {
    static int T;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        T = Integer.parseInt(br.readLine());
        for(int testCase=0;testCase<T;testCase++){
            long answer = 0;
            int N = Integer.parseInt(br.readLine());
            int[] stocks = new int[N];
            StringTokenizer st = new StringTokenizer(br.readLine()," ");
            for(int i=0;i<N;i++){
                stocks[i] = Integer.parseInt(st.nextToken());
            }
            int max = 0;
            for(int i = N-1;i>=0;i--){
                if(max<stocks[i])   max = stocks[i];
                else answer += max - stocks[i];
            }
            System.out.println(answer);

        }

    }
}