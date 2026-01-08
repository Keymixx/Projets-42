from abc import ABC, abstractmethod
from typing import Any, List, Dict, Union, Optional

class DataStream(ABC):
    def __init__(self, stream_id: str) -> None:
        self.stream_id = stream_id

    @abstractmethod
    def process_batch(self, data_batch: List[Any]) -> str:
        pass

    def filter_data(self, data_batch: List[Any], criteria:
                Optional[str]= None) -> List[Any]:
        pass

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        pass


class SensorStream(DataStream):
    def __init__(self, stream_id: str) -> None:
        super().__init__(stream_id)
        self.total_processed = 0
        self.critical = 0


    def process_batch(self, data_batch: List[Any]) -> str:
        
        processed = 0
        data_batch = self.filter_data(data_batch)
        for data in data_batch:
            if data.get("temp", 0) > 40:
                self.critical += 1
            if data.get("humidity", 0) > 80:
                self.critical += 1
            if data.get("pressure", 1000) < 990:
                self.critical += 1
            processed += 1
            
        self.total_processed += processed
        count_temp = sum(1 for d in data_batch if isinstance(d, Dict) and "temp" in d)
        total_temp = sum(d["temp"] for d in data_batch if isinstance(d, Dict) and "temp" in d)
    
        if count_temp == 0:
            return f"{processed} readings processed, no temperature find"
        avg = total_temp / count_temp
        return f"{processed} readings processed, avg temp: {avg:.2f}°C"
        


    def filter_data(self, data_batch: List[Any], criteria:
                Optional[str]= None) -> List[Any]:

        filtred_data = []

        for data in data_batch:
            if not isinstance(data, Dict):
                continue

            critic = False
            if any(d in data.keys() for d in ["temp", "humidity", "pressure"]):
                try:
                    if data.get("temp", 0) > 40:
                        critic = True
                    if data.get("humidity", 0) > 80:
                        critic = True
                    if data.get("pressure", 1000) < 990:
                        critic = True

                    if criteria == "critical" and critic == True:
                        filtred_data.append(data)
                    elif criteria == None:
                        filtred_data.append(data)

                except TypeError:
                    print("Value must be numeric")

        return filtred_data

    
    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        return {
            "critical": self.critical,
            "stream_id": self.stream_id,
            "total_processsed": self.total_processed
        }


class TransactionStream(DataStream):
    def __init__(self, stream_id: str) -> None:
        super().__init__(stream_id)
        self.wallet = 0
        self.total_operation = 0
        self.total_large_trans = 0


    def process_batch(self, data_batch: List[Any]) -> str:
        
        operation = 0
        net_flow = 0

        data_batch = self.filter_data(data_batch)
        for data in data_batch:	
            if "sell" in data.keys():
                if data.get("sell", 0) > 1000:
                    self.total_large_trans += 1
                net_flow -= data["sell"]
                operation += 1
            
            if "buy" in data.keys():
                if data.get("buy", 0) > 1000:
                    self.total_large_trans += 1
                net_flow += data["buy"]
                operation += 1
        
        self.total_operation += operation
        self.wallet += net_flow
        
        if net_flow <= 0:
            return f"{operation} operations, net flow: {net_flow} units"
        else:
            return f"{operation} operations, net flow: +{net_flow} units"



    def filter_data(self, data_batch: List[Any], criteria:
                Optional[str]= None) -> List[Any]:
        
        filtred_data = []

        for data in data_batch:
            if not isinstance(data, Dict):
                continue

            critic = False
            if any(d in data.keys() for d in ["sell", "buy"]):
                try:
                    if data.get("sell", 0) > 1000:
                        critic = True
                    if data.get("buy", 0) > 1000:
                        critic = True
                    
                    if criteria == "critical" and critic == True:
                        filtred_data.append(data)
                    elif criteria == None:
                        filtred_data.append(data)

                except TypeError:
                    print("Value must be numeric")

        return filtred_data
    
    def get_stats(self) -> Dict[str, Union[str, int, float]]:

        return {
            "wallet": self.wallet,
            "total_large_trans": self.total_large_trans,
            "total_operation": self.total_operation
        } 


class EventStream(DataStream):
    def __init__(self, stream_id: str) -> None:
        super().__init__(stream_id)
        self.error_event = 0
        self.total_event = 0

    def process_batch(self, data_batch: List[Any]) -> str:
        
        event = 0
        error_event = 0

        for data in data_batch:
            if not isinstance(data, str):
                continue
            if any(d in data for d in ["error", "login", "logout"]):
                event += 1
                if data == "error":
                    error_event += 1
            
        return f"{event} events, {error_event} error detected"


    def filter_data(self, data_batch: List[Any], criteria:
                Optional[str]= None) -> List[Any]:
        
        filtred_data = []

        for data in data_batch:
            if not isinstance(data, str):
                continue

            if any(d in data for d in ["error", "login", "logout"]):
                try:
                    if data == "error":
                        self.error_event += 1
                    filtred_data.append(data)

                except TypeError:
                    print("Value must be a strinh")

        return filtred_data
    
    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        return {
            "total_event": self.total_event,
            "error_event": self.error_event
        }

class StreamProcessor(DataStream):
    def __init__(self) -> None:
        self.streams = []

    def add_stream(self, stream: str) -> None:
        self.streams.append(stream)
        
    def process_batch(self, data_batch: List[Any]) -> str:
        all_process = ""
        for stream in self.streams:
            all_process += f"- {stream.process_batch(data_batch)}\n"
        return all_process

    def filter_data(self, data_batch: List[Any], criteria:
                Optional[str]= None) -> List[Any]:
        
        filtred_data = []

        for stream in self.streams:
            filtred_data.append(stream.filter_data(data_batch, criteria))
        
        return filtred_data
    
    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        stats = {}
        
        for stream in self.streams:
            stats.update(stream.get_stats())
        return stats
    
    def filter_result(self, filter: str) -> str:
        if filter == "High-priority":
            stats = self.get_stats()
            return f"{stats['critical']} critical sensor alerts, {stats['total_large_trans']} large transaction"
        else:
            return "Invalid filter"
            


def main():
    print("=== CODE NEXUS - POLYMORPHIC STREAM SYSTEM ===")

    batch = [
        {"temp": 22.5},
        {"buy": 100},
        {"sell": 150},
        {"humidity": 65},
        None,
        {"pressure": 1013, "buy": 320},
        "login",
        "error"
    ]

    print("\nInitializing Sensor Stream...")
    print("Stream ID: SENSOR_001, Type: Environmental Data")

    sensor1 = SensorStream("SENSOR_001")
    
    print(f"Processing sensor batch: {sensor1.filter_data(batch)}")
    print(f"Sensor analysis: {sensor1.process_batch(batch)}")

    print("\nInitializing Transaction Stream...")
    print("Stream ID: TRANS_001, Type: Financial Data")
    
    trans1 = TransactionStream("TRANS_001")

    print(f"Processing trans batch: {trans1.filter_data(batch)}")
    print(f"Trans analysis: {trans1.process_batch(batch)}")

    print("\nInitializing Event Stream...")
    print("Stream ID: EVENT_001, Type: System Events")
    
    event1 = EventStream("EVENT_001")

    print(f"Processing event batch: {event1.filter_data(batch)}")
    print(f"Event analysis: {event1.process_batch(batch)}")

    print("\n=== Polymorphic Stream Processing ===")
    print("Processing mixed stream types through unified interface...")
    
    manag1 = StreamProcessor()
    
    event2 = EventStream("EVENT_002")
    trans2 = TransactionStream("TRANS_002")
    sensor2 = SensorStream("SENSOR_002")

    manag1.add_stream(event2)
    manag1.add_stream(trans2)
    manag1.add_stream(sensor2)

    mixed_batch = [
        {"temp": 22.5},
        {"buy": 100},
        {"sell": 150},
        {"humidity": 65},
        {"pressure": 1013, "buy": 320},
        "login",
        "error",
        "logout",
        {"temp": 2.5},
        {"temp": 40.5},
        {"humidity": 65},
        {"humidity": 65},
        {"buy": 320},
        {"buy": 2420},
        {"buy": 3520},
        {"sell": 1505},
        {"sell": 1000},
        "login",
        {"pressure": 809}
    ]

    print("\nBatch result:")
    print(manag1.process_batch(mixed_batch))

    print("Stream filtering active: High-priority data only")
    print(manag1.filter_result("High-priority"))

    print("\nAll streams processed successfully. Nexus throughput optimal.")

if __name__ == "__main__":
    main()