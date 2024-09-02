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

stack<int> st;
stack<int> list[110];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, i, j, k, x, y, z;
    cin>>n>>k;
    while(n--){
        cin>>x;
        if(x==1){
            cin>>y;
            st.push(y%k);
            list[y%k].push(st.size()-1);
        }
        else if(x==2){
            if(!st.empty()){
                list[st.top()].pop();
                st.pop();
            }
        }
        else{
            int idx=98765431;
            bool tmp=true;
            for(i=0;i<k;i++){
                
                if(list[i].empty()){
                    tmp=false;
                    break;
                }
                idx=min(idx, list[i].top());
            }
            if(!tmp){ 
                cout<<"-1\n";
                continue;
            }
            cout<<st.size()-1-(idx-1)<<"\n";
        }
    }
}