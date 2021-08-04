#include <iostream>
#include <algorithm>
using namespace std;

int map[301][301];
int N,M,R;

int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

void rotate(int box){
    
    for(int i=0; i<box; i++){   
        int startVal = map[i][i];       
        int r = i;
        int c = i;
        
        int k = 0;
        while(k<4){
            
            int nr = r + dir[k][0];     
            int nc = c + dir[k][1];
            
            if(nr==i && nc==i) break;
            if(i<=nr && nr<N-i && i<=nc && nc<M-i){

                map[r][c] = map[nr][nc];
                r = nr;
                c = nc;
                
            }
            else{       
                k++;
            }
        }
        map[i+1][i] = startVal; 
     
    }
 
    
}


int main(){
    
    cin >> N >> M >> R;
        
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> map[i][j];
        }
    }
    
    int cnt = min(N,M)/2;       
    
    for(int i = 0; i<R; i++){      
        rotate(cnt);
    }

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cout << map[i][j] << " ";
        }cout <<"\n";
    }
    
    return 0;
}