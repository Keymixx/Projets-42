def NULL_not_found(object: any) -> int:
    if isinstance(object, float) and object != object :
        print(f"Cheese: {object} {type(object)}")
    elif object == None:
        print(f"Nothing: {object} {type(object)}")
    elif isinstance(object, bool):
        print(f"Fake: {object} {type(object)}")
    elif isinstance(object, int) and object == 0:
        print(f"Zero: {object} {type(object)}")
    elif isinstance(object, str) and object == "":
        print(f"Empty: {type(object)}")
    else:
        print ("Type not found")
        return 1
    return 0