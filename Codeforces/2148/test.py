import subprocess
import random

def run_program(filename, input_data):
    """Run a Python file with given stdin and return its stdout."""
    result = subprocess.run(
        ["python", filename],
        input=input_data,
        capture_output=True,
        text=True
    )
    return result.stdout.strip()

def test_files(file1, file2, test_input, i):
    out1 = run_program(file1, test_input)
    out2 = run_program(file2, test_input)

    # print(f"\nInput:\n{test_input}")
    # print(f"Output from {file1}:\n{out1}")
    # print(f"Output from {file2}:\n{out2}")

    if out1 == out2:
        return
        print(out1, out2)    
        print("✅ Outputs match", i)
    else:
        print("❌ Outputs differ", i)
        print(test_input)
        raise Exception

if __name__ == "__main__":
    # Example test cases

    inputs = []
    T = 1000
    for _ in range(T):
        N = 12
        K = random.randint(1, N)
        A = [str(random.randint(1, N)) for _ in range(N)]
        inputs.append("1\n"+str(N)+" "+str(K)+"\n"+" ".join(A))

    for i, inp in enumerate(inputs):
        test_files("E.py", "S.py", inp, i)