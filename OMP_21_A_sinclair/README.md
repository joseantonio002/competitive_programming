# What puzzled me

pow function doesnt work, is there another way to calculate 2^n? Yes -> right shift operator


# First instinct

Number of programs is  2^n*8 because 1 byte = 256 programs. Basically the problem is calculate a massive power of 2

Calculate 2^n with right shift operator, since we can't do it all at once, since 2^n = 2^n-1 * 2, calculate 2^63 % 1000007 * (number of times until 2^n)


# Actual solution

https://chat.qwen.ai/c/dc24eda6-f28c-4a57-a674-be19fc7fcb05

