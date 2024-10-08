#include <iostream>
typedef long long ll;

using namespace std;

ll root=1;
ll n;

inline ll ssum(ll x, ll y){return (x+y)*(y-x+1)/2;} 

ll sub(ll l, ll r){
    if(l<=n && n<=r) return ssum(l, n);
    else if(l>n) return 0;
    else return ssum(l, r)+sub(l*2, r*2+1);

}

bool check(ll l, ll r){
    if(l<=root && root<=r) return true;
    else if(l>root) return false;
    else return check(l*2, r*2+1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    ll q, x,y, tot;
    cin>>n>>q;
    tot=1+sub(2,3);
    while(q--){
        cin>>x>>y;
        if(x==1) root=y;
        else{
            if(y==root) cout<<tot<<"\n";
            else if(check(4*y, 4*y+1) || 2*y==root)
                cout<<tot-sub(4*y, 4*y+1)-2*y<<"\n";
            else if(check((y*2+1)*2, (y*2+1)*2+1) || 2*y+1==root)
                cout<<tot-sub((y*2+1)*2, (y*2+1)*2+1)-(2*y+1)<<"\n";
            else cout<<y+sub(2*y, 2*y+1)<<"\n";
        }
    }  
    
}
