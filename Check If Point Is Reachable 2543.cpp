/*
EXPLANATION :-
Let's Think About this Problem from (targetX, targetY) to (1, 1)
Now if we are at a point (x, y) 
The Four Operations are ->
a) (x + y, y)
b) (x, x + y)
c) (x / 2, y) if x % 2 == 0
d) (x, y / 2) if y % 2 == 0

Now if we Look carefully, the first two operations are from Euclidean GCD Formulation, i.e., if there exists 'v' which divides both 'x' and 'y' then 'v' also divides 'x + y'
Operation c) can be used when point is of form (2 ^ m * x', y) for any m > 0.
Operation d) can be used when point is of form (x, 2 ^ n * y') for any n > 0.
Now using Operation a) and b) we want to reach a point (2 ^ m * x', 2 ^ n * y')  and then we can use operation c) and d) to reach (1, 1)
[Of course these operations can be done in any order required]
For example :-
from (4, 7) we want to reach (1, 1)
Since x = 4 is already of the form 2 ^ m * x' with m = 2 and x' = 1
We will use Operation c) two times : (4, 7) -> (2, 7) -> (1, 7)
Now we Will use operation b) : (1, 7) -> (1, 8)
Now y = 8 is of the form 2 ^ n * y' with n =  3 and y' = 1
So we will use Operation d) three times : (1, 8) -> (1, 4) -> (1, 2) -> (1, 1)
[This idea can be applied to any example]

Now we can deduce that if either of (x, y) is a power of 2 we can go from (x, y) to (1, 1)

Now let's say currently none of x and y is a power of 2.
Suppose after a minimum of k steps, (x0, y0) -> (x1, y1) -> ... -> (x_(k - 1), y_(k - 1)) -> (xk, yk), 
we have xk = 2 ^ m or, yk = 2 ^ n, such that none of x0, ..., x_(k - 1) and y0, ..., y_(k - 1) is a power of 2.
Now, let's take xk = 2 ^ m for example (it's similar if we take yk = 2 ^ n as example).
Now from (x_(k - 1), y_(k - 1)) to (xk, yk), we can perform two operations, namely a) and b).

For a):
  xk := x_(k - 1) + y_(k - 1)
  or, x_(k - 1) = xk - y_(k - 1) = 2 ^ m - y_(k - 1)
  So, All common dividers of x_(k−1) and y_(k−1) must be a power of 2. 
For b):
  xk := x_(k - 1)
Moreover, we found that along the way back from (xk​, yk) to (x0, y0), common dividers rk at each step must be a power of 2 (including 2^0 = 1). 
So GCD(x, y) must be a power of 2 for us to have a path from (x, y) to (1, 1).
  
*/

class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        // An alternate way is to check gcd & (gcd - 1) == 0
        return __builtin_popcount(gcd(targetX, targetY)) == 1;
    }
};
