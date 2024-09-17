#include <iostream>
#include <map>


using namespace std;

map<string, string> arr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k;
    string a, b;
    cin>>n>>k;
    while(n--){
        cin>>a>>b;
        arr[a]=b;
    }
    while(k--){
        cin>>a;
        cout<<arr[a]<<"\n";
    }
}
