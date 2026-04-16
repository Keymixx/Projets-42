import json
from typing import List, Dict


def json_validator(function_def: str, input: str) -> tuple:
    try:
        with open(function_def, "r") as f:
            func_def = json.load(f)
    except json.JSONDecodeError as e:
        raise json.JSONDecodeError(f"(function_definition): {e}")
    try:
        with open(input, "r") as f:
            ipt = json.load(f)
    except json.JSONDecodeError as e:
        raise json.JSONDecodeError(f"(input file) {e}")
    return func_def, ipt
