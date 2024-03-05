#include <iostream>
#include<math.h>
#include<stack>

using namespace std;

stack<int> s1;
stack<int> s2;
stack<int> s3;
stack<int> s4;

int arr[100100], n;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    int i;
    for (i = 0; i < n; i++) cin >> arr[i];
    for (i = 0; i < n; i++) {
        if (s1.empty() || (s1.top() < arr[i])) {
            s1.push(arr[i]);
        }
        else if (s2.empty() || (s2.top() < arr[i])) {
            s2.push(arr[i]);
        }
        else if (s3.empty() || (s3.top() < arr[i])) {
            s3.push(arr[i]);
        }
        else if (s4.empty() || (s4.top() < arr[i])) {
            s4.push(arr[i]);
        }
        else break;
    }
    if (i == n) cout << "YES";
    else cout << "NO";
}
