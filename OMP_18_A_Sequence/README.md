# What puzzled me


# First instinct

Put the numbers in a vector, make four functions that iterate the vector checking the conditions.

To check Multiply by constant divide n/n-1

# Actual solution

You dont need the vector and the functions, they are only four numbers

Logic Behind the Check in Code
We are given 4 numbers: a, b, c, d

We want to check:
→ Is b = a × r?
→ Is c = b × r = a × r²?
→ Is d = c × r = a × r³?

If yes, then next term = d × r = a × r⁴

But here’s the catch: we cannot use floating-point arithmetic because:

Floating point can be imprecise (e.g., 0.1 can’t be represented exactly in binary).
The problem says the result must be an integer.
We’re dealing with integers, so we must use integer arithmetic only.
✅ Step-by-Step Logic in Code
Step 1: Handle the case when a == 0
If the first term is 0, then:

b = 0 × r = 0
c = 0 × r = 0
d = 0 × r = 0
So for the sequence to be geometric, all terms must be zero.

cpp


1
2
3
4
5
6
⌄
⌄
if (a == 0) {
    if (b == 0 && c == 0 && d == 0) {
        geo_valid = true;
        next_geo = 0;
    }
}
If any of b, c, d is non-zero → not geometric.

Step 2: When a != 0 — Check ratio consistency without division
Instead of computing r = b / a (which may be fractional and cause precision issues), we use this mathematical trick:

In a geometric sequence:
b / a = c / b → Cross-multiplying → b² = a × c
Similarly: c / b = d / c → c² = b × d 

This avoids division and floating point!

So we check:

cpp


1
if (b * b == a * c && c * c == b * d)
✅ If both are true → the ratios are consistent → it’s geometric.

Step 3: Compute the next term — Must be integer!
Now, we need to compute: next = d × r

But r = d / c (from last two terms), so:

next = d × (d / c) = d² / c 

We must ensure this is an integer.

So:

If c == 0 → we can’t divide → but from earlier, if c == 0, then from c² = b × d → 0 = b × d
If b != 0 → then d must be 0 → so next term = 0
If b == 0 → then from b² = a × c → 0 = a × 0 → true, but since a != 0 (we’re in else branch), then c = 0 implies b = 0 (from b² = a×c = 0) → then d must be 0 (from c² = b×d = 0) → so again, next = 0
So if c == 0, we require d == 0 → then next term = 0.

cpp


1
2
3
4
5
6
⌄
⌄
if (c == 0) {
    if (d == 0) {
        geo_valid = true;
        next_geo = 0;
    }
}
Step 4: When c != 0 — Check divisibility
We compute d² / c — but only if it’s an integer.

In C++, to check if d² is divisible by c:

cpp


1
if ((d * d) % c == 0)
⚠️ Important: This works for positive and negative c and d in C++ only if we’re careful about modulo with negatives.

But in C++, (d*d) % c when c is negative may give implementation-defined results. However, since d*d is always non-negative, and if c is negative, (d*d) % c is negative or zero — but we only care if it’s zero.

Actually, mathematically, divisibility doesn’t care about sign:
→ d² divisible by c means d² = k × c for some integer k.

But in C++, -5 % 2 is -1, not 1, so if c is negative, (d*d) % c == 0 still works correctly for checking divisibility? Let’s test:

d=10, c=-100: d*d = 100, 100 % (-100) == 0 → true ✅
d=-10, c=100: (-10)*(-10)=100, 100 % 100 == 0 → true ✅
d=-10, c=-100: 100 % (-100) == 0 → true ✅
✅ So in practice, (d*d) % c == 0 works correctly for divisibility check regardless of the sign of c, because d*d is always non-negative, and if c divides d*d, the remainder is 0.

Then compute:

cpp


1
next_geo = (d * d) / c;
This uses integer division — which is exact because we checked remainder is 0.


# Miscellaneous