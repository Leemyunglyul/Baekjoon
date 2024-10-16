#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <climits>
#include <unordered_map>
typedef long long ll;

using namespace std;

int arr[20000];
int num[20000];
set<int> st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, testn, i, j, k, stop, a, b, x, idx;
    cin>>testn;
    while(testn--){
        cin>>a>>b;
        x=a/b;
        a=a%b;
        idx=0;
        while(1){
            if(st.find(a)!=st.end())break;
            st.insert(a);
            num[++idx]=a;
            a*=10;
            arr[idx]=a/b;
            a=a%b;
        }
        cout<<x<<".";
        for(i=1;i<=idx;i++){
            if(num[i]==a) {
                stop=i;
                break;
            }
            cout<<arr[i];
        }
        cout<<"(";
        for(i=stop;i<=idx;i++){
            cout<<arr[i];
        }
        cout<<")\n";
        st.clear();
    }
}