from pydantic import BaseModel, Field
from typing import Dict


class FunctionModel(BaseModel):
    name: str
    description: str
    parameters: Dict[str, str]
    returns: Dict[str, str]
