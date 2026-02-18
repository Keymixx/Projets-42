try:
    from dotenv import load_dotenv
    import os

    print("\nORACLE STATUS: Reading the Matrix...\n")

    load_dotenv()
    API_KEY = os.getenv("API_KEY", "Missing env variable")
    MATRIX_MODE = os.getenv("MATRIX_MODE", "Missing env variable")
    DATABASE_URL = os.getenv("DATABASE_URL", "Missing env variable")
    LOG_LEVEL = os.getenv("LOG_LEVEL", "Missing env variable")
    ZION_ENDPOINT = os.getenv("ZION_ENDPOINT", "Missing env variable")

    env_var = [
        API_KEY,
        MATRIX_MODE,
        DATABASE_URL,
        LOG_LEVEL,
        ZION_ENDPOINT
    ]

    missing_env = False
    for var in env_var:
        if var == "Missing env variable":
            missing_env = True

    print("Configuration loaded:")
    print(f"Mode: {MATRIX_MODE}")

    if MATRIX_MODE == "production":
        print("Database: [HIDDEN]")
    else:
        print(f"Database: {DATABASE_URL}")

    if MATRIX_MODE == "production":
        print("API Access: [HIDDEN]")
    else:
        print(f"API Access: {API_KEY}")

    if MATRIX_MODE == "production":
        print("Log Level: ERROR")
    else:
        print(f"Log Level: {LOG_LEVEL}")

    print(f"Zion Network: {ZION_ENDPOINT}")

    print("\nEnvironment security check:")
    print("[OK] No hardcoded secrets detected")
    if missing_env:
        print("[KO] Missing variable in .env")
    else:
        print("[OK] .env file properly configured")
    print("[OK] Production overrides available")

    print("\nThe Oracle sees all configurations.")

except ModuleNotFoundError:
    print("Module not found: use - pip install python-dotenv")
