import sys

def calculate_min_cost(cost_matrix):
    n = len(cost_matrix)
    
    min_cost = sys.maxsize
    assigned_jobs = [-1] * n
    visited = [False] * n
    
    def calculate_cost(worker, current_cost):
        nonlocal min_cost
        
        if worker == n:
            min_cost = min(min_cost, current_cost)
            return
        
        for job in range(n):
            if not visited[job]:
                visited[job] = True
                assigned_jobs[worker] = job
                
                calculate_cost(worker + 1, current_cost + cost_matrix[worker][job])
                
                visited[job] = False
                assigned_jobs[worker] = -1
    calculate_cost(0, 0)
    return min_cost

cost_matrix = [
    [9, 2, 7, 8],
    [6, 4, 3, 7],
    [5, 8, 1, 8],
    [7, 6, 9, 4]
]

min_cost = calculate_min_cost(cost_matrix)
print(f"The minimum cost of assigning jobs is: {min_cost}")
