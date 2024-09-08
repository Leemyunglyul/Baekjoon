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


using namespace std;

priority_queue<int> big;
priority_queue<int, vector<int>, greater<int>> small;
map<int, int> arr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int m, n, i, j, y;
    char x;
    cin>>m;
    while(m--){
        while(!big.empty()) big.pop();
        while(!small.empty())small.pop();
        arr.clear();
        cin>>n;
        while(n--){
            cin>>x>>y;
            if(x=='I'){
                big.push(y);
                small.push(y);
                arr[y]++;
            }
            else{
                while(!small.empty() && arr[small.top()]==0){
                    small.pop();
                }
                while(!big.empty() && arr[big.top()]==0){
                    big.pop();
                }
                if(y==-1){
                    if(!small.empty()){
                        arr[small.top()]--;
                        small.pop();
                    }
                }
                else{
                    
                    if(!big.empty()){ 
                        arr[big.top()]--;
                        big.pop();
                    }
                }

            }
        }
        while(!small.empty() && arr[small.top()]==0){
                    small.pop();
                }
                while(!big.empty() && arr[big.top()]==0){
                    big.pop();
                }
        if(big.empty()||small.empty()) cout<<"EMPTY\n";
        else cout<<big.top()<<" "<<small.top()<<"\n";
    }
}

/*
for(i=1;i<=n;i++){
        
}
*/