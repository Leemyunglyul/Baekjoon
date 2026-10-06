// 최대 삽입 100,000번 × 단어 길이 10 + 루트
const int MAX_NODE = 1000001;

struct node {
    int next[26];
    int cnt;
};

node arr[MAX_NODE];
int num;

void clear_node(int idx) {
    for (int i = 0; i < 26; i++) {
        arr[idx].next[i] = 0;
    }

    arr[idx].cnt = 0;
}

void init(void) {
    num = 0;
    clear_node(0);  // 0번: 루트
}

void insert(int buffer_size, char* buf) {
    int cur = 0;

    for (int i = 0; i < buffer_size; i++) {
        int x = buf[i] - 'a';

        // 자식이 없으면 새 노드 생성
        if (arr[cur].next[x] == 0) {
            int idx = ++num;
            clear_node(idx);
            arr[cur].next[x] = idx;
        }

        cur = arr[cur].next[x];
        arr[cur].cnt++;
    }
}

int query(int buffer_size, char* buf) {
    int cur = 0;

    for (int i = 0; i < buffer_size; i++) {
        int x = buf[i] - 'a';

        if (arr[cur].next[x] == 0)
            return 0;

        cur = arr[cur].next[x];
    }

    return arr[cur].cnt;
}