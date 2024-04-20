#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <map>

using namespace std;

int arr[110];
map<int, int> list;
vector<pair<int, int>> print;

void rev(int s, int e) {
    int i;
    int temp[110];
    for (i = s; i <= e; i++) temp[i] = arr[i];
    for (i = e; i >= s; i--) {
        arr[i] = temp[s + e - i];
        list[arr[i]] = i;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, i;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> arr[i];
        list.insert({ arr[i], i });
    }
    for (i = 1; i <= n; i++) {
        if (arr[i] == i) continue;
        int idx = list[i];
        print.push_back({ i, idx });
        rev(i, idx);
    }
    cout << print.size() << "\n";
    for (i = 0; i <print.size(); i++) {
        cout << print[i].first << " "<<print[i].second<<"\n";
    }
    return 0;
}