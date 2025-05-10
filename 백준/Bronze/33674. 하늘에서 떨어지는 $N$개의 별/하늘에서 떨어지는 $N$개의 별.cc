#include <iostream>
#include <string>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k, d, s, x, i, sum, a;
    cin>>n>>d>>k;
    for(i=1, s = 0;i<=n;i++){
        cin>>x;
        s=max(s, x);
    }
    for(i=1, sum= 0, a=0;i<=d;i++){
        sum += s;
        if(sum>k){
            a++;
            sum = s;
        }
    }
    cout<<a;
}