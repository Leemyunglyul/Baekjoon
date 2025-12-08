#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int arr[1024][1024];

int second(int a, int b, int c, int d){
    int m = min(min(a, b), min(c, d));

    if(a==m) return min(b, min(c, d));
    else if(b==m) return min(a, min(c, d));
    else if(c==m) return min(a, min(b, d));
    else return min(a, min(b, c));
}

int find(int r, int c, int s){
    if(s==2){
        return second(arr[r][c], arr[r][c+1], arr[r+1][c], arr[r+1][c+1]);
    }
    int mid = s/2;
    int a = find(r, c, mid);
    int b = find(r, c+mid, mid);
    int y = find(r+mid, c, mid);
    int d = find(r+mid, c+mid, mid);

    return second(a, b, y, d);
}


int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);
    
    int i, j, n;

    cin>>n;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    if(i==1) cout << arr[0][0] << "\n";
    else cout << find(0, 0, n) << "\n";

    return 0;
}


