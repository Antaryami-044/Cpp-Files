#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <tuple>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    cin >> M >> N;

    vector<vector<char>> grid(M, vector<char>(N));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }

    int max_cells = 0;
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    for (int r = 0; r < M; ++r) {
        for (int c = 0; c < N; ++c) {
            if (grid[r][c] == '0') {
                continue;
            }

            for (int dir_idx = 0; dir_idx < 4; ++dir_idx) {
                int cur_r = r;
                int cur_c = c;
                int cur_dr = dr[dir_idx];
                int cur_dc = dc[dir_idx];

                map<tuple<int, int, int, int>, int> visited_states;
                vector<pair<int, int>> path;
                bool loop_found = false;

                while (true) {
                    tuple<int, int, int, int> current_state = make_tuple(cur_r, cur_c, cur_dr, cur_dc);

                    if (visited_states.count(current_state)) {
                        int loop_start_idx = visited_states[current_state];
                        set<pair<int, int>> unique_cells_in_loop;
                        for (size_t i = loop_start_idx; i < path.size(); ++i) {
                            unique_cells_in_loop.insert(path[i]);
                        }
                        max_cells = max(max_cells, (int)unique_cells_in_loop.size());
                        loop_found = true;
                        break;
                    }

                    visited_states[current_state] = path.size();

                    int next_r = cur_r;
                    int next_c = cur_c;

                    bool exited = false;
                    while (true) {
                        next_r += cur_dr;
                        next_c += cur_dc;
                        
                        if (next_r < 0 || next_r >= M || next_c < 0 || next_c >= N) {
                            exited = true;
                            break;
                        }
                        if (grid[next_r][next_c] != '0') {
                            break;
                        }
                        path.push_back({next_r, next_c});
                    }

                    if (exited) {
                        break;
                    }

                    cur_r = next_r;
                    cur_c = next_c;

                    path.push_back({cur_r, cur_c});

                    if (grid[cur_r][cur_c] == '/') {
                        int temp_dr = cur_dr;
                        cur_dr = -cur_dc;
                        cur_dc = -temp_dr;
                    } else if (grid[cur_r][cur_c] == '\\') {
                        int temp_dr = cur_dr;
                        cur_dr = cur_dc;
                        cur_dc = temp_dr;
                    }
                }
            }
        }
    }

    cout << max_cells << endl;

    return 0;
}