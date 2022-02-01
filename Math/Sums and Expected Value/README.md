[CF Errichto's blog](https://codeforces.com/blog/entry/62690) and it's [video](https://www.youtube.com/watch?v=U_h3IjreRek) <br>

## EV easy problems

The main thing here to remember is the use of symmetry and linearity. Try to think of every way to consider each problem, and find symmetric simplifications.

## Problems for "contribution" technique

1. Iterate over the values. For each, there are l lower values on the left, and r on the right.
2. **MOST IMPORTANT** Each edge contributes once for each path crossing it. Root the tree, dp to find the size of each subtree. <br>
   Now the contribution of each edge is the number of paths crossing it, which the number of nodes above it times the number of nodes under it. <br>
   N total nodes, u under it, contribution is u*(N-u)
3. - First straight-forward approache : The expected value for each competition is ai/2, so the total expected value is sum(ai/2)
   - Second option : Consider iterating over all possible outcomes (visualize it with a bitmask). By symmetry, each prize contributes 2^N-1 times to the answer, and there are 2^N possibilities. sum(ai*2^N-1) / 2^N = sum(ai/2).
4. - Sort the array a, and iterate over pairs of numbers (a[i], a[j]) (eventually the same i==j). Count the number of subsets where a[i] is the min, and a[j] the max. They are 2^j-i-1 such subsets, their contribution is a[j]-a[i]
   - Use the **linearity of the expectation** : E[max-min] = E[max]-E[min] <br>
    **REMEMBER** The expected value over a linear expression is the linear expression of the expected value.