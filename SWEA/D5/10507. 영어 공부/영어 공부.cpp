#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int n, m;

int arr[200100];


int solve() {
    int start= 1, end = 1;
    int n, i, j, k, bet, anw;
    
    bet=0;

    cin >> n >> k;

    for (i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    anw=1+k;

    while(end<=n){

        if(start==end){
            end++;
            if(end>n) break;
        }

        int diff = arr[end] - arr[end-1] - 1;

        bet += diff;

        if(bet>k){
            bet -= arr[start+1] - arr[start] -1;
            start++;
        }else{
            anw = max(anw, arr[end] - arr[start] + 1 + (k-bet));
            
        }
        end++;
        


    }

    return anw;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {

        cout << "#" << tc << " ";

        int result = solve();
        cout << result << '\n';
    }

    return 0;
}