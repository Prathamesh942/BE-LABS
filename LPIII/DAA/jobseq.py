class Job:
    def __init__(self, id, deadline, profit):
        self.id = id
        self.deadline = deadline
        self.profit = profit
  

def job_comparison(job):
    return job.profit


def job_scheduling(jobs):
    jobs.sort(key=job_comparison, reverse=True)

    max_deadline = max(job.deadline for job in jobs)  # Find the maximum deadline
    result = [-1] * (max_deadline + 1)  # Array to keep track of scheduled jobs
    total_profit = 0

    for job in jobs:
        for j in range(min(max_deadline, job.deadline), 0, -1):
            if result[j] == -1:  # If the slot is free
                result[j] = job.id  # Schedule the job
                total_profit += job.profit  # Add to total profit
                break  # Move to the next job

    return total_profit, result


if __name__ == "__main__":
    n = int(input("Enter the number of jobs: "))
    jobs = []

    # Input jobs
    for i in range(n):
        id, deadline, profit = map(int, input(f"Enter job ID, deadline, and profit for job {i + 1}: ").split())
        jobs.append(Job(id, deadline, profit))

    total_profit, scheduled_jobs = job_scheduling(jobs)

    print(f"Total Profit: {total_profit}")
    print("Scheduled Jobs:", end=" ")
    for job_id in scheduled_jobs[1:]:  # Skip index 0
        if job_id != -1:
            print(job_id, end=" ")
    print()
