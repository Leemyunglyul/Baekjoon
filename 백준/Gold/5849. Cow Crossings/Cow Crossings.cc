#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <stack>

using namespace std;

vector<pair<int,int>> arr;
stack<pair<int,int>> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j, x, y, lim;
    cin >> n;
    for (i = 0; i < n; i++){
        cin >> x >> y;
        arr.push_back({x, y});
    }
    sort(arr.begin(), arr.end());

    for (i = 0, lim=-1e6-1; i < n; i++){
        bool check=true;
        lim = max(lim, arr[i].second);
        while (!st.empty() && st.top().second > arr[i].second){
            st.pop();
            check=false;
        }
        if(check && lim <= arr[i].second) st.push(arr[i]);
    }

    cout << st.size() << "\n";
    

    return 0;
}