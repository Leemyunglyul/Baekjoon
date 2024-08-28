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

bool stop[1010];
int sig[1010][2];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fill_n(&stop[0], 1010, false);
    int n, i, j,k, x, sum , t;
    cin>>n>>k;
    for(i=1;i<=n;i++){
        cin>>x;
        stop[x]=true;
        cin>>sig[x][0]>>sig[x][1];
    }
    sum=1;
    for(i=1;i<=k-1;i++){
        if(!stop[i]){
            sum++;
            continue;
        }
        int a=sig[i][0];
        int b=sig[i][1];
        if((sum%(a+b))<a){
            sum+=a-(sum%(a+b))+1;
        }
        else sum++;
    }
    cout<<sum;
}