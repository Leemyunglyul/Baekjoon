#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int arr[510][510];
int floyd[510][510];
int v, e;






int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
       cin>> v >> e;
       for(int i=1; i<=v; i++){
           for(int j=1; j<=v; j++){
               if(i==j) floyd[i][j] = 0;
               else floyd[i][j] = 1e9;
           }
       }
       for(int i=0; i<e; i++){
           int a, b, c;
           cin >> a >> b >> c;
           floyd[a][b] = min(floyd[a][b], c);
         }
             for(int k=1; k<=v; k++){
              for(int i=1; i<=v; i++){
                for(int j=1; j<=v; j++){
                     if(floyd[i][j] > floyd[i][k] + floyd[k][j]){
                          floyd[i][j] = floyd[i][k] + floyd[k][j];
                     }
                }
              }
            }
        

        cout << "#" << tc;
        for(int i=1; i<=v; i++){
            for(int j=1; j<=v; j++){
                if(floyd[i][j] == 1e9) cout << " -1";
                else cout << " " << floyd[i][j];
            }
            
        }

        cout << "\n";
    }

    return 0;
}