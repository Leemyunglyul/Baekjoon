#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int n, m;

struct cats{
    int x;
    int y;
    int c;
};

struct rice{
    int p;
    int sum;
    bool y;
};

cats cat[1010];
rice arr[1010];

vector<cats> hole[1010];

int prv[1010];
int nextt[1010];
priority_queue<pair<int, int>> pq;

bool cmp(rice a, rice b){
    return a.p < b.p;
}

int dist(int a, int b, int c, int d){
    return (a-c)*(a-c)+(b-d)*(b-d);
}

void del(int idx){
    int l = prv[idx];
    int r = nextt[idx];

    if(l >= 1) nextt[l] = r;
    if(r <= m) prv[r] = l;

    arr[idx].y = false;

    if(l == 0){
        arr[r].sum += arr[idx].sum;

        for(int i=0;i<hole[idx].size();i++){
            hole[r].push_back(hole[idx][i]);
        }

        pq.push({arr[r].sum, r});

    } else if(r == m+1){
        arr[l].sum += arr[idx].sum;

        for(int i=0;i<hole[idx].size();i++){
            hole[l].push_back(hole[idx][i]);
        }

        pq.push({arr[l].sum, l});

    } else{
        for(int i=0;i<hole[idx].size();i++){
            cats now = hole[idx][i];

            int ld = dist(now.x, now.y, arr[l].p, 0);
            int rd = dist(now.x, now.y, arr[r].p, 0);

            // 거리가 같으면 왼쪽 배식구로 이동
            if(ld <= rd){
                arr[l].sum += now.c;
                hole[l].push_back(now);
            } else{
                arr[r].sum += now.c;
                hole[r].push_back(now);
            }
        }

        pq.push({arr[l].sum, l});
        pq.push({arr[r].sum, r});
    }

    hole[idx].clear();
    arr[idx].sum = 0;
}

void solve(){
    cin>>n>>m;

    int i, j, x, y, c, a;

    while(!pq.empty()) pq.pop();

    for(i=1;i<=m;i++){
        prv[i] = i-1;
        nextt[i] = i+1;
        hole[i].clear();
    }

    for(i=1;i<=n;i++){
        cin>>x>>y>>c;
        cat[i] = {x, y, c};
    }

    for(i=1;i<=m;i++){
        cin>>x;
        arr[i] = {x, 0, true};
    }

    // 인덱스 순서가 좌표 순서가 되도록 정렬
    sort(arr+1, arr+m+1, cmp);

    for(i=1;i<=n;i++){
        x = cat[i].x;
        y = cat[i].y;

        int anwx = 100010;
        int anwd = 987654321;
        int idx = 1;

        for(j=1;j<=m;j++){
            a = arr[j].p;
            int d = dist(x, y, a, 0);

            if(d < anwd){
                idx = j;
                anwd = d;
                anwx = a;
            } else if(d == anwd && a < anwx){
                anwd = d;
                anwx = a;
                idx = j;
            }
        }

        arr[idx].sum += cat[i].c;
        hole[idx].push_back(cat[i]);
    }

    for(i=1;i<=m;i++){
        pq.push({arr[i].sum, i});
    }

    int anw = 987654321;
    int remain = m;

    while(!pq.empty()){
        int sum = pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        // 삭제된 배식구 또는 갱신 전 정보는 무시
        if(!arr[idx].y || sum != arr[idx].sum) continue;

        // 현재 상태의 최댓값으로 정답 갱신
        anw = min(anw, sum);

        // 최소 하나의 배식구는 남겨둔다.
        if(remain == 1) break;

        del(idx);
        remain--;
    }

    cout<<anw<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;

    for(int tc=1;tc<=T;tc++){
        cout<<"#"<<tc<<" ";
        solve();
    }

    return 0;
}