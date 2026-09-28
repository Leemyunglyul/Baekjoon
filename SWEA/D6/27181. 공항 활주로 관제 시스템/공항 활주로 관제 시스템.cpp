#include <cstdio>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

struct ap{
    int fid;
    int p;
    int u;
};


struct cmp4{
    bool operator()(const ap& x, const ap& y) const{
        if(x.u == y.u) return x.p > y.p;
        return x.u < y.u;
    }
};

struct cmp5{
    bool operator()(const ap& x, const ap& y) const{
        if(x.u == y.u) return x.p < y.p;
        return x.u > y.u;
    }
};

std::map<int, ap> arr;
int num = 1;

std::priority_queue<ap, std::vector<ap>, cmp4> pq4;
std::priority_queue<ap, std::vector<ap>, cmp5> pq5;

bool valid(ap x, ap y){
    return  x.p == y.p && x.u == y.u;
}

void init(int P, const int fids[], const int urg[])
{

    int i;

    while(!pq4.empty()) pq4.pop();
    while(!pq5.empty()) pq5.pop();
    arr.clear();

    for(i=0;i<P;i++){
        arr.insert({fids[i], {fids[i], num, urg[i]}});
        pq4.push({fids[i], num, urg[i]});
        pq5.push({fids[i], num++, urg[i]});
    }


}

void request(int fid, int u)
{

    arr.insert({fid, {fid, num, u}});
    pq4.push({fid, num, u});
    pq5.push({fid, num++, u});
}

void renew(int fid, int u)
{

    int nn = arr[fid].p;
    arr[fid] = {fid, nn, u};
    pq4.push({fid, nn, u});
    pq5.push({fid, nn, u});
}

void cancel(int fid)
{

    arr.erase(fid);
}

int clear_landing()
{

    while(!pq4.empty() && (arr.find(pq4.top().fid) == arr.end() || 
                !valid(pq4.top(), arr[pq4.top().fid] ))) pq4.pop();

    if(pq4.empty()) return -1;
    
    ap x = pq4.top();
    arr.erase(x.fid);
    pq4.pop();

    return x.fid;
}

int divert()
{
    while(!pq5.empty() && (arr.find(pq5.top().fid) == arr.end() || 
                !valid(pq5.top(), arr[pq5.top().fid] ))) pq5.pop();

    if(pq5.empty()) return -1;
    
    ap x = pq5.top();
    arr.erase(x.fid);
    pq5.pop();

    return x.fid;
}

#define MAX_P 60000
static int in_fids[MAX_P];
static int in_urg[MAX_P];
static char in_buf[32 << 20];
static char *in_p;

static int read_int()
{
    int v = 0;
    while (*in_p < '0' || *in_p > '9') in_p++;
    while (*in_p >= '0' && *in_p <= '9')
        v = v * 10 + (*in_p++ - '0');
    return v;
}

int main()
{
    int T, tc;
    size_t rd = fread(in_buf, 1, sizeof(in_buf) - 1, stdin);
    (void)rd;
    in_p = in_buf;
    T = read_int();
    for (tc = 1; tc <= T; tc++) {
        int P, M, i;
        P = read_int(); M = read_int();
        for (i = 0; i < P; i++) {
            in_fids[i] = read_int();
            in_urg[i] = read_int();
        }
        init(P, in_fids, in_urg);
        printf("#%d\n", tc);
        while (M--) {
            int op = read_int();
            if (op == 1) {
                int fid = read_int(), u = read_int();
                request(fid, u);
            } else if (op == 2) {
                int fid = read_int(), u = read_int();
                renew(fid, u);
            } else if (op == 3) {
                int fid = read_int();
                cancel(fid);
            } else if (op == 4) {
                printf("%d\n", clear_landing());
            } else {
                printf("%d\n", divert());
            }
        }
    }
    return 0;
}