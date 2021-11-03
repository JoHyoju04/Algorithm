#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for(long long i=left;i<=right;i++){
        long long r=i/n+1,c=i%n+1;
        if(c<=r)    answer.push_back(r);
        else answer.push_back(c);
    }
    return answer;
}