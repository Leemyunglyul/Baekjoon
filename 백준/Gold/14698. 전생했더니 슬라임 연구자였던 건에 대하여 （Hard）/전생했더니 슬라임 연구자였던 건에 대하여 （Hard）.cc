#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

const long long mod = 1e9+7;

priority_queue<long long, vector<long long>, greater<long long>> pq;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    long long testn, i, n, x, anw, y;

    cin >>testn;
    
    while(testn--){
        cin>> n;
        anw = 1;
        for(i=0;i<n;i++){
            cin>>x;
            pq.push(x);
        }

        while(pq.size()>1){
            x = pq.top();
            pq.pop();
            y= pq.top();
            pq.pop();
            long long b = (x*y);
            pq.push(b);
            anw = ((anw%mod) *(b%mod))%mod;   
        }
        anw = anw % mod;

        cout << anw<<"\n";

        pq.pop();
    }
    
    return 0;
}