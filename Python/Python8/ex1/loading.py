import sys

print("\nLOADING STATUS: Loading programs...\n")
print("Checking dependencies:")

try:
    import pandas as pd
    print(f"[OK] pandas ({pd.__version__}) - Data manipulation ready")

    import matplotlib
    from matplotlib import pyplot as plt
    print(f"[OK] matplotlib ({matplotlib.__version__}) - Visualization ready")

    print("\nAnalyzing Matrix data...")

    data = pd.read_excel("pokemon.xlsx")
    poke = data.shape[0]
    tab = data["Type"].value_counts().plot.bar()
    print(f"Processing {poke} pokemon stats...")
    print("Generating visualization...")
    plt.title("Pokemon par Type")
    plt.savefig('my_plot.png')
    plt.show()
    print("\nAnalysis complete!")

except ImportError:
    print("Not dependencies detected")
    print("use:")
    print("- pip install -r requirements.txt")
    print("- python3 loading.py")
    print("or")
    print("- poetry install")
    print("- poetry run python loading.py")
    sys.exit()

except FileNotFoundError as e:
    print(f"FileError : {e}")
    sys.exit()

except PermissionError as e:
    print(f"PermissionError : {e}")
    sys.exit()

except AttributeError as e:
    print(f"PermissionError : {e}")
    sys.exit()
