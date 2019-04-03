# Andrew Stankevich Contests

## [Contest 10](https://codeforces.com/gym/100212)

1. The Smart Bomb

    Geometry Easy O(1)

1. I Just Called

    Not solved

1. Order-Preserving Codes

    DP Knuth Optimization Classic

1. More Divisors

    Highly Composite Number

1. Long Dominoes

    Bitmask + DP
    No biginteger needed

1. The Magic Wheel

    * Use pythagoras for distance.
    * Brute force on all possible cyclical rotations of pairings.
    * Solve both sides independently.

1. Cracking SSH

    Easy dp

1. Periodic Tilings

    Find if a polyiomino is periodic.
    Solution (in the problem) : if it is possible to tile the plane with some polyiomino in a regular way, then in the tiling each polyiomino has a common border of non-zero length with at most six other polyiominoes.

    Brute force three other positions bordering figures check non overlap and full border is covered. there shoudl be a symmetric so we should bf at most 3 figures (so total solution is O(n**3) n is the border of the given polyomino)

    Constructive

1. Trade

    Bipartite graph is given. Find minimum set of edges such that each vertex has degree at least 2.
    Build solution is required.

    Solution:
        * Flow with lower_bound: [By eloy]
        *   Capacity from Source to side 1 is degree - 2. Capacity from side 2 to Sink degree - 2.
            Regular graph from side 1 to side 2. Solution is unmatched edges.




1. Counting Triangulations

    Bitmask DP on convex hull. Big integers are required.

1. Unfair Contest

    Ad-hoc