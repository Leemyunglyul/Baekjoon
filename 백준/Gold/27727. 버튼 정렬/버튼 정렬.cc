#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<long long, long long>> arr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long n, i,sum, k, x, a, b, p, lim;
    cin>>n;
    for(i=1, sum=0;i<=n;i++){
        cin>>x;
        arr.push_back({x, i});
    }
    cin>>k;
    sort(arr.begin(), arr.end());
    for(i=n-1, p=n-1;i>0;i--){
        a=arr[i].first;
        b=arr[i].second;
        if(b==i+1 && a>=arr[i-1].first){
            p--;
            continue;
        }
        else break;
    }
    lim=arr[p].first;
    for(i=0;i<=p;i++){
        k-=lim-arr[i].first;
        if(k<0){
            cout<<"0";
            return 0;
        }
    }
    sum=(p>=1)?1:0;
    for(i=p+1;i<=n-1;i++){
        a=arr[i].first-arr[i-1].first;
        k-=a*i;
        if(k<0){
            cout<<sum;
            return 0;
        }
        sum+=a;
    }
    sum+=k/n;
    cout<<sum;
}