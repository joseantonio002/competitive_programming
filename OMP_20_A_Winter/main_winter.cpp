#include <bits/stdc++.h>

using namespace std;

map<string, int> months{
  {"Aug", 0},
  {"Sep", 1},
  {"Oct", 2},
  {"Nov", 3},
  {"Dec", 4}
};

vector<int> days = {31, 30, 31, 30};


int main() {
  
  while(true) {
    int d, mn;
    string m;
    cin >> d >> m;
    if(d == 0) break;
   
    mn = months.at(m);

    if(mn == 4) {
        if(d >= 21) cout << "Winter is here" << endl;
        else {
            cout << 21 - d << " days to winter" << endl;
        }
    } else {
        int ndays = 21 + (days.at(mn) - d);
        //cout << d << " " << days.at(mn) << "#" << endl;
        for(int i = mn + 1; i < int(days.size()); i++) ndays += days.at(i);
        cout << ndays << " days to winter" << endl;
    }

  }

  return 0;
}