print("=== CYBER ARCHIVES - VAULT SECURITY SYSTEM ===")
print("\nInitiating secure vault access...")

with open("classified_data.txt", "r") as file:
    print("Vault connection established with failsafe protocols")
    print("\nSECURE EXTRACTION:")
    classified_data = file.read()
    print(classified_data)

with open("secure_preservation.txt", "w") as file:
    print("\nSECURE PRESERVATION:")
    file.write(classified_data)
    print("[CLASSIFIED] New security protocols archived")

print("Vault automatically sealed upon completion")
print("\nAll vault operations completed with maximum security.")




