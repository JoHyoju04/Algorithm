import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
public class Main {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        PriorityQueue<Integer> que = new PriorityQueue<>((o1,o2)->o2-o1);
        int N = Integer.parseInt(br.readLine());
        int dasom=Integer.parseInt(br.readLine());
        int answer=0;

        if(N==1){
            System.out.println(answer);
            return;
        }

        for(int i = 0 ; i < N-1; i++) {
            int num = Integer.parseInt(br.readLine());
            que.offer(num);
        }

        while(!que.isEmpty() && que.peek()>=dasom){
            dasom += 1;
            answer += 1;
            que.offer(que.poll()-1);
        }
        System.out.println(answer);
    }
//    public static void main(String[] args) throws IOException {
//        int N = Integer.parseInt(br.readLine());
//
//        Integer[] cnts = new Integer[N-1];
//        int dasom=0;
//        int answer=0;
//        if(N==1){
//            System.out.println(answer);
//            return;
//        }
//
//        for(int i = 0 ; i < N; i++) {
//            int num = Integer.parseInt(br.readLine());
//            if(i==0){
//                dasom=num;
//            }
//            else{
//                cnts[i-1]=num;
//            }
//        }
//        while(true){ //득표수
//            Arrays.sort(cnts,(i1,i2) -> i2 - i1); //시간복잡도 N
//            int maxNum=cnts[0];
//
//            if(maxNum<dasom)    break;
//
//            dasom += 1;
//            cnts[0] -=1;
//            answer+=1;
//        }
//        System.out.println(answer);
//    }
}