#include <string>
#include <vector>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(int i=0;i<numbers.size();i++){
        long long num=numbers[i];
        if(num%2==0){
            answer.push_back(num+1);
        }
        else{
            long long bit=1;
            while(1){
                if((num&bit)==0)  break;
                bit<<=1;
            }
            bit/=2;
            answer.push_back(num+bit);
        }
    }
    return answer;
}