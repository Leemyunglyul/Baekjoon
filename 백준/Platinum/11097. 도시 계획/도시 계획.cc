#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int arr[310][310];
int parent[310];
vector<int> strong[310];
set<pair<int, int>> edge;

int find(int x){
    if(parent[x]==x) return x;
    else return parent[x]=find(parent[x]);
}

void unionn(int x, int y){
    x=find(x);
    y=find(y);
    parent[x]=y;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int testn, n, i, j, k, l, a, b, c;
    char x;
    cin>>testn;
    while(testn--){
        cin>>n;
        edge.clear();
        for(i=1;i<=n;i++){
            parent[i]=i;
            for(j=1;j<=n;j++){
                cin>>x;
                arr[i][j]=x-48;
            }
        }
        for(i=1;i<=n;i++){
            strong[i].clear();
            for(j=i+1;j<=n;j++){
                if(arr[i][j]==1 && arr[j][i]==1){
                    unionn(i, j);
                }
            }
        }
        for(i=1;i<=n;i++){
            strong[find(i)].push_back(i);
        }
        for(i=1;i<=n;i++){
            if(strong[i].size()>=2){
                for(j=0;j<strong[i].size();j++){
                    if(j==strong[i].size()-1){
                        edge.insert({strong[i][j], strong[i][0]});
                    }
                    else{
                        edge.insert({strong[i][j], strong[i][j+1]});
                    }
                }
            }
        }
        
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(arr[i][j]==0 || find(i)==find(j)) continue;
                bool check=false;
                for(k=1;k<=n;k++){
                    if(find(i)==find(k) || find(j)==find(k) ) continue;
                    check|=arr[i][k]&&arr[k][j];
                }
                if(!check && edge.find({find(i), find(j)})==edge.end() ){ 
                    edge.insert({find(i), find(j)});
                }
            }
        }
    
        cout<<edge.size()<<"\n";
        for(auto it=edge.begin();it!=edge.end();it++){
            cout<<it->first<<" "<<it->second<<"\n";
        }
        cout<<"\n";
    }

}
