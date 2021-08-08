#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = 2,size=a.size();
    vector<int> left(size,0);
    vector<int> right(size,0);
    
    for(int i=0;i<size;i++){
        if(i==0)    left[i]=a[i];
        else if(left[i-1]>a[i]) left[i]=a[i];
        else left[i]=left[i-1];
    }
    
    for(int i=size-1;i>=0;i--){
        if(i==size-1)   right[i]=a[i];
        else if(right[i+1]>a[i])    right[i]=a[i];
        else right[i]=right[i+1];
    }
    
    for(int i=1;i<size-1;i++){
        if(left[i-1]>a[i]||right[i+1]>a[i]) answer++;
    }
    return answer;
}