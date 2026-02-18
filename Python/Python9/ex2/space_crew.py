try:
    from datetime import datetime
    from enum import Enum
    from pydantic import Field, BaseModel, model_validator
    from typing import List

except ModuleNotFoundError as e:
    print(e)
    print("- pip install pydantic")


class Rank(Enum):
    CADET = "cadet"
    OFFICER = "officer"
    LIEUTENANT = "lieutenant"
    CAPTAIN = "captain"
    COMMANDER = "commander"


class CrewModel(BaseModel):
    member_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=2, max_length=50)
    rank: Rank
    age: int = Field(ge=18, le=80)
    specialization: str = Field(min_length=3, max_length=30)
    years_experience: int = Field(ge=0, le=50)
    is_active: bool = Field(default=True)


class SpaceMission(BaseModel):
    mission_id: str = Field(min_length=5, max_length=15)
    mission_name: str = Field(min_length=3, max_length=100)
    destination: str = Field(min_length=3, max_length=50)
    launch_date: datetime
    duration_days: int = Field(ge=1, le=3650)
    crew: List[CrewModel] = Field(min_length=1, max_length=12)
    mission_status: str = Field(default="planned")
    budget_millions: float = Field(ge=1, le=1000000)

    @model_validator(mode="after")
    def check_id(self):
        if not self.mission_id[:1] == "M":
            raise ValueError("Mission ID must start with 'M'")
        return self

    @model_validator(mode="after")
    def check_leader(self):
        leaders = []
        for member in self.crew:
            if member.rank == Rank.CAPTAIN or member.rank == Rank.COMMANDER:
                leaders.append(member)

        if not leaders:
            raise ValueError("Must have at least one Commander or Captain")
        return self

    @model_validator(mode="after")
    def long_mission(self):
        if self.duration_days > 365:
            crew_count = len(self.crew)
            experienced_member = 0
            for member in self.crew:
                if member.years_experience >= 5:
                    experienced_member += 1
            if not experienced_member >= crew_count / 2:
                raise ValueError("Long missions need 50% experienced crew")
        return self

    @model_validator(mode="after")
    def is_members_active(self):
        for member in self.crew:
            if not member.is_active:
                raise ValueError("All crew members must be active")
        return self


def main():
    owel = CrewModel(
            member_id="ID001",
            name="Owel",
            rank=Rank.COMMANDER,
            age=23,
            specialization="Informatique",
            years_experience="50",
            is_active=True
        )

    yannis = CrewModel(
            member_id="ID002",
            name="Yannis",
            rank=Rank.LIEUTENANT,
            age=29,
            specialization="Combat",
            years_experience="15",
            is_active=True
        )

    felix = CrewModel(
            member_id="ID003",
            name="Felix",
            rank=Rank.CADET,
            age=19,
            specialization="Rien",
            years_experience="0",
            is_active=True
        )

    carl = CrewModel(
            member_id="ID004",
            name="Carl",
            rank=Rank.CAPTAIN,
            age=24,
            specialization="Prout",
            years_experience="10",
            is_active=True
        )

    nicolas = CrewModel(
            member_id="ID005",
            name="Nicolas",
            rank=Rank.OFFICER,
            age=28,
            specialization="Babyfoot",
            years_experience="25",
            is_active=True
        )

    crew = [owel, yannis, carl, felix, nicolas]

    mission = SpaceMission(
            mission_id="M0001",
            mission_name="Operation FIZZBUZZ",
            destination="Planete Prout",
            launch_date=datetime.now(),
            duration_days=361,
            crew=crew,
            mission_status="",
            budget_millions=500000
        )

    print("Space Mission Crew Validation")
    print("=========================================")
    print("Valid mission created:")
    print(f"Mission: {mission.mission_name}")
    print(f"ID: {mission.mission_id}")
    print(f"Destination: {mission.destination}")
    print(f"Duration: {mission.duration_days} days")
    print(f"Budget: ${mission.budget_millions:.1f}M")
    print(f"Crew size: {len(mission.crew)}")
    print("Crew members:")
    for member in mission.crew:
        print(f"- {member.name} ({member.rank.value})-{member.specialization}")
    print("\n=========================================")

    crew = [yannis, felix, nicolas]

    mission = SpaceMission(
        mission_id="M0001",
        mission_name="Operation FIZZBUZZ",
        destination="Planete Prout",
        launch_date=datetime.now(),
        duration_days=361,
        crew=crew,
        mission_status="",
        budget_millions=500000
    )


if __name__ == "__main__":
    try:
        main()

    except Exception as e:
        print("Expected validation error:")
        print(e.errors()[0]["msg"])
