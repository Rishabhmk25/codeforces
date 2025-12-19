import os
import subprocess
import random

def solve_naive(n, k):
    if k % 2 == 1:
        return k * n
    
    # solving for optimal a, b
    best_sum = -1
    for a in range(n + 1):
        b = n ^ a
        if b <= n:
            if a + b > best_sum:
                best_sum = a + b
    
    return best_sum + (k - 2) * n

def run_cpp(n, k):
    input_str = f"1\n{n} {k}\n"
    process = subprocess.Popen(
        ['./c'], 
        stdin=subprocess.PIPE, 
        stdout=subprocess.PIPE, 
        stderr=subprocess.PIPE,
        text=True
    )
    stdout, setderr = process.communicate(input=input_str)
    parts = list(map(int, stdout.split()))
    return sum(parts)

print("Compiling...")
os.system("g++ -O2 c.cpp -o c")

print("Running fuzz tests...")
for n in range(1, 100):
    for k in range(1, 6):
        naive = solve_naive(n, k)
        cpp_sum = run_cpp(n, k)
        if naive != cpp_sum:
            print(f"MISMATCH for n={n}, k={k}")
            print(f"Naive: {naive}, CPP: {cpp_sum}")
            exit(1)
print("Small inputs passed.")

# Random large inputs
for _ in range(100):
   n = random.randint(1, 1000)
   k = random.randint(1, 100)
   naive = solve_naive(n, k)
   cpp_sum = run_cpp(n, k)
   if naive != cpp_sum:
        print(f"MISMATCH for n={n}, k={k}")
        print(f"Naive: {naive}, CPP: {cpp_sum}")
        exit(1)

print("All tests passed.")
