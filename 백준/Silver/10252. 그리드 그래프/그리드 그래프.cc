#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testn, n, m, i, j;
    
    cin >> testn;

    while(testn--){
        cin>>m>>n;

        cout<<"1\n";
        if(m%2==0){
            for(i=0; i<m; i++){
                if(i%2==0){
                    for(j=0; j<n; j++){
                        cout<<"("<<i<<","<<j<<")\n";
                    }
                } else {
                    for(j=n-1; j>=0; j--){
                        cout<<"("<<i<<","<<j<<")\n";
                    }
                }   
            }
        } else if(n % 2 == 0){
            for(j=0; j<n; j++){ 
                if(j%2==0){
                    for(i=0; i<m; i++){
                        cout<<"("<<i<<","<<j<<")\n";
                    }
                } else {
                    for(i=m-1; i>=0; i--){ 
                        cout<<"("<<i<<","<<j<<")\n";
                    }
                }   
            }
        }
        else {

            for(i=0; i<m; i++){
                cout<<"("<<i<<","<<n-1<<")\n"; 
            }
            for(i=n-2;i>=0;i--){
                cout<<"("<<m-1<<","<<i<<")\n";
            }
            for(i=0; i<n-1; i++){
                if(i%2==0){
                    for(j=0; j<m-1; j++){
                        cout<<"("<<j<<","<<i<<")\n";
                    }
                } else {
                    for(j=m-2; j>=0; j--){
                        cout<<"("<<j<<","<<i<<")\n";
                    }
                }   
            }
        }
    }

    return 0;
}