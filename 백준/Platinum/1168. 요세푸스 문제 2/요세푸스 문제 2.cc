#include <iostream>
#include <vector>

using namespace std;

long long segt[410000];

long long init(int node, int st, int end){
    if(st == end) return segt[node] = 1; // 각 리프 노드에 1을 저장 (사람이 1명 존재)
    int mid = (st + end) / 2;
    return segt[node] = init(node * 2, st, mid) + init(node * 2 + 1, mid + 1, end);
}

void update(int n, int st, int end, int t){
    if(t < st || t > end) return; 
    segt[n]--;

    if(st == end) return;
    int mid = (st + end) / 2;
    update(n * 2, st, mid, t);
    update(n * 2 + 1, mid + 1, end, t);
}

long long find(int n, int st, int end, int x){
    if(st == end) return st;

    int mid = (st + end) / 2;
    if(segt[n * 2] >= x) return find(n * 2, st, mid, x);
    else return find(n * 2 + 1, mid + 1, end, x - segt[n * 2]);
}

vector<long long> print;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long n, k;
    cin >> n >> k;
    
    init(1, 1, n); // 세그먼트 트리 초기화
    
    long long t = k; // 처음 시작할 사람의 위치는 k
    for(long long i = 1; i <= n; i++){
        // 현재 t번째 사람을 찾고 그 사람을 제거
        long long x = find(1, 1, n, t);
        update(1, 1, n, x);
        print.push_back(x);

        // 남은 사람 수가 있는지 확인
        if(segt[1] > 0) {
            // t를 다음 제거할 위치로 업데이트
            t = (t + k - 1) % segt[1];
            if(t == 0) t = segt[1]; // 남은 사람 수를 넘어가면 다시 처음으로 돌아옴
        }
    }

    // 결과 출력
    cout << "<";
    for(long long i = 0; i < print.size(); i++){
        if(i < n - 1) cout << print[i] << ", ";
        else cout << print[i] << ">";
    }
    cout << "\n";

    return 0;
}
