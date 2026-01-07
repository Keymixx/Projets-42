data_batch = [
	{"temp": 22.5, "humidity": 65, "pressure": 1013},
	{"temp": 12, "humidity": 23, "pressure": 1654},
	{"temp": 35, "humidity": 87, "pressure": 990}
	]

for data in data_batch:
	if "temp" in data.keys() and data["temp"] > 30:
		print("caca")