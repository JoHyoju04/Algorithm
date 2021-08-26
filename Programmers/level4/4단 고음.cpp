#include <cmath>
using namespace std;
int answer; 
void cal(int add, int n) { 
    if(pow(3, add/2)>n) 
        return; 
    if(n==3) { 
        if(add==2) { 
            answer++; 
        } 
    } else if(n>3) { 
        if(add>=2 && n%3==0) 
            cal(add-2, n/3); 
        cal(add+1, n-1); 
    } 
} 
int solution(int n) { 
    answer = 0; 
    cal(0,n); 
    return answer; 
}