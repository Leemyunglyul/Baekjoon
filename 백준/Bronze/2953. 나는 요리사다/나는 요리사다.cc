#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <set>
#include <algorithm>
#include <string>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, t1, t2, i, x, j;
    t1=0;t2=0;
    for(j=1;j<=5;j++){
        int sum=0;
        for(i=1;i<=4;i++){ 
            cin>>x;
            sum+=x;
        }
        if(sum>t2){
            t2=sum;
            t1=j;
        }
    }
    cout<<t1<<" "<<t2;
}