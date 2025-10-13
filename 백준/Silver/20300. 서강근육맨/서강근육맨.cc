#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;


vector<long long> v;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    long long n, i, x, anw, j;
    cin >> n;

    for(i=0;i<n;i++){
        cin >>x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    anw = 0;

    if(n%2==1){
        anw = v[n-1];
        n--;
    }
    for(i = 0, j = n - 1;; i++, j--) {
        if(i<j){
            anw = max(anw, v[i] + v[j]);
        } else if( i == j ) {
            anw = max(anw, v[i]);
        } else {
            break;
        }
    }

    
    cout<<anw;

    return 0;

}