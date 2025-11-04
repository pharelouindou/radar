import sys

def read_friendships(file_path):
    friendships = {}
    try:
        with open(file_path, 'r') as file:
            for line in file:
                parts = line.strip().split(" is friends with ")
                if len(parts) != 2:
                    continue     
                person1, person2 = parts
                friendships.setdefault(person1, []).append(person2)
                friendships.setdefault(person2, []).append(person1)
    except FileNotFoundError:
        print(f"Error: File {file_path} not found.", file=sys.stderr)
        sys.exit(84)
    return friendships


def read_conspiracies(file_path):
    conspiracies = {}
    try:
        with open(file_path, 'r') as file:
            for line in file:
                parts = line.strip().split(" is plotting against ")
                if len(parts) != 2:
                    continue
                plotter, target = parts
                conspiracies.setdefault(plotter, []).append(target)
    except FileNotFoundError:
        print(f"Error: File {file_path} not found.", file=sys.stderr)
        sys.exit(84)

    return conspiracies
