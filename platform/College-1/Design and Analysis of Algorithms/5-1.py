import sys

# Function to calculate the minimum cost using Branch and Bound method
def calculate_min_cost(cost_matrix):
    n = len(cost_matrix)
    
    # Initialize variables
    min_cost = sys.maxsize
    assigned_jobs = [-1] * n
    visited = [False] * n
    
    # Helper function to calculate the cost recursively
    def calculate_cost(worker, current_cost):
        nonlocal min_cost
        
        # If all workers are assigned jobs, update the minimum cost
        if worker == n:
            min_cost = min(min_cost, current_cost)
            return
        
        # Explore all jobs for the current worker
        for job in range(n):
            if not visited[job]:
                visited[job] = True
                assigned_jobs[worker] = job
                
                # Calculate the cost for the current assignment
                calculate_cost(worker + 1, current_cost + cost_matrix[worker][job])
                
                # Backtrack
                visited[job] = False
                assigned_jobs[worker] = -1
    
    # Start calculating the cost from the first worker
    calculate_cost(0, 0)
    
    return min_cost

# Cost matrix representing the cost of assigning jobs to workers
cost_matrix = [
    [9, 2, 7, 8],
    [6, 4, 3, 7],
    [5, 8, 1, 8],
    [7, 6, 9, 4]
]

# Calculate and print the minimum cost
min_cost = calculate_min_cost(cost_matrix)
print(f"The minimum cost of assigning jobs is: {min_cost}")
