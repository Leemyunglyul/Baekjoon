#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long n, k, i, anw;
    cin>>n>>k;
    for(i=2, anw=1;i<=n;i++){
        anw=((anw+k-1)%i)+1;
    }
    cout<<anw;

}