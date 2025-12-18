
import subprocess
import os

def run_test():
    # Compile user code
    print("Compiling user code...")
    res = subprocess.run(['g++', 'range.cpp', '-o', 'range'], capture_output=True, text=True)
    if res.returncode != 0:
        print("User code compilation failed:", res.stderr)
        return

    # Compile correct solution
    print("Compiling correct solution...")
    res = subprocess.run(['g++', 'range_solution.cpp', '-o', 'range_sol'], capture_output=True, text=True)
    if res.returncode != 0:
        print("Solution compilation failed:", res.stderr)
        return

    # Test Case
    input_str = "1\n5\n0 0 0 100 1\n"
    
    print("\nRunning user code with input:")
    print(input_str.strip())
    
    # Run user code
    try:
        p_user = subprocess.run(['./range'], input=input_str, capture_output=True, text=True, timeout=2)
        user_out = p_user.stdout.strip()
    except subprocess.TimeoutExpired:
        user_out = "TLE"
        
    print("User Code Output:", user_out)

    # Run correct solution
    try:
        p_sol = subprocess.run(['./range_sol'], input=input_str, capture_output=True, text=True, timeout=2)
        sol_out = p_sol.stdout.strip()
    except subprocess.TimeoutExpired:
        sol_out = "TLE"

    print("Correct Output:", sol_out)
    
    if user_out != sol_out:
        print("\nMISMATCH FOUND!")
        print(f"Expected {sol_out}, got {user_out}")
    else:
        print("\nMatch (or both wrong/TLE).")

if __name__ == "__main__":
    run_test()
