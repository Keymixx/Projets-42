import sys

print("=== Player Score Analytics ===")
len_args = len(sys.argv)

# ===IF NO ARG=====
if len_args == 1:
    print("No scores provided. Usage: " \
    "python3 ft_score_analytics.py <score1> <score2> ...")
    quit()

#====TEST IF IS INT=====
i = 1
try:
    while i < len_args:
          sys.argv[i] = int(sys.argv[i])
          i += 1
except :
    print(f"Oops your type: {sys.argv[i]}!")
    print("its unfortunately not a score...")
    quit()

# =====PRINT SCORE======
str_score = ""
max_score = max(sys.argv[1:])
min_score = min(sys.argv[1:])
tot_score = sum(sys.argv[1:])
i = 1
while i < len_args:
    sys.argv[i] = int(sys.argv[i])
    if i == (len_args - 1):
        str_score += f"{sys.argv[i]}"
    else:
        str_score += f"{sys.argv[i]}, "
    i += 1
print(f"Total players: {len_args - 1}")
print(f"Total score: {tot_score}")
print(f"Average score: {tot_score / (len_args - 1):.1f}")
print(f"High score: {max_score}")
if min_score < 0:
    print(f"Lowest score: {min_score}", end="")
    print("     NEGATIF SCORE????? SERIOUSLY???")
else:
	print(f"Lowest score: {min_score}")
print(f"Score range: {max_score - min_score}")