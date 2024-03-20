#include <iostream>
#include<cmath>

using namespace std;

int hang[1000010];
int arr[4] = { 0 };

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int hn, up, down, i;
    cin >> hn;
    for (i = 1; i <= hn; i++) {
        cin >> hang[i];
        arr[hang[i]]++;
    }
    cin >> up >> down;
    if (up > arr[1] + arr[3] || down>arr[2]+arr[3]) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for (i = 1; i <= hn; i++) {
        if (hang[i] == 1) {
            up--;
            cout << "U";
        }
        else if (hang[i] == 2) {
            down--;
            cout << "D";
        }
        else {
            if (up > 0) {
                up--;
                cout << "U";
            }
            else {
                down--;
                cout << "D";
            }
        }
    }
}
