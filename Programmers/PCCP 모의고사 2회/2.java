import java.util.PriorityQueue;

class Solution {
    public int solution(int[] ability, int number) {
        int answer = 0;
        PriorityQueue<Integer> pq=new PriorityQueue<>();

        for(int a:ability){
            pq.add(a);
        }

        for(int i=0;i<number;i++){
            int n1=pq.poll();
            int n2=pq.poll();
            pq.add(n1+n2);
            pq.add(n1+n2);
        }

        while(!pq.isEmpty()){
            answer += pq.poll();
        }
        return answer;
    }
}