#include <bits/stdc++.h>
using namespace std;

/*
Stack in c++ #include <stack>
stack<int> st;
st.push(5) // Add element to stack
st.top() // returns top of the stack withouth deleting it
st.pop() // deletes top of the stack
st.size()
As any element other than the top element cannot be accessed in the stack, it cannot be actually traversed. 
But we can create a copy of it, access the top element and delete the top. By doing this till the copy stack is empty, 
we can effectively traverse without modifying the original stack.
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    
    // Create a copy
    stack<int> temp(st);
    
    while(!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    return 0;
*/

// Count correct parenthesis

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  stack<char> st;
  for(int i=0; i < N; i++) {
    string mountain;
    int count = 0;
    cin >> mountain;
    for(char par: mountain){
      if (par == '(') {
        st.push(par);
      }
      else {
        st.size() > 0 ? (count++, st.pop()) : (void)0;
      }
    }
    cout << count << endl;
  }

  return 0;
}