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

int arr[500001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, i, j;
    fill_n(&arr[0], 500001, 0);
    cin>>n;
    int sum=1;
    arr[1]=1;
    for(i=2;i<=n;i++){
        if(arr[i]>0) continue;
        sum++;
        arr[i]=sum;
        for(j=i*2;j<=n;j+=i){
            arr[j]=sum;
        }
    }
    
    cout<<sum<<"\n";
    for(i=1;i<=n;i++) cout<<arr[i]<<" ";
    
    return 0;
}