import subprocess

def run_cc():
    input_str = "1\n26 2\n"
    process = subprocess.Popen(
        ['./cc'], 
        stdin=subprocess.PIPE, 
        stdout=subprocess.PIPE, 
        stderr=subprocess.PIPE,
        text=True
    )
    stdout, stderr = process.communicate(input=input_str)
    return list(map(int, stdout.split()))

print("Compiling cc.cpp...")
subprocess.run(["g++", "-O2", "cc.cpp", "-o", "cc"], check=True)

print("Running with n=26, k=2...")
res = run_cc()
s_user = sum(res)
xor_sum = res[0] ^ res[1]

print(f"User Output: {res}")
print(f"User Sum: {s_user}")
print(f"XOR Check: {xor_sum} (Expected 26)")

# Optimal solution
# 26 is 11010
# Optimal pair maximizes sum.
# 21 (10101) and 15 (01111) -> XOR 11010 (26). Sum 36.
print("Optimal Sum: 36 (21 + 15)")

if s_user < 36:
    print("FAILURE: User solution is suboptimal.")
else:
    print("SUCCESS: User solution is optimal.")
