from llm_sdk import Small_LLM_Model
from src.parser import json_validator
import json

try:
    model = Small_LLM_Model()
    prompt = "Give me a short introduction to large language model."
    messages = [
        {"role": "user", "content": prompt}
    ]
    prompt = "Coucou"

    func_def, input = json_validator(
        "data/input/functions_definition.json",
        "data/input/function_calling_tests.json")

    print(func_def)
    print(input)

    # for _ in range(50):
    #     encode = model.encode(prompt)
    #     encode = encode.tolist()
    #     logits = model.get_logits_from_input_ids(encode[0])
    #     test = logits.index(max(logits))
    #     prompt += model.decode([int(test)])
    # print(prompt)

except Exception as e:
    print(f"JSON ERROR: {e}")
