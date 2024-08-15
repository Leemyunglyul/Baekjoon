#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr1;
vector<int> arr2;

int main(){
    ios_base::sync_with_stdio; cin.tie(NULL); cout.tie(NULL);
    
    int n, i, x, y;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>x>>y;
        int sum=x+y;
        if(sum%2==0){
            arr1.push_back(i);
        }
        else arr2.push_back(i);
    }
    if(arr1.empty()||arr2.empty()){
        cout<<"NO";
        return 0;
    }
    else cout<<"YES\n";
    for(i=0;i<arr1.size();i++){
        cout<<arr1[i]<<" ";
    }
    for(i=0;i<arr2.size();i++){
        cout<<arr2[i]<<" ";
    }

    return 0;
}