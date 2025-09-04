#include <bits/stdc++.h>
using namespace std;

// 2011 is NOT a leap year
/*
doomsday days (Monday)
1/10, 2/21, 4/4, 5/9, 6/6, 7/11, 8/8, 9/5, 10/10, 11/7, 12/12
*/

const vector<int> thirty_one_m{1, 3, 5, 7, 8, 10, 12};
const map<int, string> days = {
    {1, "Monday"},
    {2, "Tuesday"},
    {3, "Wednesday"},
    {4, "Thursday"},
    {5, "Friday"},
    {6, "Saturday"},
    {7, "Sunday"}
};

bool int_in_vector(const vector<int>& v, int x) {
  return std::find(v.begin(), v.end(), x) != v.end();
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  while(N--) {
    int m,d, c_d = 1, c_m = 1; // current day monday
    cin >> m >> d;
    if(m == 1 && d < 10) {
        for(int i = 10; i != d; i--) {
            c_d--;
            c_d == 0 ? c_d = 7 : c_d = c_d;
        }
    } else {
        for(int i = 10; !(d == i && m == c_m); i++) {
            c_d++;
            if(c_d == 8) c_d = 1;
            if (i == 31 && int_in_vector(thirty_one_m, c_m)) {
                i = 0;
                c_m++;
            } else if (i == 30 && !int_in_vector(thirty_one_m, c_m)) {
                i = 0;
                c_m++;
            } else if (i == 28 && c_m == 2) {
                i = 0;
                c_m++;
            }
        }
    }
    cout << days.at(c_d) << endl;
  }
  return 0;
}