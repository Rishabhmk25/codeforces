def check_cc_logic():
    for n in range(1, 100):
        # User logic simulation for k=2
        # If n is power of 2: n, 0
        # If n is even and not power of 2: n-1, 3
        # Else (odd): n, 0
        
        k = 2
        bits = 0
        temp = n
        while temp > 0:
            if temp & 1:
                bits += 1
            temp >>= 1
        
        is_power_of_two = (n > 0) and ((n & (n - 1)) == 0)
        
        a, b = 0, 0
        if n % 2 == 0 and not is_power_of_two:
            a, b = n - 1, 3
        else:
            a, b = n, 0
            
        # Check validity
        current_xor = a ^ b
        if current_xor != n:
            print(f"FAIL VALIDITY: n={n}, k={k}. Output: {a} {b}. XOR_SUM={current_xor} != {n}")
            return
        
        if a > n or b > n:
            print(f"FAIL CONSTRAINT: n={n}, k={k}. Output: {a} {b}. Elements must be <= n")
            return

        # Check optimality (naive check)
        # We know greedy approach (n, 0) gives sum n
        # User tries to get more sum
        user_sum = a + b
        
        # Simple check: is user_sum correct?
        # For n=6 (110), user: 5, 3. XOR 6. Sum 8. Optimal.
        # For n=12 (1100), user: 11, 3. XOR 8 != 12. FAIL.
        
check_cc_logic()
