#include <bits/stdc++.h>

using namespace std;

struct output {
    output(bool is, int next): is(is), next(next) {}
    bool is;
    int next;
};

output is_add_constant(const vector<int>& numbers) {
    int first_sub = numbers.at(int(numbers.size()) - 1) - numbers.at(int(numbers.size()) - 2);
    int sub;
    for(int i = int(numbers.size()) - 2; i > 0; i--) {
        sub = numbers[i] - numbers[i-1];
        if (sub != first_sub) return output(false, -1);
    }
    return output(true, numbers.back() + first_sub);
}

output is_fib(const vector<int>& numbers) {
    for(int i = int(numbers.size()) - 1; i > 1; i--) {
        if (numbers[i] != (numbers[i - 1] + numbers[i - 2])) return output(false, -1);
    }
    return output(true, numbers[int(numbers.size()) - 1] + numbers[int(numbers.size()) - 2]);
}

output is_add_more(const vector<int>& numbers) {
    int first_increment = numbers.at(1) - numbers.at(0);
    first_increment++;
    for(int i = 2; i < int(numbers.size()); i++) {
        if (numbers[i] != (numbers[i - 1] + first_increment)) return output(false, -1);
        first_increment++;
    }
    return output(true, numbers[int(numbers.size()) - 1] + first_increment);
}

output is_mult_constant(const vector<int>& numbers) {
    float constant = numbers.at(1)/float(numbers.at(0));
    for(int i = 2; i < int(numbers.size()); i++) {
        if (numbers[i] != int(numbers[i - 1] * constant)) return output(false, -1);
    }
    return output(true, int(numbers[int(numbers.size()) - 1] * constant));
}

int main() {

  int N;
  cin >> N;

  while(N--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> numbers{a, b, c, d};
    
    output addconstant = is_add_constant(numbers), fib = is_fib(numbers), 
                                multc = is_mult_constant(numbers), addm = is_add_more(numbers);

    if(addconstant.is) cout << addconstant.next;
    else if(fib.is) cout << fib.next;
    else if(multc.is) cout << multc.next;
    else if(addm.is) cout << addm.next;
    else cout << 42;

    cout << endl;

  }

  return 0;
}