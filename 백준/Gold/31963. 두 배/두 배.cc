#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

int arr[300000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, i, j;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>arr[i];
    }
    int sum=0;
    for(i=2;i<=n;i++){
        if(arr[i-1]>arr[i]){
            double x=ceil(log((double)arr[i-1]/arr[i])/log(2));
            arr[i]*=pow(2, x);
            sum+=x;
        }
    }
    cout<<sum;
}

/*
for(i=1;i<=n;i++){
        
}
*/