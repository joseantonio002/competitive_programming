# What puzzled me


# First instinct

Loop all positions and calculate number of replicants eaten by checking all directions with loops

# Actual solution

To solve the Blade Ranas problem — finding the optimal grid position to eliminate the maximum number of replicants in 8 directions (horizontal, vertical, and diagonal), blocked by walls — we use a technique called Direction Vectors with Raycasting.

🔍 Technique Overview\
We define 8 direction vectors (dr, dc) representing movement in all 8 compass directions (like a queen in chess).\
For each valid position (not a wall), we “shoot rays” in each of the 8 directions:\
Move step-by-step in that direction.\
Count every 'R' (replicant) encountered.\
Stop when hitting a wall ('#') or grid boundary.\
We also include the center cell if it contains a replicant.\
We track the position with the highest count, breaking ties by choosing the topmost then leftmost (row-major order).\
🧩 Competitive Programming Relevance\
This technique is widely used in problems involving:

Line-of-sight / visibility (e.g., chess queen attacks, laser beams).\
Grid neighbor checks (e.g., Game of Life, Minesweeper).\
Pathfinding with directional constraints.\
Simulations involving propagation or blocking (walls, obstacles).\
Commonly known as “Direction Vectors” or “Grid Raycasting”, it’s a staple pattern in 2D grid problems.

```
    // 8 directions: N, NE, E, SE, S, SW, W, NW
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    ...
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
```


# Miscellaneous