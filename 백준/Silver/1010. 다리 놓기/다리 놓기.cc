#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

using ll = unsigned long long;

ll bridge(int X, int Y)
{
    int N = X;
    int K = Y;
    if (K > N - K)
        K = N - K;
    ll i, j, m, n;
    if (K == 0)
        return 1;
    n = 1;
    m = 1;
    for (i = N; i > N - K; i--)
        m *= i;
    for (j = 1; j <= K; j++)
        n *= j;
    return m / n;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    ll testn, n, m;

    cin>> testn;

    while(testn--){
        cin>> n >> m;
        
        ll anw = bridge(m, n);
        cout<< anw << "\n";
    }

    
    return 0;
}


