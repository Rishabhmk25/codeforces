def solve_naive(n, k):
    # Try all pairs a, b such that a^b == n
    best_sum = -1
    best_pair = None
    for a in range(n + 1):
        b = n ^ a
        if b <= n:
            if a + b > best_sum:
                best_sum = a + b
                best_pair = (a, b)
    return best_pair, best_sum

n = 6
k = 2
pair, s = solve_naive(n, k)
print(f"n={n}, k={k}")
print(f"Optimal: {pair}, Sum={s}")
print(f"User Code would output: 0 {n}, Sum={n}")
if s > n:
    print("FAILURE CONFIRMED")
else:
    print("NO FAILURE")
