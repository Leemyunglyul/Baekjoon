#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int solve(){
    int n, m, k, i, j;

    cin>>n>>m>>k;

    int anw = 0;

    while(1){
        if(n+m-3<k || n<2 || m<1){
            break;
        }
        n-=2;
        m-=1;

        anw++;

    }

    return anw;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {

        cout << "#" << tc << " " << solve()<< '\n';
    }

    return 0;
}