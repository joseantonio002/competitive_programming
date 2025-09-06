

This one was also easy

I did the digit sum converting to string and then iterating the string and converting char to int (by substracting the char '0'),
but the arithmetic way is:

```
    int num = 12345;
    int sum = 0;

    while (num > 0) {
        sum += num % 10;  // take last digit
        num /= 10;        // remove last digit
    }
```

A way to check if a float value has no fractional part:

```
bool is_square(long long n) {
  float sq = sqrt(n);
  return fmod(sq, 1.0f) == 0.0f;
}
```

How setprecision and fixed work:

std::fixed → forces decimal notation (no scientific e+08).

std::setprecision(10) → controls number of digits after the decimal point.