from abc import ABC, abstractmethod
from typing import Any, List, Dict, Union, Optional, Protocol
import time


class ProcessingStage(Protocol):
    def process(self, data: Any) -> Any:
        ...


class InputStage:
    def process(self, data: Any) -> Dict:
        if data is None:
            raise ValueError("ERROR: Data cannot be None")
        return {"raw": data}


class TransformStage:
    def process(self, data: Any) -> Dict:
        current_data = data["raw"]
        try:
            if isinstance(current_data, Dict):
                data["metadata"] = time.ctime()
                data["validated"] = True

            elif isinstance(current_data, str):
                current_data = current_data.split("\n")
                if len(current_data) == 1:
                    raise ValueError("Just header")
                data["action_cnt"] = len(current_data) - 1

            elif isinstance(current_data, List):
                current_data = [v for v in current_data if isinstance(v, (float, int) )]
                try:
                    data["temp_cnt"] = len(current_data)
                    data["temp_tot"] = sum(current_data)
                except Exception as e:
                    print(f"ERROR1: {e}")

            else:
                raise ValueError("ERROR3")

        except Exception as e:
            print(f"ERROR2: {e}")

        return data


class OutputStage:
    def process(self, data: Any) -> str:
        return data


class ProcessingPipeline(ABC):
    def __init__(self, pipeline_id: str):
        self.pipeline_id = pipeline_id
        self.processed_count = 0
        self.error_count = 0
        self.time_process = 0
        self.stages = []

    def add_stage(self, stage: ProcessingStage):
        self.stages.append(stage)

    @abstractmethod
    def process(self, data: Any) -> Union[str, Any]:
        pass

    def execute_pipeline(self, data: Any) -> Any:
        try:
            for stage in self.stages:
                data = stage.process(data)
                self.processed_count += 1
        except Exception as e:
            print(e)
        return data


class JSONAdapter(ProcessingPipeline):
    def __init__(self, pipeline_id):
        super().__init__(pipeline_id)

    def process(self, data: Any) -> Union[str, Any]:

        if not isinstance(data, Dict):
            raise ValueError("JSON must be a Dict")

        result = self.execute_pipeline(data)

        result = result["raw"]

        temp = result.get("value", 0)
        unit = result.get("unit", "C")
        return f"Processed temperature reading: {temp}°{unit} (Normal range)"


class CSVAdapter(ProcessingPipeline):
    def __init__(self, pipeline_id):
        super().__init__(pipeline_id)

    def process(self, data: Any) -> Union[str, Any]:
        if not isinstance(data, str):
            raise ValueError("CSV must be a string")

        result = self.execute_pipeline(data)

        actions = result.get("action_cnt", 0)
        return f"Output: User activity logged: {actions} actions processed"


class StreamAdapter(ProcessingPipeline):
    def __init__(self, pipeline_id):
        super().__init__(pipeline_id)

    def process(self, data: Any) -> Union[str, Any]:
        if not isinstance(data, List):
            raise ValueError("Stream must be List")

        result = self.execute_pipeline(data)

        temp_cnt = result.get("temp_cnt")
        temp_tot = result.get("temp_tot")
        avg = temp_tot / temp_cnt

        return f" Stream summary: {temp_cnt} readings, avg: {avg:.2f}°C"


class NexusManager:
    def __init__(self):
        self.pipelines = []

    def add_pipeline(self, pipeline):
        self.pipelines.append(pipeline)

    def process_data(self, data):
        pass


def main():
    print("=== CODE NEXUS - ENTERPRISE PIPELINE SYSTEM ===\n")

    print("Initializing Nexus Manager...")
    print("Pipeline capacity: 1000 streams/second\n")

    print("Creating Data Processing Pipeline...")
    print("Stage 1: Input validation and parsing")
    print("Stage 2: Data transformation and enrichment")
    print("Stage 3: Output formatting and delivery\n")

    input_stage = InputStage()
    transorm_stage = TransformStage()
    output_stage = OutputStage()

    json_pipeline = JSONAdapter("JSON_001")
    json_pipeline.add_stage(input_stage)
    json_pipeline.add_stage(transorm_stage)
    json_pipeline.add_stage(output_stage)

    csv_pipeline = CSVAdapter("CSV_001")
    csv_pipeline.add_stage(input_stage)
    csv_pipeline.add_stage(transorm_stage)
    csv_pipeline.add_stage(output_stage)

    stream_pipeline = StreamAdapter("STREAM_001")
    stream_pipeline.add_stage(input_stage)
    stream_pipeline.add_stage(transorm_stage)
    stream_pipeline.add_stage(output_stage)

    print("=== Multi-Format Data Processing ===\n")

    print("\nProcessing JSON data through pipeline..")
    json_data =                                                                                            
    print(f"Input: {json_data}")
    print("Transform: Enriched with metadata and validation")
    print(f"Output: {json_pipeline.process(json_data)}")

    print("\nProcessing CSV data through same pipeline...")
    csv_data = "user,action,timestamp\ncarl,login,10.45.32"
    print(f'Input: "user,action,timestamp"')
    print("Transform: Parsed and structured data")
    print(f"Output: {csv_pipeline.process(csv_data)}")

    print("\nProcessing Stream data through same pipeline...")
    stream_data = [32.4, 42, 14, 24, 21.2]
    print("Input: Real-time sensor stream")
    print("Transform: Aggregated and filtered")
    print(f"Output: {stream_pipeline.process(stream_data)}")


    


if __name__ == "__main__":
    main()
