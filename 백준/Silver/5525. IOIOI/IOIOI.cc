#include <iostream>



using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, sum, i, j, m, x;
    cin>>n>>m;
    string s;
    cin>>s;
    for(i=0, x=0 ,sum=0;i<m;i++){
        //even turn
        if(x%2==1){
            if(x==2*n+1){
                sum++;
                x-=2;
            }
            if(s[i]=='O') x++;
            else x=1;
        }
        //odd turn
        else{
            if(s[i]=='I') x++;
            else x=0;
        }
    }
    if(x==2*n+1) sum++;
    cout<<sum;
}
