class Plant:
    def __init__(self, name:str, age:int , height:int):
        self.name = name
        self.age = age
        self.height = height

class Flower(Plant):
    def __init__(self, name, age, height, color):
        super().__init__(name, age, height,)
        self.color = color

    def bloom(self):
        print(f"{self.name} is blooming beautifully!")

class Tree:
    def __init__(self, name, age, height, trunk_diameter):
        super().__init__(name, age, height,)
        self.trunk_diameter = trunk_diameter
    
    def produce_shade(self):
        print(f"{self.name} provides {self.trunk_diameter * 1.56} square meters of shade")
    
class Vegetable(Plant):
    def __init__(self, name, age, height, harvest_season):
        super().__init__(name, age, height,)
        self.harvest_season = harvest_season

    def produce_shade(self):
        print(f"{self.name} is rich in vitamin C")