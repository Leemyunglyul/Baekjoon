#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <queue>
#include <tuple>

using namespace std;

int arr[100100];
int sum[100100];
long long num[100100][4];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, i, j;
    cin>>n;
    for(i=1;i<=n;i++) cin>>arr[i];
    for(i=1;i<=n;i++){
        sum[i]=sum[i-1]+arr[i];
    }
    int x=sum[n];
    if(x%4>0){
        cout<<"0";
        return 0;
    }
    int list[4]={x/4, x/2, x*3/4, x};
    for(i=1;i<=n;i++){
        for(j=0;j<=3;j++) num[i][j]=num[i-1][j];
        if(sum[i]==list[0]){
            num[i][0]++;
        }
        else if(sum[i]==list[1]){
            num[i][1]+=num[i][0];
        }
        else if(sum[i]==list[2]){
            num[i][2]+=num[i][1];
        }
        else if(sum[i]==list[3]){
            num[i][3]+=num[i][2];
        }
    }
    cout<<num[n][3];

    return 0;
}