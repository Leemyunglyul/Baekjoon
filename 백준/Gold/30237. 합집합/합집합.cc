#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


        int arr[60];
        int temp[60];
        vector<int> dict[60];
        int list[60][60];

int main(){
    ios_base::sync_with_stdio; cin.tie(NULL); cout.tie(NULL);
    
    int n, i, m, x, y, testn,j, anw, sum, k;
    cin>>testn;
    while(testn--){
        cin>>n;
        fill_n(&arr[0], 60, 0);
        fill_n(&temp[0], 60, 0);
        for(i=0;i<=59;i++) dict[i].clear();
        fill_n(&list[0][0], 60*60, 0);
        for(i=1;i<=n;i++){
            cin>>list[i][0];
            for(j=1;j<=list[i][0];j++){
                cin>>list[i][j];
                arr[list[i][j]]++;
                dict[list[i][j]].push_back(i);
            }
        }
        anw=0;
        for(i=1;i<=50;i++){
            if(arr[i]==0) continue;
            for(j=1;j<=50;j++){
                temp[j]=arr[j];
            }
            for(j=0;j<dict[i].size();j++){
                int d=dict[i][j];
                for(k=1;k<=list[d][0];k++){
                    temp[list[d][k]]--;
                }
            }
            sum=0;
            for(j=1;j<=50;j++){
                if(temp[j]>0){
                    sum++;
                }
            }
            anw=max(anw, sum);
        }
        cout<<anw<<"\n";
    }

    return 0;
}