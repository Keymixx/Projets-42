print("=== CYBER ARCHIVES - VAULT SECURITY SYSTEM ===")
print("\nInitiating secure vault access...")

with open("classified_data.txt", "r") as data:
    print("Vault connection established with failsafe protocols")
    print("\nSECURE EXTRACTION:")
    classified_data = data.read()
    print(classified_data)

with open("secure_preservation.txt", "w") as secure:
    print("\nSECURE PRESERVATION:")
    secure.write(classified_data)
    print("{[}CLASSIFIED{]} New security protocols archived")

if secure.closed and data.closed == True:
    print("Vault automatically sealed upon completion")
else:
    print("{[}ERROR{]} Vault not correctly close")
print("\nAll vault operations completed with maximum security.")




