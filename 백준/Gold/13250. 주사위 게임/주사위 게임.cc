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

double arr[1000100];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, i, j;
    double x=0.1666666666666667;
    cin>>n;
    fill_n(&arr[0], 1000100,1);
    for(i=1;i<=n;i++){
        for(j=i-1;j>=i-6;j--){
            if(j<1) break;
            arr[i]+=arr[j]*x;
        }
    }
    cout.precision(12);
    cout<<arr[n];
}