import sys

print("=== Command Quest ===")

len_args = len(sys.argv)
if len_args > 1:
	print(f"Program name: {sys.argv[0]}")
	print(f"Arguments received: {len_args - 1}")
	i = 1;
	while i < len_args:
		print(f"Argument {i}: {sys.argv[i]}")
		i += 1
	print(f"Total arguments: {len_args}")

else:
	print("No arguments provided!")
	print(f"Program name: {sys.argv[0]}")
	print(f"Total arguments: {len_args}")

