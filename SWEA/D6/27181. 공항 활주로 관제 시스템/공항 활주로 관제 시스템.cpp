#include <cstdio>
#include <queue>
#include <vector>
#include <unordered_map>

struct ap{
    int fid;
    int p;
    int u;
    int ver;
};

struct cmp4{
    bool operator()(const ap& x, const ap& y) const{
        if(x.u != y.u) return x.u < y.u;
        return x.p > y.p;
    }
};

struct cmp5{
    bool operator()(const ap& x, const ap& y) const{
        if(x.u != y.u) return x.u > y.u;
        return x.p < y.p;
    }
};

std::unordered_map<int, ap> arr;

std::priority_queue<ap, std::vector<ap>, cmp4> pq4;
std::priority_queue<ap, std::vector<ap>, cmp5> pq5;

int num;
int version_num;

bool valid(const ap& x)
{
    auto it = arr.find(x.fid);

    if(it == arr.end()) return false;

    return it->second.ver == x.ver;
}

void init(int P, const int fids[], const int urg[])
{
    arr.clear();

    pq4 = decltype(pq4)();
    pq5 = decltype(pq5)();

    num = 1;
    version_num = 1;

    arr.reserve(P * 2 + 100);
    arr.max_load_factor(0.7f);

    for(int i = 0; i < P; i++){
        ap x = {fids[i], num++, urg[i], version_num++};

        arr.emplace(x.fid, x);

        pq4.push(x);
        pq5.push(x);
    }
}

void request(int fid, int u)
{
    ap x = {fid, num++, u, version_num++};

    arr.emplace(fid, x);

    pq4.push(x);
    pq5.push(x);
}

void renew(int fid, int u)
{
    auto it = arr.find(fid);

    it->second.u = u;
    it->second.ver = version_num++;

    ap x = it->second;

    pq4.push(x);
    pq5.push(x);
}

void cancel(int fid)
{
    arr.erase(fid);
}

int clear_landing()
{
    while(!pq4.empty() && !valid(pq4.top())){
        pq4.pop();
    }

    if(pq4.empty()) return -1;

    int fid = pq4.top().fid;

    pq4.pop();
    arr.erase(fid);

    return fid;
}

int divert()
{
    while(!pq5.empty() && !valid(pq5.top())){
        pq5.pop();
    }

    if(pq5.empty()) return -1;

    int fid = pq5.top().fid;

    pq5.pop();
    arr.erase(fid);

    return fid;
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