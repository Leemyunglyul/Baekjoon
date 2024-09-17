#include <iostream>
#include <cmath>

using namespace std;

int arr[110][110];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    fill_n(&arr[0][0], 110*110, 110);
    int n, m, i, j,k, x, y, sum;
    pair<int, int> a;
    cin>>n>>m;
    for(i=1;i<=m;i++){
        cin>>x>>y;
        arr[x][y]=1;
        arr[y][x]=1;
    }
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                arr[i][j]=min(arr[i][j], arr[i][k]+arr[k][j]);
            }
        }

    }
    for(i=1;i<=n;i++){
        for(j=1, sum=0;j<=n;j++){
            sum+=arr[i][j];
        }
        if(i==1) a={i, sum};
        else{
            if(a.second>sum) a={i, sum};
        }
    }
    cout<<a.first;
}
