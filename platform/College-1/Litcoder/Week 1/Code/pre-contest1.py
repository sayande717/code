class Job:
    def __init__(self, id, deadline, profit):
        self.id = id
        self.deadline = deadline
        self.profit = profit

def job_scheduling(jobs):
    jobs.sort(key=lambda x: x.profit, reverse=True)
    n = len(jobs)
    result = [False] * n
    job_sequence = [''] * n

    # if n = 5, job,deadline = 2, search for free slots from 2 to 0
    # whenever you find a free slot, put the job in the slot:
    # > result[j] = True
    # > job_sequence[j] = (current) job.id
    for job in jobs:
        for j in range(min(n, job.deadline) - 1, -1, -1):
            if not result[j]:
                result[j] = True
                job_sequence[j] = job.id
                break

    # remove the empty elements from job_sequence, and return the list
    # [] = list, `if job` = if job exists, put the job.
    return [job for job in job_sequence if job]

num_jobs = int(input())
job_ids = input().split()
deadlines = list(map(int, input().split()))
profits = list(map(int, input().split()))

# enter values in the job class
jobs = [Job(job_ids[i], deadlines[i], profits[i]) for i in range(num_jobs)]

optimal_sequence = job_scheduling(jobs)
for index in range(len(optimal_sequence)):
    print(f'{optimal_sequence[index]} ', end='')
