#include <iostream>
#include<math.h>
#include<map>
#include<stack>

using namespace std;

int arr[200100];
int big[200100];
stack<pair<int, int>> st;
map<int, int> list;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int testn, n, i;
    string print;
    cin >> testn;
    while (testn--) {
        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> arr[i];
            list[arr[i]] = 0;
            big[i] = 0;
        }
        for (i = 1, print="Yes"; i <= n; i++) {
            while (!st.empty() && st.top().first < arr[i]) {
                int pos = st.top().second;
                big[pos] = arr[i];
                st.pop();
            }
            st.push({ arr[i], i });
            if (list[arr[i]] == 0) {
                list[arr[i]] = i;
            }
            else {
                if (big[list[arr[i]]] > 0) {
                    print = "No";
                    break;
                }
            }
        }
        cout << print<<"\n";
        while (!st.empty()) st.pop();
        list.clear();
    }
}
