
n = int(input())
cubes = list(map(int, input().split()))

topmost_cubes = []
towers = 0

for cube in cubes:
    placed = False
    for i in range(towers):
        if cube < topmost_cubes[i]:
            topmost_cubes[i] = cube
            placed = True
            break
    
    if not placed:
        towers += 1
        topmost_cubes.append(cube)

print(towers)
