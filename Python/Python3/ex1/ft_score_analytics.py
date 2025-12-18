import sys

len_args = len(sys.argv)
if len_args == 1:
	print("No scores provided. Usage: " \
	"python3 ft_score_analytics.py <score1> <score2> ...")
else:
    i = 1
    str_score = ""
    while i < len_args:
        sys.argv[i] = int(sys.argv[i])
        if i == (len_args - 1):
            str_score += f"{sys.argv[i]}"
        else:
            str_score += f"{sys.argv[i]}, "
        i += 1
    print(f"Total players: {len_args - 1}")
    print(f"Total score: {sum(int(sys.argv))}")
    print(f"Average score: {sum(sys.argv) /(len_args - 1)}")