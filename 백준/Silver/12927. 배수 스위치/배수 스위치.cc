#include <iostream>
#include <string>


using namespace std;

bool arr[1010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int i, j, sum;
    string x;
    cin>>x;
    for(i=0;i<x.size();i++) arr[i+1]=(x[i]=='Y');
    
    for(i=1,sum=0;i<x.size()+1;i++){
        if(arr[i]){
            for(j=i;j<x.size()+1;j+=i){
                arr[j] = (1- arr[j]);
            }
            sum++;
        }
    }
    cout << sum;
}