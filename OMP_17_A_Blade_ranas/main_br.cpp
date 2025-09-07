#include <bits/stdc++.h>
using namespace std;

struct pos {
    int r;
    int c;
    pos() {}
    pos(int r, int c): r(r), c(c) {}
};

int check_horizontal(const vector<vector<char>>& grid, pos p, int nc) {
    p.r--;
    p.c--;
    if(grid[p.r][p.c] == '#') return 0;
    int nrep = 0;
    if(grid[p.r][p.c] == 'R') nrep++;
    for(int i = p.c + 1; i < nc; i++) {
        char cc = grid[p.r][i];
        if (cc == 'R') nrep++;
        else if(cc == '#') break;
    }
    for(int i = p.c - 1; i >= 0; i--) {
        char cc = grid[p.r][i];
        if (cc == 'R') nrep++;
        else if(cc == '#') break;
    }
    return nrep;
}

int check_vertical(const vector<vector<char>>& grid, pos p, int nr) {
    p.r--;
    p.c--;
    if(grid[p.r][p.c] == '#') return 0;
    int nrep = 0;
    for(int i = p.r + 1; i < nr; i++) {
        char cc = grid[i][p.c];
        if (cc == 'R') nrep++;
        else if(cc == '#') break;
    }
    for(int i = p.r - 1; i >= 0; i--) {
        char cc = grid[i][p.c];
        if (cc == 'R') nrep++;
        else if(cc == '#') break;
    }
    return nrep;
}

int check_diagonal(const vector<vector<char>>& grid, pos p, int nr, int nc) {
    p.r--;
    p.c--;
    if(grid[p.r][p.c] == '#') return 0;
    int nrep = 0;
    int j = p.c + 1;
    for(int i = p.r + 1; i < nr; i++) {
        if (j >= nc) break;
        char cc = grid[i][j];
        if (cc == 'R') nrep++;
        else if(cc == '#') break;
        j++;
    }
    j = p.c - 1;
    for(int i = p.r - 1; i >= 0; i--) {
        if (j < 0) break;
        char cc = grid[i][j];
        if (cc == 'R') nrep++;
        else if(cc == '#') break;
        j--;
    }
    j = p.c - 1;
    for(int i = p.r + 1; i < nr; i++) {
        if (j < 0) break;
        char cc = grid[i][j];
        if (cc == 'R') nrep++;
        else if(cc == '#') break;
        j--;
    }
    j = p.c + 1;
    for(int i = p.r - 1; i >= 0; i--) {
        if (j >= nc) break;
        char cc = grid[i][j];
        if (cc == 'R') nrep++;
        else if(cc == '#') break;
        j++;
    }
    return nrep;
}



int main() {

  int N;

  cin >> N;

  while(N--) {
    int nr, nc;
    cin >> nr >> nc;
    vector<vector<char>> grid;
    for(int irow = 0; irow < nr; irow++) {
      string s;
      cin >> s;
      grid.push_back({});
      for(char c : s) grid[int(grid.size()) - 1].push_back(c);
    }

    pos bestp;
    int bestnrep = -1;
    for(int i = 1; i <= nr; i++) {
        for(int j = 1; j <= nc; j++) {
            int nrep = 0;
            pos p(i, j);
            nrep += check_diagonal(grid, p, nr, nc);
            nrep += check_horizontal(grid, p, nc);
            nrep += check_vertical(grid, p, nr); 
            if(nrep > bestnrep) {
                bestp.c = j;
                bestp.r = i;
                bestnrep = nrep;
            }
        }
    }
    cout << bestp.r << " " << bestp.c;
    cout << endl;
  }
  return 0;
}