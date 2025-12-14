print("=== Achievement Tracker System ===\n")

achievements = {
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

carl = {"first_kill", "level_10!", "boss_slayer", "fizzbuzz", "speed_demon"}
yannis = {"first_kill", "treasure_hunter", "perfectionist", "fizzbuzz"}
felix = {"first_kill", "level_10!", "speed_demon", "fizzbuzz", "perfectionist"}
owel = {"fizzbuzz", "golem"}

players = [carl, owel, yannis, felix]

print(f"Player carl achievements: {carl}")
print(f"Player owel achievements: {owel}")
print(f"Player yannis achievements: {yannis}")
print(f"Player felix achievements: {felix}")

print("\n=== Achievement Analytics ===")


i = 0
total_achievement = set()
while i < len(players) - 1:
    temp = players[i].union(players[i + 1])
    total_achievement = total_achievement.union(temp)
    i += 1
print(f"All unique achievement discoverd: {total_achievement}")
print(f"Total unique achievement discoverd: {len(total_achievement)}")

i = 0
while i < len(players) - 1:
    commun_achievment = players[i].intersection(players[i + 1])
    i += 1
print(f"Common to all players: {commun_achievment}")

rare_achievement = set()
for achievement in achievements:
    count = 0
    for player in players:
        if achievement in player:
            count += 1
    if count == 1:
        rare_achievement = rare_achievement.union({achievement})

print(f"Rare achievements (1 player): {rare_achievement}")
print()
print(f"Carl vs Owel common: {carl.intersection(owel)}")
print(f"Carl unique: {carl.difference(owel)}")
print(f"Owel unique: {owel.difference(carl)}")