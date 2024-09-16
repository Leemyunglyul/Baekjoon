#include <iostream>

using namespace std;

int arr[110][110];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, i, j, k;
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            arr[i][j]|=arr[i][k]&&arr[k][j];
        }
    }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}
