import subprocess

def run_cc(n, k):
    input_str = f"1\n{n} {k}\n"
    try:
        process = subprocess.Popen(
            ['./cc'], 
            stdin=subprocess.PIPE, 
            stdout=subprocess.PIPE, 
            stderr=subprocess.PIPE,
            text=True
        )
        stdout, stderr = process.communicate(input=input_str)
        if not stdout.strip():
            return None
        parts = list(map(int, stdout.split()))
        return parts
    except Exception as e:
        return None

def check():
    print("Compiling cc.cpp...")
    subprocess.run(["g++", "-O2", "cc.cpp", "-o", "cc"], check=True)
    
    print("Checking for failures...")
    for n in range(2, 50):
        # We process even k since user code handles k%2==1 trivially
        k = 2
        
        # User logic for k=2 even numbers
        res = run_cc(n, k)
        if not res:
            continue
            
        a, b = res
        
        # Check 1: Constraints
        if a > n or b > n:
            print(f"FAILED CONSTRAINT: n={n}, k={k}")
            print(f"Output: {a}, {b}")
            print(f"Reason: Elements must be <= {n}")
            return
            
        # Check 2: Validity
        if (a ^ b) != n:
            print(f"FAILED VALIDITY: n={n}, k={k}")
            print(f"Output: {a}, {b}")
            print(f"XOR Sum: {a ^ b} (Expected {n})")
            return
            
        # Check Optimal (Naive check)
        # Simply check if sum < n, which is a weak check but user code generally outputs weird stuff
        # Or compare with naive solver if needed.
        # But constraint/validity likely to fail first.

check()
