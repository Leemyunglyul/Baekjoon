#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, i, j, m;
    char c;
    cin>>n;
    while(n--){
        cin>>m>>c;
        while(m--){
            cout<<c;
        }
        cout<<"\n";
    }
}
