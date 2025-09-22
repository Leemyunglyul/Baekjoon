#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> arr;

string a;
bool visited[11];

void maker(int n, int idx){
    if(idx == a.size()){
        arr.push_back(n);
        return;
    }

    for(int i=0; i<a.size(); i++){
        if(visited[i]==true){
            continue;
        }
        if(idx==0 && a[i]=='0'){
            continue;
        }
        visited[i]=true;
        maker(n*10 + (a[i]-'0'), idx+1);
        visited[i]=false;
    }
    
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    
    int x, anw;

    cin>>a>>x;

    maker(0,0);

    sort(arr.begin(), arr.end());
        
    anw = -1;

    for(int i=0; i<arr.size(); i++){
        if(arr[i] >= x){
            break;
        }
        else anw = arr[i];
    }
    cout<<anw;

    return 0;
}