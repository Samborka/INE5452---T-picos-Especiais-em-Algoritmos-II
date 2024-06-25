def last_person_leave_double_escalator(N, arrivals):
    last_leave_time = 0
    current_time = 0
    for time, direction in arrivals:
        if direction == 0:  # Moving from left to right
            last_leave_time = max(last_leave_time + 5, time + 10)
        else:  # Moving from right to left
            last_leave_time = max(last_leave_time + 10, time + 15)
    return last_leave_time

# Input
N = int(input())
arrivals = []
for _ in range(N):
    t, d = map(int, input().split())
    arrivals.append((t, d))

# Calculating the last leave time
last_leave_time = last_person_leave_double_escalator(N, arrivals)

# Output
print(last_leave_time)
