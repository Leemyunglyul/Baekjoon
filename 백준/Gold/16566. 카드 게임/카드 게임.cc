#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <stack>
#include <map>

using namespace std;

int parent[4000050];
int arr[4000050];
int test[10050];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unionn(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px != py) {
        parent[py] = px;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j, m, k, x, y;
    cin >> n >> m >> k;
    for(i = 1; i <= m; i++) {
        cin>>arr[i];
    }
    sort(arr + 1, arr + m + 1);
    for(i=1,x=0;i<=m;i++){
        for(j=x;j<arr[i];j++){
            parent[j]=arr[i]-1;
        }
        x=arr[i];
    } 
    for(i=1;i<=k;i++){
        cin>>test[i];
    }
    for(i=1;i<=k;i++){
        x=find(test[i]);
        cout<<x+1<<"\n";
        unionn(x+1, x);
    }   
    
    return 0;
}