#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int testn, n, i, j, x,y, anw, tmp;
    char a, b;
    cin>>testn;
    while(testn--){
        cin>>n;
        anw=2;
        tmp=0;
        while(n--){
            cin>>a>>x>>b>>y;
            for(i=0;i<=6;i++){
                if(!((1<<i)&anw))continue;
                if(a=='+'){
                    tmp|=(1<<((i+x)%7));
                }
                else{
                    tmp|=(1<<((i*x)%7));
                }
                if(b=='+'){
                    tmp|=(1<<((i+y)%7));
                }
                else{
                    tmp|=(1<<((i*y)%7));
                }
            }
            anw=tmp;
            tmp=0;
        }
        if(anw&1) cout<<"LUCKY\n";
        else cout<<"UNLUCKY\n";
    }
}
