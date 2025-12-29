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
	def validate(self, data) -> bool:
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
	def validate(self, data) -> bool:
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
			elif split_data[0] == "INFO":
				prefix = "[INFO] INFO level detected: "
			elif split_data[0] == "WARNING":
				prefix = "[WARNING] WARNING level detected: "
			
			return f"{prefix}{split_data[1:]}"
		else:
			return

		
print("=== CODE NEXUS - DATA PROCESSOR FOUNDATION ===\n")

NumProcess = NumericProcessor()
print(NumProcess.format_output(NumProcess.process([1, 2, 3, 4, 5])))

TextProcess = TextProcessor()
print(TextProcess.format_output(TextProcess.process("Hello Nexus World")))

LogProcess = LogProcessor()
print(LogProcess.format_output(LogProcess.process("ERROR: Connection timeout")))
