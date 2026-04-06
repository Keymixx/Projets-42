from . import Small_LLM_Model, randint
Model = Small_LLM_Model(
    model_name="Qwen/Qwen3-0.6B",
    device=None,
    dtype=None,
    trust_remote_code=True,
)

num = randint(1, 10)
