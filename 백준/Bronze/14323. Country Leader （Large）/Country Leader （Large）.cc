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

string arr[110];
bool sum[30];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, i, j, testn, num, now, anw, k, big;
    cin>>testn;
    for(i=1;i<=testn;i++){
        cin>>num;
        cin.ignore();
        for(j=1, anw=0, big=0;j<=num;j++){
            
            getline(cin, arr[j]);
           // cin.ignore();
            fill_n(&sum[0], 30, false);
            now=0;
            for(k=0;k<arr[j].size();k++){
                if(arr[j][k]<64 || arr[j][k]>90) continue;
                if(sum[arr[j][k]-65]);
                else{
                    sum[arr[j][k]-65]=true;
                    now++;
                } 
            }
            if(now>big){
                big=now;
                anw=j;
            }
            else if(now==big){
                if(arr[j]<arr[anw]){
                    big=now;
                    anw=j;
                }
            }
        }
        cout<<"Case #"<<i<<": "<<arr[anw]<<"\n";
    }
}