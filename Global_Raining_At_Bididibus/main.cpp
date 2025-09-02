#include <bits/stdc++.h> // includes all standard libraries
using namespace std;

int main() {
  // make cin faster
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  while(N--) {
    string m;
    cin >> m;
    stack<int> st;
    int count = 0;
    for(int i = 0; i < int(m.size()); i++) {
      char c = m[i];
      if (c == '\\') {
        st.push(i);
      } else if (c == '/' && !st.empty()) { // If we are inside a valley (!st.empty()) and we go up (c == '/') there must be water
        int index = st.top(); st.pop();
        count += i - index; // The amount of water in a valley is the initial position minus the final position of the valley
      }
    }
    cout << count << endl;
  }
  return 0;
}