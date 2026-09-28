#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;

const int MAX_N = 500000;
const ll INF = (1LL << 60);

ll arr[MAX_N + 2];
ll tree[MAX_N * 4 + 10];

// lazy[n] = {a, b}
// x -> a*x + b
pair<ll, ll> lazy[MAX_N * 4 + 10];

int N;

ll init_tree(int n, int s, int e){

    lazy[n] = {1, 0};

    if(s == e)
        return tree[n] = arr[s];

    int m = (s + e) / 2;

    return tree[n] =
        max(init_tree(n*2, s, m),
            init_tree(n*2+1, m+1, e));
}

void update_lazy(int n, int s, int e){

    if(lazy[n].first == 1 && lazy[n].second == 0)
        return;

    ll a = lazy[n].first;
    ll b = lazy[n].second;

    tree[n] = tree[n] * a + b;

    if(s != e){

        lazy[n*2] = {
            lazy[n*2].first * a,
            lazy[n*2].second * a + b
        };

        lazy[n*2+1] = {
            lazy[n*2+1].first * a,
            lazy[n*2+1].second * a + b
        };
    }

    lazy[n] = {1, 0};
}

void update(int n, int s, int e,
            int l, int r, ll d1, ll d2){

    update_lazy(n, s, e);

    if(r < s || e < l)
        return;

    if(l <= s && e <= r){

        tree[n] = tree[n] * d1 + d2;

        if(s != e){

            lazy[n*2] = {
                lazy[n*2].first * d1,
                lazy[n*2].second * d1 + d2
            };

            lazy[n*2+1] = {
                lazy[n*2+1].first * d1,
                lazy[n*2+1].second * d1 + d2
            };
        }

        return;
    }

    int m = (s + e) / 2;

    update(n*2, s, m, l, r, d1, d2);
    update(n*2+1, m+1, e, l, r, d1, d2);

    tree[n] = max(tree[n*2], tree[n*2+1]);
}

ll query(int n, int s, int e,
         int l, int r){

    update_lazy(n, s, e);

    if(r < s || e < l)
        return -INF;

    if(l <= s && e <= r)
        return tree[n];

    int m = (s + e) / 2;

    return max(
        query(n*2, s, m, l, r),
        query(n*2+1, m+1, e, l, r)
    );
}

int query2(int n, int s, int e,
           int l, int r, ll x){

    update_lazy(n, s, e);

    if(r < s || e < l)
        return -1;

    if(tree[n] < x)
        return -1;

    if(s == e)
        return s;

    int m = (s + e) / 2;

    int ret = query2(n*2, s, m, l, r, x);

    if(ret != -1)
        return ret;

    return query2(n*2+1, m+1, e, l, r, x);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++){

        int M;
        cin >> N >> M;

        for(int i = 0; i < N; i++)
            cin >> arr[i];

        init_tree(1, 0, N-1);

        cout << "#" << tc << '\n';

        for(int i = 0; i < M; i++){

            int op;
            cin >> op;

            if(op == 1){

                int l, r;
                ll w;

                cin >> l >> r >> w;

                // +w
                update(1, 0, N-1, l, r, 1, w);
            }
            else if(op == 2){

                int l, r;
                ll v;

                cin >> l >> r >> v;

                // =v
                update(1, 0, N-1, l, r, 0, v);
            }
            else if(op == 3){

                int l, r;
                cin >> l >> r;

                cout << query(1, 0, N-1, l, r) << '\n';
            }
            else if(op == 4){

                int l, r;
                ll x;

                cin >> l >> r >> x;

                cout << query2(1, 0, N-1, l, r, x) << '\n';
            }
        }
    }

    return 0;
}