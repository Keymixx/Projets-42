class ManagerGarden:
    def __init__(self):
        self.gardens = []
        self.total_garden = 0
        self.stats = self.GardenStats(self)

    def add_garden(self, garden):
        self.gardens.append(garden)
        self.total_garden += 1
        print(f"{garden.owner}'s garden has been added to the network.")

    @classmethod
    def create_garden_network(cls, gardens):
        network = cls()
        print("===Creation of garden network===")
        if type(gardens) is list:
            for garden in gardens:
                network.add_garden(garden)
        else:
            network.add_garden(gardens)
        return network

    def add_plant_net(self, owner, plant):
        for garden in self.gardens:
            if garden.owner == owner:
                garden.add_plant(plant)

    class GardenStats:
        def __init__(self, network):
            self.network = network

        def report_garden_owner(self, owner):
            for garden in self.network.gardens:
                if garden.owner == owner:
                    print(f"=== {garden.owner}'s Garden Report ===")
                    self.print_garden_owner(garden)
                    print()
                    self.garden_evolution(garden)
                    print(f"Plant types : {self.garden_plant_type(garden)}")
                    print("=== End of the Garden Report ===")

        @staticmethod
        def get_flower_info(plant):
            info = " "
            if isinstance(plant, Flowering):
                if plant.bloom is True:
                    info += "flowers (blooming)"
                    if isinstance(plant, PrizeFlower):
                        info += f", Prize points: {plant.prize}"
            return info

        def print_garden_owner(self, garden):
            print("Plants in garden:")
            for plant in garden.plants:
                print(f"- {plant.name}: {plant.height}cm", end="")
                print(f"{self.get_flower_info(plant)}")

        @staticmethod
        def garden_evolution(garden):
            print(f"Plants added since the last report: {garden.last_plants}")
            print(f"Total plants:{garden.total_plants}")
            print(f"Total growth since the last report: {garden.last_growth}")
            print(f"Total growth:{garden.total_growth}")
            garden.last_growth = 0
            garden.last_plants = 0

        @staticmethod
        def garden_plant_type(garden):
            reg = 0
            flow = 0
            priz_f = 0
            for plant in garden.plants:
                if isinstance(plant, PrizeFlower):
                    priz_f += 1
                elif isinstance(plant, Flowering):
                    flow += 1
                elif isinstance(plant, Plant):
                    reg += 1
            return f"{reg} regular, {flow} flowering, {priz_f} prize flowers"

        def get_network_info(self):
            print("=== Network Info ===")
            print(f"Height validation test: {self.validation_test()}")
            self.all_score()
            print(f"Total gardens managed: {self.network.total_garden}")

        def validation_test(self):
            for garden in self.network.gardens:
                for plant in garden.plants:
                    if plant.height < 0:
                        return False
            return True

        def all_score(self):
            print("Garden scores - ", end="")
            i = 0
            for garden in self.network.gardens:
                if i == 0:
                    print(f"{garden.owner}: {self.calcul_p(garden)}", end="")
                else:
                    print(f", {garden.owner}: {self.calcul_p(garden)}", end="")
                i += 1
            print()

        @staticmethod
        def calcul_p(garden):
            points = 0
            for plant in garden.plants:
                if isinstance(plant, PrizeFlower):
                    points += plant.prize
                else:
                    pass
            return points


class Garden:
    def __init__(self, owner):
        self.owner = owner
        self.plants = []
        self.last_growth = 0
        self.last_plants = 0
        self.total_plants = 0
        self.total_growth = 0

    def add_plant(self, plant):
        self.plants.append(plant)
        self.last_plants += 1
        self.total_plants += 1
        print(f"Added {plant.name} to {self.owner}'s garden")

    def grow_all(self):
        print(f"{self.owner} is helping all plants grow...")
        for plant in self.plants:
            plant.grow()
            self.total_growth += 1
            self.last_growth += 1

    def print_garden(self):
        for plant in self.plants:
            print(f"{plant.name}")


class Plant:
    def __init__(self, name, height):
        self.name = name
        self.height = height

    def grow(self):
        self.height += 1
        print(f"{self.name} grew 1cm")


class Flowering(Plant):
    def __init__(self, name, height, color):
        super().__init__(name, height,)
        self.color = color
        self.bloom = True


class PrizeFlower(Flowering):
    def __init__(self, name, height, color, prize):
        super().__init__(name, height, color)
        self.prize = prize


gardens = [
    Garden("Alice"),
    Garden("Bob"),
    Garden("Carl")
]
carrot = Plant("Carrot", 16)
rose = Flowering("Rose", 23, "red")
sunflower = PrizeFlower("Sunflower", 61, "yellow", 10)
tulip = PrizeFlower("Tulip", 31, "pink", 16)
oak_tree = Plant("Oak Tree", 1432)
network = ManagerGarden.create_garden_network(gardens)
print()
network.add_plant_net("Carl", carrot)
network.add_plant_net("Carl", rose)
network.add_plant_net("Carl", tulip)
print()
network.add_plant_net("Bob", sunflower)
network.add_plant_net("Bob", rose)
print()
network.stats.report_garden_owner("Carl")
network.add_plant_net("Carl", oak_tree)
print()
network.stats.get_network_info()
