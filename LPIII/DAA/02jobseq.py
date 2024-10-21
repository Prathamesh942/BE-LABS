n = int(input("Enter no of jobs"))
jobs = []
for i in range (n):
    jobId = input("Enter job Id")
    deadline = int(input("Enter deadline"))
    profit = int(input("Enter profit"))
    jobs.append([profit,deadline,jobId])
jobs.sort(reverse=True)
maxDeadline = 0
for job in jobs:
    maxDeadline=max(maxDeadline, job[1])

schedule = [0]*maxDeadline
profit=0

for job in jobs:
    for i in range(job[1]-1,-1,-1):
        if schedule[i]==0:
            schedule[i]=job[2]
            profit+=job[0]
            break

print(schedule, profit)