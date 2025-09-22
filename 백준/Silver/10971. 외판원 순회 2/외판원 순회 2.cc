#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int num;
int anw = 987654321;

int arr[12][12];
bool visited[11];

void maker(int n, int cur, int idx){
    if(idx == num){
        if(arr[cur][0]==0){
            return;
        }
        anw=min(anw, n+arr[cur][0]);
        return;
    }

    for(int i=0; i<num; i++){
        if(visited[i]==true){
            continue;
        }
        if(arr[cur][i]==0){
            continue;
        }
        visited[i]=true;
        
        maker(n + arr[cur][i], i, idx+1);
        visited[i]=false;
    }
    
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    fill_n(visited, 11, false);
    
    cin>>num;

    for(int i=0; i<num; i++){
     for (int j = 0; j < num; j++ )
     {
        cin>>arr[i][j];
     }
     
    }
    visited[0] = true;
    maker(0, 0, 1);

    cout<<anw;

    return 0;
}