import sys

print("=== Command Quest ===")

len = len(sys.argv)
if len > 1:
    print(f"Program name: {sys.argv[0]}")
    print(f"Arguments received: {len - 1}")
    i = 1
    while i < len:
        print(f"Argument {i}: {sys.argv[i]}")
        i += 1
    print(f"Total arguments: {len}")
else:
    print("No arguments provided!")
    print(f"Program name: {sys.argv[0]}")
    print(f"Total arguments: {len}")