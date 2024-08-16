#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[3010][2];

int main(){
    ios_base::sync_with_stdio; cin.tie(NULL); cout.tie(NULL);
    
    int n, i, x, y;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>arr[i][0];
    }
    int anw=0;
    for(i=1;i<=n;i++){
        cin>>arr[i][1];
        if(arr[i][1]<arr[i][0]){
            arr[i][1]=arr[i][0];
        }
        anw=max(anw, arr[i][0]+arr[i][1]);
    }
    cout<<anw;

    return 0;
}