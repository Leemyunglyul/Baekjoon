#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, i, j;
    cin>>n;
    if(n==2) cout<<"NO";
    else{
        cout<<"YES\n";
        for(i=1;i<=n;i++){
            if(i==1) cout<<"1 ";
            else if(i==2) cout<<"3 ";
            else if(i==3) cout<<"2 ";
            else cout<<i<<" ";
        }
    }
    
}
