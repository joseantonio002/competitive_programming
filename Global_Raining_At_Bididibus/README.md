# Problem description:

[Problem](https://onlinejudge.inf.um.es/~mooshak/cgi-bin/execute/41307266029206696)

Background
Bididibus is an ancient two-dimensional universe populated by the Bididibusians. Bididibusians have their own 2D water, 2D mountains, 1D television, and even an amazing new technology of 2D cinemas!

These days, some Bididibusian scholars are warning the public about the risks of global raining. Such climate catastrophe would fill with water all the valleys of the universe.

The Problem
Bididibus consists of blocks with uniform width and height. Bididibusian orography is described by a series of symbols, from left to right, indicating that the land rises one unit (represented by "/"), descends one unit (represented by "\"), or it is flat (represented by "_").

For example, we can have a 2D universe like this:

              _
             / \
            /   \__/\_
    /\_   _/          \   _
 /\/   \_/             \_/ \    /\
/                           \/\/
It goes without saying that native geographers are big fans of ASCII art. They also use a simplified representation, where each column (from left to right) is replaced by the symbol it contains. For example, the simplified representation of the previous universe would be:

//\//\_\_/_///_\\__/\_\\_/_\\/\//\
After the global rain, water would fill all the blocks of the valleys. If we represent water areas in blue, we would have the following:

Observe that a block with "/" or "\" partially filled with water corresponds to 1/2 units of water. A block completely filled with water corresponds to 1 unit of water. For example, in the previous universe we have a total of 21 units of water.

Given a simplified representation of a universe, your task is to compute the units of water that we would have after the global rain.

The Input
The first line of the input contains an integer indicating the number of test cases.

For each test case, there is a line which can contain three possible symbols:   "/", "\", "_". There will be at most 10000 symbols in each line.

The Output
For each test case, the output should contain a single integer indicating the units of water of the corresponding case.

Sample Input
4
//\//\_\_/_///_\\__/\_\\_/_\\/\//\
////\\\\\\\\
\/
\\\\\\\\\\//////////
Sample Output
21
0
1
100


# What puzzled me

I didnt know how to keep track of the valleys, SOLUTION -> [Stack](https://en.cppreference.com/w/cpp/container/stack.html) as a tool for matching opening and closing elements. \
I didnt know how to calculate the amount of water depending on the deepness and flat terrain

# First instinct

Approach the problem instead of by lenght by height. Every time you "leave" a valley (find / with stack not empty) sum to the current amount of water + 1 (because minimum water is always 1) + the number of flat terrain in that valley and the below (variable storing this number) + 2 * the "height" of the valley (if the valley is only \\/ then height 0, \\\\// height 1. This is because every time you go up in a valley you add 2 water)

This didnt work because if we have nested valleys it would sum the height of the previous valley, basically it assumed that once you started going up it will continue to go up

# Actual solution

Instead of looking it from bottom to top. Look at the valleys from left to right, the amount of water in a "floor" of the valley is equal to the subtraction of the index at the end of the valley minus the index at the start, so you just have to sum

# Miscellaneous

in c++, ternary operator, can I do more than one operation in a case, can I do nothing?: 

st.size() > 0 ? count++; st.pop() : NULL;

st.size() > 0 ? (count++, st.pop()) : (void)0;

(count++, st.pop()) uses the comma operator, which evaluates count++, then st.pop(), and returns the result of st.pop().(void)0 is a common idiom for “do nothing.”