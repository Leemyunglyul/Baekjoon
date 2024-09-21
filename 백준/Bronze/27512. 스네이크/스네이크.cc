#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin>>n>>m; 
    if(n*m%2==0) cout<<n*m;
    else cout<<n*m-1;
}