from typing import Any, List, Dict, Union, Optional
from abc import	ABC, abstractmethod

class DataProcessor(ABC):
	
	@abstractmethod
	def process(self, data: Any) -> str:
		pass

	@abstractmethod
	def validate(self, data: Any) -> bool:
		pass

	def format_output(self, result: str) -> str:
		return f"Output: {result}"

class NumericProcessor(DataProcessor):
	def validate(self, data: Any) -> bool:
		if isinstance(data, list):
			for number in data:
				if not isinstance(number, (int, float)):
					return False
			return True
		elif isinstance(data, int):
			return True
		return False


	def process(self, data: Any) -> str:
		
		if self.validate(data):
			if isinstance(data, (int, float)):
				nb_values = 1
				tot = data
				avg = data
			else:
				nb_values = len(data)
				tot = sum(data)
				avg = tot / nb_values
		else:
			return

		return f"Processed {nb_values} numeric values, sum={tot}, avg={avg}"


class TextProcessor(DataProcessor):
	def validate(self, data: Any) -> bool:
		if isinstance(data, str):
			split_data = data.split()
			if split_data[0] in ("ERROR:", "INFO:", "WARNING:") :
				return False
			return True
		return False

	def process(self, data: Any) -> str:
		if self.validate(data):
			nb_char = len(data)
			nb_words = len(data.split())
			return f"Processed text: {nb_char} characters, {nb_words} words"


class LogProcessor(DataProcessor):
	def validate(self, data: Any) -> bool:
		if isinstance(data, str):
			split_data = data.split()
			if split_data[0] in ("ERROR:", "INFO:", "WARNING:") :
				return True
			return False
		return False 
	
	def process(self, data: Any) -> str:
		if self.validate(data):
			split_data = data.split()
			if split_data[0] == "ERROR:":
				prefix = "[ALERT] ERROR level detected: "
				data = data.strip("ERROR: ")
			elif split_data[0] == "INFO:":
				prefix = "[INFO] INFO level detected: "
				data = data.strip("INFO: ")
			elif split_data[0] == "WARNING:":
				prefix = "[WARNING] WARNING level detected: "
				data = data.strip("WARNING: ")
			
			return f"{prefix}{data}"
		else:
			return


def main():
	print("=== CODE NEXUS - DATA PROCESSOR FOUNDATION ===")

	# ========Numeric Processor test=========
	print("\nInitializing Numeric Processor...")
	NumProcess = NumericProcessor()
	data = [1, 2, 3, 4, 5]
	print(f"Processing data: {data}")
	if NumProcess.validate(data):
		print("Validation: Numeric data verified")
		print(NumProcess.format_output(NumProcess.process(data)))
	else:
		print("Validation: Invalid data")

	# ========Text Processor test=========
	print("\nInitializing Text Processor...")
	TextProcess = TextProcessor()
	data = "Hello Nexus World"
	print(f'Processing data: "{data}"')
	if TextProcess.validate(data):
		print("Validation: Text data verified")
		print(TextProcess.format_output(TextProcess.process(data)))
	else:
		print("Validation: Invalid data")
	
	# ========Log Processor test=========
	print("\nInitializing Log Processor...")
	LogProcess = LogProcessor()
	data = "ERROR: Connection timeout"
	print(f'Processing data: "{data}"')
	if LogProcess.validate(data):
		print("Validation: Log entry verified")
		print(LogProcess.format_output(LogProcess.process(data)))
	else:
		print("Validation: Invalid data")
	
	# ========Polymorphic Processor test=========
	print("\n=== Polymorphic Processing Demo ===")
	print("Processing multiple data types through same interface...")
	datas = ["Coucou tout le monde !", [2, 5, 1, 8, 4], "INFO: System ready"]
	processors = [LogProcess, TextProcess, NumProcess]

	for data in datas:
		i = 0
		for processor in processors:
			if processor.validate(data):
				i += 1
				print(f"Result {i}: {processor.process(data)}")

	print("\nFoundation systems online. Nexus ready for advanced streams.")


if __name__ == "__main__":
	main()
