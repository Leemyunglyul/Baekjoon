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
long long tmp[3];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, i, j;
    cin>>n;
    for(i=1;i<=n;i++) cin>>arr[i];
    for(i=1;i<=n;i++){
        sum[i]=sum[i-1]+arr[i];
    }
    int x=sum[n];
    if(x%4!=0){
        cout<<"0";
        return 0;
    }
    int list[4]={x/4, x/2, x/4*3, x};
    /*for(auto i: list){
        cout<<i<<" ";
    }cout<<endl;*/
    for(i=1;i<n;i++){
        //for(j=0;j<=2;j++) num[i][j]=num[i-1][j];
        //num[i][0]=num[i-1][0];
        /*if(sum[i]==list[3]){
            //anw+=num[i][2];
            anw+=tmp[2];
        }*/
        if(sum[i]==list[2]){
            //num[i][2]+=num[i-1][1];
            tmp[2]+=tmp[1];
        }
        if(sum[i]==list[1]){
           // num[i][1]+=num[i-1][0];
            tmp[1]+=tmp[0];
        }
        if(sum[i]==list[0]){
            //num[i][0]++;
            tmp[0]++;
        }
        /*cout<<i<<" th gogo: ";
        for(j=0;j<=2;j++){
            cout<<tmp[j]<<" ";
        }
        cout<<endl;*/
    }
    cout<<tmp[2];

    return 0;
}