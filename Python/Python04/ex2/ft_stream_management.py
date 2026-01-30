import sys

print("=== CYBER ARCHIVES - COMMUNICATION SYSTEM ===")

id = input("Input Stream active. Enter archivist ID: ")
report = input("Input Stream active. Enter status report: ")


print(f"\n{{[}}STANDARD{{]}} Archive status from {id}: {report}",file=sys.stdout)
print(f"{{[}}ALERT{{[}} System diagnostic: Communication channels verified",file=sys.stderr)
print(f"{{[}}STANDARD{{[}} Data transmission complete",file=sys.stdout)
print("\nThree-channel communication test successful")