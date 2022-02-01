# Resources:
- [https://codeforces.com/blog/entry/43225](https://codeforces.com/blog/entry/43225)

    How can matrix exponentiation help to solve a specific class of problems

    **Prerequisite** : Given A and B, calculate A\*B / Given A and A\*B, calculate B / Given A of size dxd, calculate A^n in 0(d^3log(n))

    3 useful applications :
    1. Couting the number of ways for reaching a vertex
    Let M1 be a matrix where M1[i][j] equals the number of edges connecting vertex i to vertex j. Let M2 be M1 raised to the power of b (M1^b). Now for any pair u and v, the number of ways for reaching vertex v starting from u after b steps is M2[u][v].
    <br> https://codeforces.com/contest/621/problem/E !!!

    2. Shortest path with a specified number of steps
    Let M1 be a matrix where M1[i][j] equals the cost of passing the edge connecting i to j (infinity if there is no edge). Let M2 be M1 raised to the power of b (but this time using the distance product for multiplication). Now for any pair u and v, the minimum cost for reaching vertex v starting from u after b steps is M2[u][v].
    <br> https://codeforces.com/problemset/problem/147/B

    3. Nth Fibonacci number in O(log n)
    Simple