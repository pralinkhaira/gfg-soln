class Solution:
     def applyDiff2D(self, mat, opr):
        m, n = len(mat), len(mat[0])
        changes = [[0] * (n + 1) for _ in range(m + 1)]
        for v, r1, c1, r2, c2 in opr:
            changes[r1][c1] += v
            changes[r1][c2 + 1] -= v
            changes[r2 + 1][c1] -= v
            changes[r2 + 1][c2 + 1] += v
        # Propagating the changes
        # Special case for the first row
        for c in range(1, n):
            changes[0][c] += changes[0][c - 1]
        for r in range(1, m):
            # Propagate from previous column
            for c in range(1, n):
                changes[r][c] += changes[r][c - 1]
            # Then propagate from above row
            for c in range(n):
                changes[r][c] += changes[r - 1][c]
        # Apply changes to the matrix
        for r in range(m):
            for c in range(n):
                mat[r][c] += changes[r][c]
        return mat

