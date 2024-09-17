#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>


using namespace std;

map<string, int> arr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int testn, n;
    cin>>testn;
    string a, b;
    while(testn--){
        cin>>n;
        while(n--){
            cin>>a>>b;
            arr[b]++;
        }
        int sum=0;
        for(auto it=arr.begin();it!=arr.end();it++){
            if(sum==0) sum=it->second+1;
            else sum*=it->second+1;
        }
        cout<<max(sum-1,0)<<"\n";

        arr.clear();
    }
}
