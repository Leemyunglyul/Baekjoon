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

int arr[500010];
int sum[500010];
vector<int> anw;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, i, x;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>x;
        if(x<=0){
            arr[0]++;
            arr[-x+1]--;
        }
        else arr[x]++;
    }
    for(i=1, sum[0]=arr[0];i<=n;i++){
        sum[i]=arr[i]+sum[i-1];
    }
    for(i=0;i<=n;i++){
        if(i+sum[i]==n) anw.push_back(i);
    }
    cout<<anw.size()<<endl;
    for(i=0;i<anw.size();i++) cout<<anw[i]<<" ";


    return 0;
}