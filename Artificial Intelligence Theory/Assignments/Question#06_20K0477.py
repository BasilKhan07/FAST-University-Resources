from queue import Queue
import heapq

romania_map = {
    'Arad': {'Zerind': 75, 'Timisoara': 118, 'Sibiu': 140},
    'Zerind': {'Arad': 75, 'Oradea': 71},
    'Oradea': {'Zerind': 71, 'Sibiu': 151},
    'Timisoara': {'Arad': 118, 'Lugoj': 111},
    'Sibiu': {'Arad': 140, 'Oradea': 151, 'Fagaras': 99, 'Rimnicu Vilcea': 80},
    'Lugoj': {'Timisoara': 111, 'Mehadia': 70},
    'Fagaras': {'Sibiu': 99, 'Bucharest': 211},
    'Rimnicu Vilcea': {'Sibiu': 80, 'Pitesti': 97, 'Craiova': 146},
    'Mehadia': {'Lugoj': 70, 'Drobeta': 75},
    'Drobeta': {'Mehadia': 75, 'Craiova': 120},
    'Craiova': {'Drobeta': 120, 'Rimnicu Vilcea': 146, 'Pitesti': 138},
    'Pitesti': {'Rimnicu Vilcea': 97, 'Craiova': 138, 'Bucharest': 101},
    'Bucharest': {'Fagaras': 211, 'Pitesti': 101, 'Giurgiu': 90, 'Urziceni': 85},
    'Giurgiu': {'Bucharest': 90},
    'Urziceni': {'Bucharest': 85, 'Hirsova': 98, 'Vaslui': 142},
    'Hirsova': {'Urziceni': 98, 'Eforie': 86},
    'Eforie': {'Hirsova': 86},
    'Vaslui': {'Urziceni': 142, 'Iasi': 92},
    'Iasi': {'Vaslui': 92, 'Neamt': 87},
    'Neamt': {'Iasi': 87}
}

romania_heuristics = {
    'Arad': 366,
    'Bucharest': 0,
    'Craiova': 160,
    'Drobeta': 242,
    'Eforie': 161,
    'Fagaras': 176,
    'Giurgiu': 77,
    'Hirsova': 151,
    'Iasi': 226,
    'Lugoj': 244,
    'Mehadia': 241,
    'Neamt': 234,
    'Oradea': 380,
    'Pitesti': 100,
    'Rimnicu Vilcea': 193,
    'Sibiu': 253,
    'Timisoara': 329,
    'Urziceni': 80,
    'Vaslui': 199,
    'Zerind': 374,
}

# Breadth First Search
def BreadthFirstSearch(romania_map, romania_heuristics, start, goal):
    frontier = Queue()
    frontier.put(start)
    explored = set()
    paths = {start: [start]}
    costs = {start: 0}
    
    while not frontier.empty():
        current = frontier.get()
        
        if current == goal:
            return [(paths[current], costs[current])]
        
        explored.add(current)
        
        for neighbor, distance in romania_map[current].items():
            new_cost = costs[current] + distance
            if neighbor not in costs or new_cost < costs[neighbor]:
                costs[neighbor] = new_cost
                paths[neighbor] = paths[current] + [neighbor]
                
                priority = new_cost + romania_heuristics[neighbor]
                frontier.put(neighbor)
                
    return []

# Uniform Cost Search
def UniformCostSearch(graph, start, goal):
    frontier = []
    heapq.heappush(frontier, (0, start, []))
    explored = set()  
    while frontier:
        cost, node, path = heapq.heappop(frontier) 
        if node == goal:
            return path + [node], cost
        if node in explored:
            continue
        explored.add(node)
        for neighbor, edge_cost in graph[node].items():
            if neighbor not in explored:
                heapq.heappush(frontier, (cost + edge_cost, neighbor, path + [node]))
    return None, None

# Greedy Best First Search
def GreedyBestFirstSearch(graph, heuristics, start, end):
    visited = []
    path = [(start, [start], 0)]
    while path:
        path.sort(key=lambda x: heuristics[x[0]])
        node, nodes, cost = path.pop(0)
        if node == end:
            return nodes, cost
        
        if node not in visited:
            visited.append(node)
            
            for neighbor, neighbor_cost in graph[node].items():
                if neighbor not in visited:
                    total_cost = cost + neighbor_cost
                    new_nodes = nodes + [neighbor]
                    new_path = (neighbor, new_nodes, total_cost)
                    path.append(new_path)
    return None

# Iterative Deepening Depth First Search
def IterativeDeepeningDepthFirstSearch(src, dest, max_depth, graph, heuristics):
    depth_limit = 0
    while depth_limit <= max_depth:
        print(f"Searching paths up to depth {depth_limit}")
        result = DepthLimitedSearch(src, dest, depth_limit, [], 0, graph, heuristics)
        if result is not None:
            return result
        depth_limit += 1
    return None

def DepthLimitedSearch(node, dest, depth_limit, path, path_cost, graph, heuristics):
    if node == dest:
        path.append(node)
        return path, path_cost
    if depth_limit == 0:
        return None
    path.append(node)
    successors = get_successors(node, graph)
    successors = sorted(successors, key=lambda x: heuristics[x])
    for succ in successors:
        if succ in path:
            continue
        cost = path_cost + graph[node][succ]
        result = DepthLimitedSearch(succ, dest, depth_limit - 1, path, cost, graph, heuristics)
        if result is not None:
            return result
    path.pop()
    return None

def get_successors(node, graph):
    return list(graph[node].keys())


source = input("Enter source city: ")
destination = input("Enter destination city: ")

print('\nBreadth First Search: ')
solution1 = BreadthFirstSearch(romania_map, romania_heuristics, source, destination)
for path, cost in solution1:
    print(f"Path: {' -> '.join(path)}")
    print(f"Cost: {cost}")

print('\nUniform Cost Search: ')
path, cost = UniformCostSearch(romania_map, source, destination)
if path is None:
    print(f"No path found from {source} to {destination}.")
else:
    print(f"Path: {path}")
    print(f"Path cost: {cost}")

print('\nGreedy Best First Search: ')
path, cost = GreedyBestFirstSearch(romania_map, romania_heuristics, source, destination)
print(f"Path: {path}")
print(f"Cost: {cost}")

print("\nIterative Deepining Depth First Search:")
max_depth = int(input('Enter Depth limit: '))
solution4 = IterativeDeepeningDepthFirstSearch(source, destination, max_depth, romania_map, romania_heuristics)
if solution4 is not None:
    path, path_cost = solution4
    print("Path found:")
    print(" -> ".join(path))
    print("Path cost:", path_cost)
else:
    print("Destination not found within max depth.")