#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

int arr[10100];
int in[101000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k, i, j, x,y ;
    cin>>n>>k;
    for(i=1;i<=n;i++){
        cin>>in[i];
        arr[in[i]]++;
    }
    while(k--){
        cin>>x>>y;
        if(x==1){
            if(y==0){
                if(arr[0]>0 && n>1) cout<<"1\n";
                else cout<<"0\n";
                continue;
            }
            bool anw=false;
            for(i=1;i<=10000;i++){
                if(arr[i]==0) continue;
                int tmp=y/i;
                if(tmp<=0 || tmp>10000 || i*tmp!=y) continue;
                if(tmp==i){
                    if(arr[tmp]>=2){
                        anw=true;
                        break;
                    }
                    continue;
                }
                else if(arr[tmp]>0 && arr[i]>0){
                    anw=true; break;
                }
            }
            cout<<(int)anw<<"\n";
        }
        else{
            arr[in[y]]--;
            in[y]=0;
            arr[0]++;
        }
    }

}

/*
for(i=1;i<=n;i++){
        
}
*/