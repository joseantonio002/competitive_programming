#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    // 8 directions: N, NE, E, SE, S, SW, W, NW
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    while (N--) {
        int nr, nc;
        cin >> nr >> nc;
        vector<string> grid(nr);
        for (int i = 0; i < nr; i++) {
            cin >> grid[i];
        }

        int best_r = 1, best_c = 1, best_count = -1;

        for (int r = 0; r < nr; r++) {
            for (int c = 0; c < nc; c++) {
                if (grid[r][c] == '#') continue; // Can't stand on wall

                int count = 0;

                // Check all 8 directions
                for (int d = 0; d < 8; d++) {
                    int nr_ = r + dr[d];
                    int nc_ = c + dc[d];

                    // Raycast in this direction until wall or boundary
                    while (nr_ >= 0 && nr_ < nr && nc_ >= 0 && nc_ < nc) {
                        if (grid[nr_][nc_] == 'R') {
                            count++;
                        } else if (grid[nr_][nc_] == '#') {
                            break; // Stop at wall
                        }
                        // Move further in this direction
                        nr_ += dr[d];
                        nc_ += dc[d];
                    }
                }

                // Include center if it's a replicant
                if (grid[r][c] == 'R') {
                    count++;
                }

                // Update best position (row-major order ensures first top-left wins)
                if (count > best_count) {
                    best_count = count;
                    best_r = r + 1;
                    best_c = c + 1;
                }
            }
        }

        cout << best_r << " " << best_c << endl;
    }

    return 0;
}