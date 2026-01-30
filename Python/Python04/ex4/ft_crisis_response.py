def crisis_protocol(filename):
	print(f"\nCRISIS ALERT: Attempting access to '{filename}'...")

	try: 
		with open(filename, "r") as file:
			data = file.read()
			print(f"SUCCESS: Archive recovered - ``{data}''")
			print("STATUS: Normal operations resumed")
	except FileNotFoundError:
		print("RESPONSE: Archive not found in storage matrix")
		print("STATUS: Crisis handled, system stable")
	except PermissionError:
		print("RESPONSE: Security protocols deny access")
		print("STATUS: Crisis handled, security maintained")

print("=== CYBER ARCHIVES - CRISIS RESPONSE SYSTEM ===")

crisis_protocol("lost_archive.txt")
crisis_protocol("classified_vault.txt")
crisis_protocol("standard_archive.txt")

print("\nAll crisis scenarios handled successfully. Archives secure.")
