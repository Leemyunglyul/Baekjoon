#include <iostream>
#include <string>
#include <cmath>

using namespace std;


long long sum[1000100]= {0};
long long a[1000100]= {0};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long n, i, j, testn;

    cin >> n;

    for(i=1; i<=n; i++) {
        for(j=i; j<=n; j+=i) {
            sum[j]+=i;
        }
    }

    for(i=1; i<=1000000; i++) {
        a[i]=a[i-1]+sum[i];
    }

    cout << a[n] << "\n";

    return 0;

}