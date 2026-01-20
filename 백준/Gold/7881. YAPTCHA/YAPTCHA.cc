#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

bool ass[3000010];
int arr[1000010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, i, j, x;
    fill_n(&ass[0], 3000010, true);
    for(i=2;i<3000010;i++)
        if(ass[i])
            for(j=i+i;j<3000010;j+=i)
                ass[j] = false;
    for(i=1;i<1000010;i++){
        arr[i] = arr[i-1];
        if(ass[3*i+7]){
            arr[i]++;
        }
    }

    cin>>n;
    while(n--){
        cin>>x;
        cout<<arr[x]<<"\n";
    }

    return 0;
}