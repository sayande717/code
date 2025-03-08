import queue

class Process:
    def __init__(self, pid, burst_time):
        self.pid = pid
        self.burst_time = burst_time
        self.remaining_time = burst_time

class Scheduler:
    def __init__(self, time_quantum):
        self.time_quantum = time_quantum
        self.process_queue = queue.Queue()
        self.time = 0

    def add_process(self, process):
        self.process_queue.put(process)

    def run(self):
        while not self.process_queue.empty():
            process = self.process_queue.get()
            if process.remaining_time > self.time_quantum:
                print(f"Time {self.time}: Process {process.pid} is running")
                self.time += self.time_quantum
                process.remaining_time -= self.time_quantum
                self.process_queue.put(process)
            else:
                print(f"Time {self.time}: Process {process.pid} is running")
                self.time += process.remaining_time
                process.remaining_time = 0
                print(f"Time {self.time}: Process {process.pid} has finished")

if __name__ == "__main__":
    scheduler = Scheduler(time_quantum=4)
    processes = [Process(pid=1, burst_time=10),
                 Process(pid=2, burst_time=4),
                 Process(pid=3, burst_time=6),
                 Process(pid=4, burst_time=5)]

    for process in processes:
        scheduler.add_process(process)

    scheduler.run()