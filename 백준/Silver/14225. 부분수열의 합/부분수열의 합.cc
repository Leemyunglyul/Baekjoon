#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int arr[22];
bool visited[2000010];

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    fill_n(&visited[0], 2000010, false);
    int n, x, i, j;
    cin >> n;

    for(i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr,arr+n);

    if(arr[0] != 1){
        cout << "1";
        return 0;
    }

    for(i=0;i<n;i++){
        for(j=2000000;j>=1;j--){
            if(visited[j]){
                visited[j+arr[i]]= true;
                //cout<<j+arr[i]<<" ";
            }
        }
        visited[arr[i]]=true;
        //cout<<arr[i]<<" ";
    }

    for(i=1;i<=2000000;i++){
        if(!visited[i]){
            cout << i;
            break;
        }
    }

    return 0;
}