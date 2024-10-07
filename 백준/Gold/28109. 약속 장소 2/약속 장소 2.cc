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
#include <unordered_map>
typedef long long ll;

using namespace std;

int arr[110000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, i, j, k, sum, p;
    string s, t;
    cin>>n>>k>>s;
    
    sum=0;
    if(25*n+1<k){
        cout<<"-1";
        return 0;
    }
    p=0;
    while(p>=0){
        if(s[p]=='A' && arr[p+1]==0 && p+1<n){
            arr[p]++;
            p++;
            continue;
        }
        t=s;
        for(;arr[p]<26;arr[p]++){
            t[p]='A'+arr[p];
            if(t[p]==s[p] && arr[p+1]==0&& p+1<n){
                arr[p]++;
                p+=2;
                break;
            }
            sum++;
            //cout<<sum<<"th :"<<t<<"\n";
            if(sum==k){
                cout<<t;
                return 0;
            }
            
        }
        p--;
    }
    cout<<"-1";
}
