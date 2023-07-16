
def tower_of_hanoi(n, source, auxiliary, destination):
    if n == 1:
        print(source, destination)
        return 1
    else:
        moves = 0
        moves += tower_of_hanoi(n-1, source, destination, auxiliary)
        print(source, destination)
        moves += 1
        moves += tower_of_hanoi(n-1, auxiliary, source, destination)
        return moves

n = int(input())
print(tower_of_hanoi(n, 1, 2, 3))
