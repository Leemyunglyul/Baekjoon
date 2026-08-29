#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
//#include <bits/stdc++.h>

using namespace std;

int n, m;

int arr[12] = {0, 1, 4, 6, 8, 
    9, 10, 12, 14, 15, 
    16, 18};

long long comb(int n, int r) {
    if (r > n - r) r = n - r;

    long long ret = 1;
    for (int i = 1; i <= r; i++) {
        ret = ret * (n - i + 1) / i;
    }
    return ret;
}

double solve(){
    cin>> n >> m;

    double p1 = (double)n / 100;
    double p2 = (double)m / 100;

    double ans = 0;

    int i, j;

    for(i=0; i<12; i++){
        for(j=0; j<12; j++){
            int a = arr[i];
            int b = arr[j];
            ans += comb(18, a) * comb(18, b) * pow(p1, a) * pow(1-p1, 18-a) * pow(p2, b) * pow(1-p2, 18-b);
        }
    }

    return (1-ans);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {



        cout << "#" << tc;
        cout << " " << fixed << setprecision(6) << solve();
        cout << "\n";
    }

    return 0;
}