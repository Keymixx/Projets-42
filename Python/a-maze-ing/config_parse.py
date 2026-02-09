from typing import Dict, Any, Optional
import sys


def config(file: str) -> Optional[Dict[str, Any]]:
    """Parse a configuration file and validate maze parameters.

    Args:
        file (str): The path or filename of the configuration file.

    Returns:
        Dict: A dictionary with validated keys (WIDTH, HEIGHT, ENTRY,
            EXIT, OUTPUT_FILE, PERFECT) or None if file not found.

    Raises:
        ValueError: If a mandatory key is missing, invalid, or if
            coordinates are out of bounds.
        FileNotFoundError: If file doesn't founded.
    """

    required_keys = ["WIDTH", "HEIGHT", "ENTRY",
                     "EXIT", "OUTPUT_FILE", "PERFECT"]
    all_keys = ["WIDTH", "HEIGHT", "ENTRY",
                "EXIT", "OUTPUT_FILE", "PERFECT", "SEED"]
    file_content: Dict[str, Any] = {}
    try:
        with open(file, "r") as f:
            for line in f:
                line = line.strip()
                if not line or line.startswith("#"):
                    continue
                if "=" not in line:
                    raise ValueError(f"Invalid line detected: {line}")

                parts = line.split("=", 1)
                key = parts[0].strip()
                value = parts[1].strip()
                clean_value = value.replace("(", "").\
                    replace(")", "").replace(" ", "")

                if key not in all_keys:
                    raise ValueError(f"Invalid line detected: {line}")

                try:

                    if key in file_content:
                        raise ValueError(f"Duplicate key detected: {key}")

                    if key in ["WIDTH", "HEIGHT"]:
                        file_content[key] = int(clean_value)
                    elif key in ["ENTRY", "EXIT"]:
                        pos = [int(p) for p in clean_value.split(",")]
                        if len(pos) == 2:
                            file_content[key] = tuple((pos[0], pos[1]))
                    elif key == "OUTPUT_FILE":
                        if value.lower().endswith(".txt"):
                            file_content[key] = value
                    elif key == "PERFECT":
                        if value.upper() == "TRUE":
                            file_content[key] = True
                        elif value.upper() == "FALSE":
                            file_content[key] = False
                        else:
                            raise ValueError("PERFECT must be True or False")
                    elif key == "SEED":
                        file_content[key] = int(clean_value)

                except ValueError as e:
                    print(f"ValueError : {e}")
                    sys.exit()

            missing = [k for k in required_keys if k not in file_content]
            if missing:
                raise ValueError(f'Missing/Invalid: {", ".join(missing)}')

            if file_content["ENTRY"] == file_content["EXIT"]:
                raise ValueError("ENTRY and EXIT can't be equal")

            width, height = file_content["WIDTH"], file_content["HEIGHT"]
            for key in ["ENTRY", "EXIT"]:
                y, x = file_content[key]
                if not (0 <= y <= height and 0 <= x <= width):
                    raise ValueError(
                        f"Limit Error: {key}: (y={y}, x={x}) "
                        f"for (height={height}, width={width})")

            if "SEED" in file_content:
                if 1 > file_content["SEED"] > 2147483647:
                    print(file_content["SEED"])
                    raise ValueError("SEED must be between 1 and 2147483647")

        return file_content
    except FileNotFoundError:
        print("Error: File config.txt not found in storage!")
        sys.exit()
    except PermissionError:
        print("Error: Permission denied for config.txt")
        sys.exit()
