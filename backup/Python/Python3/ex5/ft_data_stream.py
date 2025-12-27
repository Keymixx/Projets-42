import random

def event_stream(nb_event):

    players = ["Carl", "Hoel", "Yannis", "Felix", "Sbonneau", "Nithomas"]
    hooks = ["death", "kill", "quest _complete", "level_up",
            "item_found", "treasure_found", "lost_connexion", "kill_monster"]
    levels = [i for i in range(1,15)]
    
    for i in range(nb_event):
        event = {
            "hook": random.choice(hooks),
            "player": random.choice(players),
            "level": random.choice(levels),
        }
        
        if i < 10:
            print(f"Event {i}: {event['hook']} by {event['player']}", end ="")
            print(f" (level {event['level']})")
            if i == 9:
                print("...")
        
        yield event


def info_stream_event(events):

    death_event = 0
    level_up_event = 0
    total_events = 0
    high_level_players = 0

    for event in events:
        total_events += 1
        if event["hook"] == "death":
            death_event += 1
        if event["level"] > 10:
            high_level_players += 1
        if event["hook"] == "level_up":
            level_up_event += 1

    print("\n=== Stream Analytics ===")
    print(f"Total events processed: {total_events}")
    print(f"High-level players (10+): {high_level_players}")
    print(f"Death events: {death_event}")
    print(f"Level-up events: {level_up_event}")


def event_not_stream(nb_event):

    players = ["Carl", "Hoel", "Yannis", "Felix", "Sbonneau", "Nithomas"]
    hooks = ["death", "kill", "quest _complete", "level_up",
            "item_found", "treasure_found", "lost_connexion", "kill_monster"]
    levels = [i for i in range(1,15)]
    events = []
    for i in range(nb_event):
        event = {
            "hook": random.choice(hooks),
            "player": random.choice(players),
            "level": random.choice(levels),
        }
        if i < 10:
            print(f"Event {i}: {event['hook']} by {event['player']}", end ="")
            print(f" (level {event['level']})")
            if i == 9:
                print("...")
        events.append(event)
    
    return events

def info_not_stream_event(events):

    death_event = 0
    level_up_event = 0
    total_events = 0
    high_level_players = 0

    for event in events:
        total_events += 1
        if event["hook"] == "death":
            death_event += 1
        if event["level"] > 10:
            high_level_players += 1
        if event["hook"] == "level_up":
            level_up_event += 1

    print("\n=== Stream Analytics ===")
    print(f"Total events processed: {total_events}")
    print(f"High-level players (10+): {high_level_players}")
    print(f"Death events: {death_event}")
    print(f"Level-up events: {level_up_event}")

def fibonnaci(nb):
    a = 0
    b = 1
    for _ in range(nb):
        yield a
        a = b
        b = a + b

def is_prime(nb)-> bool:

    i = 2
    if nb < 2:
        return False
    if nb == 2:
        return True
    for i in range(2,nb):
        if nb % i == 0:
            return False
    return True

def prime_number(nb):
    i = 0
    total_nb = 0
    while total_nb < nb:
        if is_prime(i):
            yield i
            total_nb += 1
            i += 1
        else:
            i += 1

nb_events = 1000

print("=== Game Data Stream Processor ===")
print(f"\nProcessing {nb_events} game events...\n")

events = event_stream(nb_events)
info_stream_event(events)

print("\n#### WITHOUT STREAM ####")
print("\n=== Game Data Without Stream Processor ===")\

events = event_not_stream(nb_events)
info_not_stream_event(events)


print("\n=== Generator Demonstration ===")

seq = 10
fibo = fibonnaci(seq)
print(f"Fibonacci sequence (first {seq}):", end="")
for number in fibo:
    print(f" {number}", end="")
print()

prime = prime_number(seq)
print(f"Prime numbers (first {seq}):", end="")
for number in prime:
    print(f" {number}", end="")
print()

