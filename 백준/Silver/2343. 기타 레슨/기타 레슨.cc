#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <climits>
#include <unordered_map>
typedef long long ll;

using namespace std;

int arr[100100];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, i, j, k, avg, anw, big, sum, l, h;
    cin>>n>>k;
    for(i=1, sum=0, l=-1;i<=n;i++){
        cin>>arr[i];
        sum+=arr[i];
        l=max(arr[i], l);
    }
    h=sum;
    while(l<=h){
        int cnt=0;
        int tmp=0;
        int mid=(l+h)/2;
        for(i=1;i<=n;i++){
            if(tmp+arr[i]>mid){
                tmp=0;
                cnt++;
            }
            tmp+=arr[i];
            
        }
        if(tmp!=0)cnt++;
        if(cnt<=k){
            h=mid-1;
        }
        else l=mid+1;
    }
    cout<<l;
}