#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;


queue<int> q;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int n, x, y, maxn, num;
    cin>>n;

    maxn = 0;
    num = 100001;

    while(n--) {
        cin>>x;

        if(x==1){
            cin>>y;
            q.push(y);

            if(q.size() > maxn) {
                maxn = q.size();
                num = q.back();
            } else if(q.size() == maxn) {
                num = min(num, q.back());
            }

        } else{
            if(!q.empty()) q.pop();
        }
    }
    cout<< maxn <<" "<< num <<"\n";
    return 0;

}