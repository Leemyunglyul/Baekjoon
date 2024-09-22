#include <iostream>

using namespace std;

int arr[10010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int sum=0;
    int n, i, j, a, b,m,x;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>arr[i];
        sum+=2*arr[i];
    }
    for(i=1;i<=n;i++){
        if(arr[i]<=arr[i+1]){
            if(arr[i+1]<=arr[i+2]){
                arr[i+1]-=arr[i];
                arr[i+2]-=arr[i];
                sum+=arr[i];
                arr[i]=0;
            }
            else{
                x=arr[i+1]-arr[i+2];
                arr[i+1]-=x;
                arr[i]-=x;
                sum+=x;
                if(arr[i]>0)i--;
            }
        }
        else{
            x=arr[i]-arr[i+1];
            arr[i]-=x;
            sum+=x;
            i--;
        }
    }
    
    cout<<sum;
}