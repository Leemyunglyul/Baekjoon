#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <climits>
#include <unordered_map>
typedef long long ll;

using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, m, sum,t;
    sum=0;
    cin>>n;
    m=n;
    do{
        t=m;
        m=m%10+m/10;
        m=(t%10)*10+m%10;
        sum++;
        //cout<<m<<endl;
    }while(n!=m);
    cout<<sum;    
}
