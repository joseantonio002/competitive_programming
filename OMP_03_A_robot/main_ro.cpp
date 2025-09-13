#include <bits/stdc++.h>
using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  while(cin >> N >> M) {
    vector<vector<string>> o_map;
    int x_ini, y_ini;
    for(int i = -1; i < N; i++) {
        if (i == - 1) {
            cin >> x_ini >> y_ini;
        }
        else {
            vector<string> row;
            for(int j = 0; j < M; j++) {
                string c;
                char input;
                cin >> input;
                c = string(1, input);
                row.push_back(c);
            }
            o_map.push_back(row);
        }
    }
    vector<vector<string>> r_map(N, (vector<string>(M, "?")));
    int nmoves = 0;
    int x = x_ini - 1, y = y_ini - 1;
    bool all_ocuppied = false, all_visited = false;
    while(!all_ocuppied && !all_visited) {
        r_map[x][y] = o_map[x][y]; // Visit current cell

        if(x > 0) { // Check north
          if(r_map[x - 1][y] == "?") r_map[x - 1][y] = "U" + o_map[x - 1][y];
        }  
        if(x < N - 1) { // Check south
          if(r_map[x + 1][y] == "?") r_map[x + 1][y] = "U" + o_map[x + 1][y]; 
        } 
        if(y > 0) {
          if(r_map[x][y - 1] == "?") r_map[x][y - 1] = "U" + o_map[x][y - 1]; // Check west
        }
        if(y < M - 1) {
          if(r_map[x][y + 1] == "?") r_map[x][y + 1] = "U" + o_map[x][y + 1]; // Check east
        }

        if(x > 0 && r_map[x - 1][y] == "U0") { // North
          x = x - 1; y = y; nmoves++;
        } else if(y < M - 1 && r_map[x][y + 1] == "U0") { // East
          x = x; y = y + 1; nmoves++;
        } else if(x < N - 1 && r_map[x + 1][y] == "U0") { // South
          x = x + 1; y = y; nmoves++;
        } else if(y > 0 && r_map[x][y - 1] == "U0") { // West
          x = x; y = y - 1; nmoves++;
        } else {
          all_ocuppied = true;
        }
    }
    for (vector<string> v : r_map) {
        // print top border for each row
        cout << "|";
        for (size_t i = 0; i < v.size(); i++) {
            cout << "---|";
        }
        cout << endl;

        // print row content
        cout << "|";
        for (string s : v) {
            if (s[0] == 'U') cout << " " << s[1] << " |";
            else cout << " " << s << " |";
        }
        cout << endl;
    }

    // print bottom border for the last row
    cout << "|";
    for (size_t i = 0; i < r_map[0].size(); i++) {
        cout << "---|";
    }
    cout << endl;

    cout << endl;
    cout << "REALIZADOS " << nmoves << " MOVIMIENTOS" << endl;
  }
  return 0;
}