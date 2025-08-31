#include <cstdio>
#include <iostream>
#include <string>
using namespace std;


int main() {
  string s;
  cin >> s;
  cout << s;
  return 0;
}

/*
#include <iostream>
using namespace std;

int main (void)
{
  int numcasos, N, M;
  char L;
  cin >> numcasos;
  for (int i= 0; i<numcasos; i++) {
    cin >> L >> N >> M;
    cout << (L=='s' ? N+M: L=='r' ? N-M : N*M) << endl;
  }
}
*/