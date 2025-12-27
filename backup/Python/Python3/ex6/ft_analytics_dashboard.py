def set_mastery(all_players):
    print("=== Set Comprehension Examples ===")

    unique_player = {player['name'] for player in all_players}
    active_region = {player['region'] for player in all_players}

    total_achievements = set()
    for player in all_players:
        total_achievements.update(player["achievements"])

    rare_achievement = set()
    for achievement in total_achievements:
        count = 0
        for player in all_players:
            if achievement in player["achievements"]:
                count += 1
        if count == 1:
            rare_achievement.update({achievement})
        

    print(f"Unique player: {unique_player}")
    print(f"Active region: {active_region}")
    print(f"Unique achievements: {rare_achievement}")


def list_mastery(all_players):
    
    print("\n=== List Comprehension Examples ===")
    
    online_players = [player['name'] for player in all_players if player['online'] == True]
    high_score = [player['name'] for player in all_players if player['score'] > 4500]
    scores = [player['score'] for player in all_players]

    print(f"All scores: {sorted(scores)}")
    print(f"High scores (>4500): {high_score}")
    print(f"Online Player: {online_players}")


def dict_mastery(all_players):

    print("\n=== Dict Comprehension Examples ===")
    score_player = dict()
    achievements_player = dict()
    score_categorie = {
        "high": 0,
        "medium": 0,
        "low": 0,
    }

    for player in all_players:
        if player["score"] > 4500:
            score_categorie["high"] += 1
        elif player["score"] > 3000:
            score_categorie["medium"] += 1
        else:
            score_categorie["low"] += 1

        name = player["name"]
        score_player[name] = player["score"]
        achievements_player[name] = len(player["achievements"])

    print(f"Player score: {score_player}")
    print(f"Player Achievements: {achievements_player}")
    print(f"Score categorie: {score_categorie}")


def master_mastery(all_players):

    print("\n=== Combined Analysis ===")

    unique_achievements = set()
    for player in all_players:
        achievements = player["achievements"]
        unique_achievements = unique_achievements.union(achievements)
    
    scores = [player['score'] for player in all_players]
    average_score = sum(scores) / len(scores)

    online_players = [player['name'] for player in all_players if player['online'] == True]

    best_online = max(online_players)
    
    best_score_online = [player['score'] for player in all_players if player['name'] == best_online]
    
    
    print(f"Online player: {len(online_players)}")
    print(f"Best Online: {best_online} {best_score_online}")
    print(f"Average score: {average_score:.1f}")


all_achievements = {
    "first_kill",
    "level_10!",
    "treasure_hunter",
    "speed_demon",
    "boss_slayer",
    "collector",
    "fizzbuzz",
    "golem",
    "perfectionist",
    "king",
    "easter_egg"
}


carl = {
    "name": "Carl",
    "achievements": {"fizzbuzz", "boss_slayer", "level_10!", "first_kill"},
    "score": 4200,
    "region": "west",
    "level": 9,
    "online": True
}

hoel = {
    "name": "Hoel",
    "achievements": {"fizzbuzz", "golem", "level_10!", "collector"},
    "score": 6000,
    "region": "east",
    "level": 19,
    "online": False
}

yannis = {
    "name": "Yannis",
    "achievements": {"fizzbuzz", "king", "boss_slayer", "speed_demon"},
    "score": 5500,
    "region": "east",
    "level": 14,
    "online": True
}

felix = {
    "name": "Felix",
    "achievements": {"fizzbuzz"},
    "score": 100,
    "region": "north",
    "level": 3,
    "online": True
}

nicolas = {
    "name": "Nicolas",
    "achievements": {"fizzbuzz", "speed_demon", "first_kill"},
    "score": 3200,
    "region": "north",
    "level": 7,
    "online": False
}


all_players = [carl, yannis, felix, hoel, nicolas]

set_mastery(all_players)
list_mastery(all_players)
dict_mastery(all_players)

master_mastery(all_players)