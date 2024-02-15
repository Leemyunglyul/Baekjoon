#include <string>
#include <vector>

using namespace std;

vector<int> sum;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int i, start, end, j, len;
    int n=sequence.size();
    sum.push_back(0);
    for(i=1;i<=n;i++){
        if(i==0) sum.push_back(sequence[i-1]);
        else sum.push_back(sequence[i-1]+sum[i-1]);
    }
    start=0;
    end=1;
    len=2*n;
    while(start<=end && start<n && end<=n){
        while(end<=n && sum[end]-sum[start]<k) end++;
        while(start<end && sum[end]-sum[start]>k) start++;
        if(sum[end]-sum[start]==k){
            if(len>end-start){
                len=end-start;
                answer.clear();
                answer.push_back(start);
                answer.push_back(end-1);
            }
        }
        end++;
    }
    return answer;
}