print("=== CYBER ARCHIVES - PRESERVATION SYSTEM ===\n")
print("Initializing new storage unit: new_discovery.txt")

try:
    f = open("new_discovery.txt", "w")
    print("Connection established...\n")

    print("Inscribing preservation data...")
    
    print("{[}ENTRY 001{]} New quantum algorithm discovered")
    f.write("{[}ENTRY 001{]} New quantum algorithm discovered\n")
    print("{[}ENTRY 002{]} Efficiency increased by 347%")
    f.write("{[}ENTRY 002{]} Efficiency increased by 347%\n")
    print("{[}ENTRY 003{]} Archived by Data Archivist trainee")
    f.write("{[}ENTRY 003{]} Archived by Data Archivist trainee\n")
    
    f.close()
    print("\nData recovery complete. Storage unit disconnected.")

except:
    print("ERROR: Storage vault not found.")