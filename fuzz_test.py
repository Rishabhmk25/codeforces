
import subprocess
import random

def run_compare():
    # Helper to clean/compile
    subprocess.run(['g++', 'range.cpp', '-o', 'range'], check=False)
    subprocess.run(['g++', 'range_solution.cpp', '-o', 'range_sol'], check=False)

    cases_found = 0
    while cases_found < 3:
        n = random.randint(3, 5) # Keep N small for readability
        arr = [random.randint(0, 20) for _ in range(n)]
        
        input_str = f"1\n{n}\n" + " ".join(map(str, arr)) + "\n"
        
        try:
            p_user = subprocess.run(['./range'], input=input_str, capture_output=True, text=True)
            p_sol = subprocess.run(['./range_sol'], input=input_str, capture_output=True, text=True)
            
            user_out = p_user.stdout.strip()
            sol_out = p_sol.stdout.strip()
            
            if user_out != sol_out:
                print(f"CASE {cases_found + 1}:")
                print(f"Input: {arr}")
                print(f"User: {user_out} | Correct: {sol_out}")
                print("-" * 20)
                cases_found += 1
        except Exception as e:
            pass

if __name__ == "__main__":
    run_compare()
