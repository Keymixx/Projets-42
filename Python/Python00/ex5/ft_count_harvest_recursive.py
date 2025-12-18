def ft_count_harvest_recursive():
    days = int(input("Days until harvest: "))

    def print_days(days):
        if days > 1:
            print_days(days - 1)
        print(f"Day {days}")
    if days > 0:
        print_days(days)
    print("Harvest time!")
