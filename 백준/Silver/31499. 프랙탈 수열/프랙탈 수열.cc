#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long n, i, k, x;
    cin>>n>>k;
    for(i=1, x=1;i<=n;i++) x=x*i%k;
    cout<<x;
}