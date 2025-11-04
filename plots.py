import sys
from collections import deque
from parser import read_friendships, read_conspiracies

def floyd_warshall(graph, names, max_depth):
    n = len(names)
    dist = [[float('inf') for _ in range(n)] for _ in range(n)]
    
    for i, person1 in enumerate(names):
        dist[i][i] = 0 
        for j, person2 in enumerate(names):
            if person2 in graph.get(person1, []):
                dist[i][j] = 1 

    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
    
    for i in range(n):
        for j in range(n):
            if dist[i][j] > max_depth:
                dist[i][j] = 0
    
    return dist

def find_direct_enemies(conspiracies, queen="Cersei Lannister"):
    direct_enemies = []
    for plotter, targets in conspiracies.items():
        if queen in targets:
            direct_enemies.append(plotter)
    return direct_enemies

def validate_conspiracies(friendships, conspiracies):
    for person in conspiracies:
        if person not in friendships:
            print(f"Error: Person {person} is in conspiracy file but not in friendship file", file=sys.stderr)
            sys.exit(84)
    
    for person, targets in conspiracies.items():
        for target in targets:
            if target not in friendships:
                print(f"Error: Person {target} is in conspiracy file but not in friendship file", file=sys.stderr)
                sys.exit(84)

def find_conspiracy_chains(friendships, conspiracies, direct_enemies, close_friends, queen="Cersei Lannister"):
    conspiracy_chains = {}
    visited = set() 

    for enemy in direct_enemies:
        chain = find_direct_conspiracy(conspiracies, close_friends, enemy)
        if chain:
            conspiracy_chains[enemy] = chain
            continue
        chain = find_recursive_conspiracy(friendships, conspiracies, close_friends, enemy, visited)
        if chain:
            conspiracy_chains[enemy] = chain
    return conspiracy_chains


def find_direct_conspiracy(conspiracies, close_friends, enemy):
    potential_allies = []
    for friend in close_friends:
        if friend in conspiracies and enemy in conspiracies[friend]:
            is_plotting_against_queen = "Cersei Lannister" in conspiracies.get(friend, [])
            potential_allies.append((friend, is_plotting_against_queen))
    if potential_allies:
        potential_allies.sort(key=lambda x: (x[1], x[0]))
        return [potential_allies[0][0], enemy]
    return None

def find_recursive_conspiracy(friendships, conspiracies, close_friends, target, visited, path=None):
    if path is None:
        path = []
    potential_far_friends = []
    for person in friendships:
        if person not in visited and person in conspiracies and target in conspiracies[person]:
            potential_far_friends.append(person)
    
    if not potential_far_friends:
        return None

    potential_far_friends.sort()
    
    for far_friend in potential_far_friends:
        far_friend_enemies = []
        for p, targets in conspiracies.items():
            if far_friend in targets and p not in visited:
                far_friend_enemies.append(p)
        
        for enemy_of_far_friend in sorted(far_friend_enemies):
            for close_friend in close_friends:
                if close_friend not in visited and close_friend in conspiracies and enemy_of_far_friend in conspiracies[close_friend]:
                    new_visited = visited.copy()
                    new_visited.add(far_friend)
                    new_visited.add(close_friend)
                    new_visited.add(enemy_of_far_friend)
                    return [close_friend, enemy_of_far_friend, far_friend, target]
            new_visited = visited.copy()
            new_visited.add(far_friend)
            recursive_path = find_recursive_conspiracy(friendships, conspiracies, close_friends, enemy_of_far_friend, new_visited)
            if recursive_path:
                return recursive_path + [far_friend, target]
    return None

def plots_mode(friends_file, plots_file, max_depth):
    friendships = read_friendships(friends_file)
    conspiracies = read_conspiracies(plots_file)
    validate_conspiracies(friendships, conspiracies)
    names = sorted(friendships.keys())
    print("Names:")
    for name in names:
        print(name)
    distance_matrix = floyd_warshall(friendships, names, max_depth)
    print()
    print("Relationships:")
    for row in distance_matrix:
        print(" ".join(map(str, row)))
    queen = "Cersei Lannister"
    direct_enemies = find_direct_enemies(conspiracies, queen)
    
    queen_index = names.index(queen)
    close_friends = [names[i] for i in range(len(names)) if distance_matrix[queen_index][i] <= max_depth and distance_matrix[queen_index][i] > 0]

    conspiracy_chains = find_conspiracy_chains(friendships, conspiracies, direct_enemies, close_friends, queen)
    print()
    print("Conspiracies:")
    sorted_chains = []
    for enemy, chain in conspiracy_chains.items():
        if chain:
            sorted_chains.append((len(chain), " -> ".join(chain)))
        sorted_chains.sort(key=lambda x: (x[0], x[1]))
    if sorted_chains:
        for _, chain_str in sorted_chains:
            print(chain_str)
    failed_enemies = [enemy for enemy in direct_enemies if enemy not in conspiracy_chains]
    for enemy in failed_enemies:
        print(f"No conspiracy possible against {enemy}")
    print()
    print("Result:")
    if len(conspiracy_chains) == len(direct_enemies):
        print("The stone is safe!")
    else:
        print("There is only one way out: treason!")