##
## EPITECH PROJECT, 2024
## G-CNA-400-COT-4-1-gameofstones-germain.dandji
## File description:
## links.py
##

import sys
from collections import deque
from parser import read_friendships

def bfs_shortest_path(graph, start, target):
    if start not in graph or target not in graph:
        return -1

    queue = deque([(start, 0)])
    visited = set()
    while queue:
        person, depth = queue.popleft()

        if person == target:
            return depth  
        if person not in visited:
            visited.add(person)
            for friend in graph.get(person, []):
                if friend not in visited:
                    queue.append((friend, depth + 1))
    return -1  

def links_mode(friends_file, person1, person2):
    friendships = read_friendships(friends_file)
    distance = bfs_shortest_path(friendships, person1, person2)
    print(f"Degree of separation between {person1} and {person2}: {distance}")
