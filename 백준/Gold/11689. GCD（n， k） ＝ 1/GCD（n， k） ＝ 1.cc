#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <map>

using namespace std;

vector<long long> v;

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long n, i, m, k;
    cin >> n;
    m = n;
    double lim = sqrt(n);
    for (i = 2; i <= int(lim); i++) {
       // cout << n << endl;
        if (n % i == 0) {
            v.push_back(i);
        }
        
        while (n % i == 0) {
            n /= i;
        }
    }
    if(n>1) v.push_back(n);
    
    for (i = 0; i < v.size(); i++) {
        m = m / v[i] * (v[i] - 1) ;
    }
    cout << m;

    return 0;
}