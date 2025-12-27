print("=== CYBER ARCHIVES - DATA RECOVERY SYSTEM ===\n")
print("Accessing Storage Vault: ancient\_fragment.txt")


f = open("ancient_fragmet.txt", "r")
print("Connection established...\n")
print("RECOVERED DATA:")
print(f.read())
f.close()
print("\nData recovery complete. Storage unit disconnected.")
