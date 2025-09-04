# Problem description

[Problem](https://onlinejudge.inf.um.es/~mooshak/cgi-bin/execute/9760936032869357)

Background\
No. Doom's day algorithm is not a method to compute which day the world will end. It is an algorithm created by the mathematician John Horton Conway, to calculate which day of the week (Monday, Tuesday, etc.) corresponds to a certain date.

This algorithm is based in the idea of the doomsday, a certain day of the week which always occurs in the same dates. For example, 4/4 (the 4th of April), 6/6 (the 6th of June), 8/8 (the 8th of August), 10/10 (the 10th of October) and 12/12 (the 12th of December) are dates which always occur in doomsday. All years have their own doomsday.

In year 2011, doomsday is Monday. So all of 4/4, 6/6, 8/8, 10/10 and 12/12 are Mondays. Using that information, you can easily compute any other date. For example, the 13th of December 2011 will be Tuesday, the 14th of December 2011 will be Wednesday, etc.

The Problem\
Other days which occur on doomsday are 5/9, 9/5, 7/11 and 11/7. Also, in leap years, we have the following doomsdays: 1/11 (the 11th of January) and 2/22 (the 22nd of Febrary), and in non-leap years 1/10 and 2/21.

Given a date of year 2011, you have to compute which day of the week it occurs.

Input\
The input can contain different test cases. The first line of the input indicates the number of test cases.

For each test case, there is a line with two numbers: M D. M represents the month (from 1 to 12) and D represents the day (from 1 to 31). The date will always be valid.

Output\
For each test case, you have to output the day of the week where that date occurs in 2011. The days of the week will be: Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday.

Sample Input\
8
1 6
2 28
4 5
5 26
8 1
11 1
12 25
12 31

Sample Output
Thursday
Monday
Tuesday
Thursday
Monday
Tuesday
Sunday
Saturday

# What puzzled me

How do you know what months have 31 days? -> The Knuckle trick (month that fall in the knuckle have 31 days)

How do you know if a year is a leap year?\
1) Is it divisible by 4? Yes, continue; No, is not
2) Is it divisible by 100? Yes, continue; No, it is a leap year
3) Is it divisible by 400? Yes, it is a leap year; No, is not a leap year

# First instinct

Do it with loops

# Actual solution

Use the modulo operator

1. Days of the week are cyclical

There are 7 days in the week:

Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday


After Sunday, we go back to Monday.
This means the days repeat every 7 steps.

So:

Monday + 7 days = Monday again

Monday + 14 days = Monday again

Monday + 21 days = Monday again

In math, we describe this repetition using modulo 7.

2. Example without modulo

Let’s say we know:

December 12, 2011 = Monday (reference doomsday).

Now, what about December 25?

Difference in days: 25 - 12 = 13.

If you just “move forward 13 days” from Monday:

After 7 days → back to Monday

After 14 days → back to Monday again

But we only moved 13 days, not 14. So actually it’s Monday + 6 = Sunday.

Notice: “13 days later” is really the same as “6 days later” (because 13 and 6 differ by a multiple of 7).

3. Why modulo?

That’s exactly what modulo does:

13 % 7 = 6


So instead of carrying around “13 days later,” which is cumbersome, we just reduce it to 6 — the actual number of steps forward that matter for weekdays.

Another example:

Suppose the date was December 5.

Difference: 5 - 12 = -7.

Moving backwards 7 days from Monday → we land on Monday again.

But -7 % 7 = 0 (when normalized to non-negative).
So, again, it tells us “this is just 0 days away, still Monday.”

4. General principle

Whenever something repeats every N steps, you can use modulo N to figure out where you land.

Days of the week repeat every 7 → use % 7.

Clock hours repeat every 12 → use % 12.

Months repeat every 12 → use % 12.

Here, we only care about how far away the date is from the reference within the week cycle.
So we don’t care about the raw difference (13, -7, 20, -15 …).
We only care about that difference modulo 7, which reduces it to a neat number between 0 and 6.

# Miscellaneous

If the number is smaller than the modulo (e.g 2 % 7) the result is the number