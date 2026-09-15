#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    for (int test_case = 1; test_case <= T; ++test_case)
    {
        int N, M;
        cin >> N >> M;

        string board[50];
        int devil[50][50];
        int dist[50][50];
        queue<pair<int, int>> dq, sq;

        for (int r = 0; r < N; ++r)
        {
            cin >> board[r];
            fill(devil[r], devil[r] + M, 1000000000);
            fill(dist[r], dist[r] + M, -1);

            for (int c = 0; c < M; ++c)
            {
                if (board[r][c] == '*')
                {
                    devil[r][c] = 0;
                    dq.push({r, c});
                }
                else if (board[r][c] == 'S')
                {
                    dist[r][c] = 0;
                    sq.push({r, c});
                }
            }
        }

        while (!dq.empty())
        {
            auto [r, c] = dq.front();
            dq.pop();

            for (int d = 0; d < 4; ++d)
            {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                    continue;
                if (board[nr][nc] == 'X' || board[nr][nc] == 'D')
                    continue;
                if (devil[nr][nc] != 1000000000)
                    continue;

                devil[nr][nc] = devil[r][c] + 1;
                dq.push({nr, nc});
            }
        }

        int answer = -1;

        while (!sq.empty())
        {
            auto [r, c] = sq.front();
            sq.pop();

            if (board[r][c] == 'D')
            {
                answer = dist[r][c];
                break;
            }

            for (int d = 0; d < 4; ++d)
            {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                    continue;
                if (board[nr][nc] == 'X' || dist[nr][nc] != -1)
                    continue;
                if (dist[r][c] + 1 >= devil[nr][nc])
                    continue;

                dist[nr][nc] = dist[r][c] + 1;
                sq.push({nr, nc});
            }
        }

        cout << "#" << test_case << " ";
        if (answer == -1)
            cout << "GAME OVER\n";
        else
            cout << answer << '\n';
    }

    return 0;
}