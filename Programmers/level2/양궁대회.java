class Solution {
    static int maxDiff = 0;
    static int[] maxRyan = new int[11];

    static void dfs(int depth,int n,int[] apeach,int[] ryan){
        if(depth==n){
            int apeachSum=0;
            int ryanSum=0;
            for(int i=0;i<11;i++){
                if(apeach[i]==0 && ryan[i]==0){
                    continue;
                }
                if(apeach[i]>=ryan[i]){
                    apeachSum+=10-i;
                }else{
                    ryanSum+=10-i;
                }
            }
            if(ryanSum<=apeachSum)  return;

            if(ryanSum - apeachSum > maxDiff){
                maxDiff = ryanSum - apeachSum;
                maxRyan = ryan.clone();
            }
            else if(ryanSum - apeachSum == maxDiff){
                for(int i=10;i>=0;i--){
                    if(maxRyan[i]<ryan[i]){
                        maxRyan = ryan.clone();
                        break;
                    }else if(maxRyan[i]>ryan[i]){
                        break;
                    }
                }
            }

            return;
        }
        for(int i=0;i<=10;i++){
            if(ryan[i]>apeach[i]) break;
            ryan[i]+=1;
            dfs(depth+1,n,apeach,ryan);
            ryan[i]-=1;
        }
    }
    public int[] solution(int n, int[] info) {
        int[] answer = {};
        int[] ryan = new int[11];
        dfs(0,n,info,ryan);

        int sum=0;
        for(int i=0;i<11;i++){
            sum+=maxRyan[i];
        }
        if(sum==0){
            answer=new int[]{-1};
        }else{
            answer=maxRyan.clone();
        }
        return answer;
    }
}