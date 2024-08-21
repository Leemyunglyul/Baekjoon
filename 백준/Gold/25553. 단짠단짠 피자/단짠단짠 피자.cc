#include <iostream>
#include <cstdio>

using namespace std;

long long arr[200100];
long long sum[200100];
long long oe[200100][2];
long long n, k;

inline long long find(long long x){
    return x<=n-k+1? x+k-1 : x+k-1-n;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long i, j,q, x, y, odd, even, idx, anw, a1, a2, t1, t2;
    odd=0;
    even=0;
    long long small=-9876543218754320;
    fill_n(&sum[0], 200100, small);

    cin>>n>>q>>k;
    for(i=1;i<=n;i++) cin>>arr[i];
    for(i=1, sum[1]=0;i<=k;i++){
        sum[1]+=arr[i];
        if(i%2==1) oe[1][0]++;
        else oe[1][1]++; 

    }
    for(i=2;i<=n;i++){
        idx=find(i);
        sum[i]=sum[i-1]-arr[i-1]+arr[idx];

        oe[i][0]=oe[i-1][0];//홀
        oe[i][1]=oe[i-1][1];//짝
        if((i-1)%2==0) oe[i][1]--;
        else oe[i][0]--;
        if(idx%2==0) oe[i][1]++;
        else oe[i][0]++;
    }
    pair<long long, long long> p={oe[1][0], oe[1][1]};
    a1=1;
    a2=0;
    for(i=2;i<=n;i++){
        if(p.first==oe[i][0] && p.second==oe[i][1]){
            if(sum[i]>sum[a1]){
                a1=i;
            }
        }
        else{
            if(a2==0 || sum[i]>sum[a2]){
                a2=i;
            }
        }
    }
    while(q--){
            cin>>x;
            if(x==1){
                cin>>y;
                odd+=y;
            }
            else if(x==2){
                cin>>y;
                even+=y;
            }
            else{
                t1=sum[a1]+odd*oe[a1][0]+even*oe[a1][1];
                t2=sum[a2]+odd*oe[a2][0]+even*oe[a2][1];
                if(a2==0 || t1>t2 || (t1==t2 && a1<a2)){
                    cout<<a1<<" "<<t1<<"\n";
                }
                else{
                    cout<<a2<<" "<<t2<<"\n";
                }
            }
    }


    return 0;
}