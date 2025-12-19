
import subprocess
import os

def run_test():
    # Compile FIXED user code (O(N^2) logic fix)
    print("Compiling fixed user code (range_fixed_logic.cpp)...")
    res = subprocess.run(['g++', 'range_fixed_logic.cpp', '-o', 'range_fixed'], capture_output=True, text=True)
    if res.returncode != 0:
        print("Fixed code compilation failed:", res.stderr)
        return

    # Compile correct optimal solution (O(N))
    print("Compiling correct solution (range_solution.cpp)...")
    res = subprocess.run(['g++', 'range_solution.cpp', '-o', 'range_sol'], capture_output=True, text=True)
    if res.returncode != 0:
        print("Solution compilation failed:", res.stderr)
        return

    # Test Case
    input_str = "1\n5\n0 0 0 100 1\n"
    
    print("\nRunning fixed code with input:")
    print(input_str.strip())
    
    # Run fixed code
    try:
        p_fixed = subprocess.run(['./range_fixed'], input=input_str, capture_output=True, text=True, timeout=2)
        fixed_out = p_fixed.stdout.strip()
    except subprocess.TimeoutExpired:
        fixed_out = "TLE"
        
    print("Fixed Code Output:", fixed_out)

    # Run correct solution
    try:
        p_sol = subprocess.run(['./range_sol'], input=input_str, capture_output=True, text=True, timeout=2)
        sol_out = p_sol.stdout.strip()
    except subprocess.TimeoutExpired:
        sol_out = "TLE"

    print("Correct Output:", sol_out)
    
    if fixed_out != sol_out:
        print("\nMISMATCH FOUND!")
        print(f"Expected {sol_out}, got {fixed_out}")
    else:
        print("\nSUCCESS: Match found!")

if __name__ == "__main__":
    run_test()
