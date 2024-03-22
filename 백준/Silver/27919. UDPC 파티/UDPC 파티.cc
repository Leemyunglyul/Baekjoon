#include <iostream>
#include<cmath>

using namespace std;

int arr[4];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string x;
    int n, i;
    cin >> x;
    for (i = 0; i < x.size(); i++) {
        if (x[i] == 'U') arr[0]++;
        else if (x[i] == 'D') arr[1]++;
        else if (x[i] == 'P') arr[2]++;
        else arr[3]++;
    }
    if (arr[0] + arr[3] > arr[1] && arr[0] + arr[1] + arr[3] > arr[2]) cout << "U";
    if (arr[1] > 0 || arr[2] > 0) cout << "DP";
}
