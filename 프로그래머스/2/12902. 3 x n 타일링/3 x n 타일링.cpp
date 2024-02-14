#include <string>
#include <vector>

using namespace std;

long long int arr[5010]={0};
long long int sum[5010]={0};

int solution(int n) {
    int answer = 0;
    int i, j;
    arr[2]=3;
    arr[4]=11;
    for(i=6 ;i<=n;i+=2){
        arr[i]=(arr[i-2]*3)%1000000007;
        for(j=2;j<=i-4;j+=2){
            arr[i]=(arr[i]+arr[j]*2)%1000000007;
        }
        arr[i]+=2;
    }
    arr[n]%=1000000007;
    return arr[n];
}