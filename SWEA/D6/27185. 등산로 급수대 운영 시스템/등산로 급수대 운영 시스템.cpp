#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
/* 필요한 STL 헤더는 자유롭게 추가해도 된다.
   단, next_site 등 전역 함수명과 std 심볼의 충돌을 피하기 위해
   using namespace std; 는 쓰지 말고 std:: 접두사를 사용할 것. */
using namespace std;
/*=========================================================
  여기서부터 6개 함수만 구현하시오.
  main 및 입출력 부분은 수정하지 않는 것을 권장한다.

  init      : 각 테스트 케이스 시작 시 1회 호출 (전역 초기화 필수)
  add_site  : 명령 1 — 위치 p에 쉼터 신설 (현재 없는 위치만 주어짐)
  close_site: 명령 2 — 위치 p의 쉼터 폐쇄 (현재 있는 위치만 주어짐)
  next_site : 명령 5의 단위 조회 — x 이상인 최소 쉼터 위치, 없으면 0
              (체인 반복·64비트 합산·출력은 아래 main이 수행한다)
  max_min_distance: 명령 3 — 답 반환, k가 현재 쉼터 수보다 크면 -1
  min_max_distance: 명령 4 — 답 반환, k가 현재 쉼터 수보다 크면 -1
=========================================================*/
set<int> arr;

void init(int n, const int sites[])
{
    // TODO: 초기 쉼터 n개(정렬 비보장·셔플 순서)를 등록하고
    //       전역 자료 구조를 반드시 초기화할 것. n = 0이면 빈 배열.
    arr.clear();
    int i;
    for(i=0;i<n;i++) arr.insert(sites[i]); 
}

void add_site(int p)
{
    // TODO: 위치 p에 쉼터 신설
    arr.insert(p);
}

void close_site(int p)
{
    // TODO: 위치 p의 쉼터 폐쇄
    arr.erase(p);
}

int next_site(int x)
{
    // TODO: x 이상인 최소 쉼터 위치를 반환, 없으면 0

    auto it = arr.lower_bound(x);

    if(it != arr.end()) return *it;
    else return 0;
}

int max_min_distance(int k)
{
    // TODO: 정확히 k곳 선택 시 인접 간격의 최솟값을 최대화한 값.
    //       k가 현재 쉼터 수보다 크면 -1

    if(k > (int)arr.size()) return -1;

    vector<int> v(arr.begin(), arr.end());

    int n = v.size();
    int left = 1;
    int right = v.back() - v.front();
    int answer = -1;

    while(left <= right){
        int mid = (left + right) / 2;

        int cnt = 1;
        int last = v[0];

        for(int i = 1; i < n; i++){
            if(v[i] - last >= mid){
                cnt++;
                last = v[i];
            }
        }

        if(cnt >= k){
            answer = mid;
            left = mid + 1;
        } else{
            right = mid - 1;
        }
    }

    return answer;
    
 
}

int min_max_distance(int k)
{
    // TODO: 최소·최대 위치를 반드시 포함해 정확히 k곳 선택 시
    //       인접 간격의 최댓값을 최소화한 값. k가 현재 쉼터 수보다 크면 -1
    if(k > (int)arr.size()) return -1;

    vector<int> v(arr.begin(), arr.end());

    int n = v.size();
    int left = 1;
    int right = v.back() - v.front();
    int answer = -1;

    while(left <= right){
        int mid = (left + right) / 2;

        int cur = 0;
        int cnt = 1; 
        bool possible = true;

        while(cur < n - 1){
            int next = cur;

            while(next + 1 < n && v[next + 1] - v[cur] <= mid){
                next++;
            }

            if(next == cur){
                possible = false;
                break;
            }

            cur = next;
            cnt++;

            if(cnt > k){
                possible = false;
                break;
            }
        }

        if(possible){
            answer = mid;
            right = mid - 1;
        } else{
            left = mid + 1;
        }
    }

    return answer;
}

/*========= 이하 수정 비권장 (출력 형식 유지) =========*/
#define MAX_INIT 10005

static int in_sites[MAX_INIT];
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
        int n, M, i;
        n = read_int(); M = read_int();
        for (i = 0; i < n; i++)
            in_sites[i] = read_int();
        init(n, in_sites);
        printf("#%d\n", tc);
        while (M--) {
            int op = read_int();
            if (op == 1) {
                int p = read_int();
                add_site(p);
            } else if (op == 2) {
                int p = read_int();
                close_site(p);
            } else if (op == 3) {
                int k = read_int();
                printf("%d\n", max_min_distance(k));
            } else if (op == 4) {
                int k = read_int();
                printf("%d\n", min_max_distance(k));
            } else {
                int s = read_int(), c = read_int(), j;
                long long total = 0;
                int x = s;
                for (j = 0; j < c; j++) {
                    int y = next_site(x);
                    total += y;
                    x = (int)(((long long)x + y) % 1000000000 + 1);
                }
                printf("%lld\n", total);
            }
        }
    }
    return 0;
}