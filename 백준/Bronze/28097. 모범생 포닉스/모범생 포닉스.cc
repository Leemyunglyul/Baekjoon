#include <iostream>
#include<math.h>
#include<map>
#include<stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, i, sum, x;
    cin >> n;
    for (i = 0, sum=0; i < n; i++) {
        cin >> x;
        sum += x;
    }
    sum += (n-1) * 8;
    cout << sum / 24 << " " << sum % 24;
}
