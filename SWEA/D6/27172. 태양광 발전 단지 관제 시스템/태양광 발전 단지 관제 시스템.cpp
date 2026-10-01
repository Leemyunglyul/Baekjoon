#include <cstdio>

#define MAX_N 500

struct Point {
    int x, y;
};

struct Node {
    int value, x, y;
};

int n, k;
int arr[MAX_N][MAX_N];
int lazy[410];
Node top[410][5];
int topCnt[410];

int sector(int x, int y) {
    return (y / k) * (n / k) + x / k;
}

bool better(const Node& a, const Node& b) {
    if (a.value != b.value) return a.value > b.value;
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

bool insert(Node list[], int& size, int limit, Node cur) {
    if (size == limit && !better(cur, list[size - 1])) {
        return false;
    }

    int pos;

    if (size < limit) pos = size++;
    else pos = limit - 1;

    while (pos > 0 && better(cur, list[pos - 1])) {
        list[pos] = list[pos - 1];
        pos--;
    }

    list[pos] = cur;
    return true;
}

void rebuild(int sec) {
    int y1 = sec / (n / k) * k;
    int x1 = sec % (n / k) * k;

    topCnt[sec] = 0;

    for (int y = y1; y < y1 + k; y++) {
        for (int x = x1; x < x1 + k; x++) {
            insert(top[sec], topCnt[sec], 5, {arr[y][x], x, y});
        }
    }
}

void init(int N, int K, int graph[][MAX_N]) {
    n = N;
    k = K;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            arr[y][x] = graph[y][x];
        }
    }

    for (int sec = 0; sec < (n / k) * (n / k); sec++) {
        lazy[sec] = 0;
        rebuild(sec);
    }
}

void set(Point p, int value) {
    int sec = sector(p.x, p.y);
    int prev = arr[p.y][p.x];

    arr[p.y][p.x] = value - lazy[sec];

    if (prev == arr[p.y][p.x]) return;

    for (int i = 0; i < topCnt[sec]; i++) {
        if (top[sec][i].x != p.x || top[sec][i].y != p.y) {
            continue;
        }

        if (arr[p.y][p.x] < prev) {
            rebuild(sec);
            return;
        }

        for (int j = i; j + 1 < topCnt[sec]; j++) {
            top[sec][j] = top[sec][j + 1];
        }

        topCnt[sec]--;
        break;
    }

    insert(top[sec], topCnt[sec], 5, {arr[p.y][p.x], p.x, p.y});
}

int get(Point p) {
    return arr[p.y][p.x] + lazy[sector(p.x, p.y)];
}

void update(Point A, Point B, int num) {
    for (int sy = A.y / k; sy <= B.y / k; sy++) {
        for (int sx = A.x / k; sx <= B.x / k; sx++) {
            lazy[sy * (n / k) + sx] += num;
        }
    }
}

void query(Point A, Point B, int count, Point result[]) {
    Node best[5];
    int size = 0;

    for (int sy = A.y / k; sy <= B.y / k; sy++) {
        for (int sx = A.x / k; sx <= B.x / k; sx++) {
            int sec = sy * (n / k) + sx;

            for (int i = 0; i < topCnt[sec] && i < count; i++) {
                Node cur = top[sec][i];
                cur.value += lazy[sec];

                if (!insert(best, size, count, cur)) break;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        result[i] = {best[i].x, best[i].y};
    }
}

/*========= 이하 기존 main 유지 =========*/
static int in_graph[MAX_N][MAX_N];
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
        int N, K, M, i, j;
        N = read_int(); K = read_int(); M = read_int();

        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                in_graph[i][j] = read_int();

        init(N, K, in_graph);
        printf("#%d\n", tc);

        while (M--) {
            int op = read_int();

            if (op == 1) {
                Point p; int v;
                p.x = read_int(); p.y = read_int(); v = read_int();
                set(p, v);
            } else if (op == 2) {
                Point p;
                p.x = read_int(); p.y = read_int();
                printf("%d\n", get(p));
            } else if (op == 3) {
                Point a, b; int w;
                a.x = read_int(); a.y = read_int();
                b.x = read_int(); b.y = read_int(); w = read_int();
                update(a, b, w);
            } else {
                Point a, b, res[5] = {{0,0},{0,0},{0,0},{0,0},{0,0}};
                int c;
                a.x = read_int(); a.y = read_int();
                b.x = read_int(); b.y = read_int(); c = read_int();

                query(a, b, c, res);

                for (i = 0; i < c; i++)
                    printf(i ? " %d %d" : "%d %d", res[i].x, res[i].y);

                printf("\n");
            }
        }
    }

    return 0;
}