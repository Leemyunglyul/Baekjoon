#include <iostream>
#include<math.h>
#include<algorithm>

using namespace std;

int arr[3010];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, i, now, x, least, qnum;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    sort(arr+1, arr + n+1);
    for (now = 1, least=0, qnum=-1; now<n; now++) {
        int temp = (arr[now] + arr[now + 1]) / 2;
        if (min(temp - arr[now], arr[now + 1] - temp) > least) {
            least=min(temp - arr[now], arr[now + 1] - temp);
            qnum = temp;
        }
    }
    cout << qnum;
}
