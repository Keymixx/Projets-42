import sys
import site


def in_venv():
    return sys.prefix != sys.base_prefix


def welcome_msg():

    if in_venv():
        return "Welcome to the construct"
    else:
        return "You're still plugged in"


if __name__ == "__main__":

    if not in_venv():
        print("\nMATRIX STATUS: You're still plugged in\n")

        print(f"Current Python: {sys.executable}")
        print("Virtual Environment: None detected")

        print("\nWARNING: You're in the global environment!")
        print("The machines can see everything you install.")

        print("\nTo enter the construct, run:")
        print("python -m venv matrix_env")
        print("source matrix_env/bin/activate")

        print("\nThen run this program again.")

    else:

        print("\nMATRIX STATUS: Welcome to the construct\n")

        venv_path = sys.prefix.split("/")
        print(f"Current Python: {sys.executable}")
        print(f"Virtual Environment: {venv_path[-1]}")
        print(f"Environment Path: {sys.prefix}")

        print("\nSUCCESS: You're in an isolated environment!")
        print("Safe to install packages without affecting")
        print("the global system.")

        print("\nPackage installation path:")
        for path in site.getsitepackages():
            if "site-packages" in path:
                print(path)
