
def fill_grid(n, m):
    if n % 2 == 1 or m % 2 == 1:
        return "NO"
    else:
        grid = [['A' for _ in range(m)] for _ in range(n)]
        for i in range(0, n, 2):
            for j in range(0, m, 2):
                grid[i][j] = 'A'
                grid[i][j+1] = 'B'
                grid[i+1][j] = 'C'
                grid[i+1][j+1] = 'D'
        return "YES\n" + '\n'.join([''.join(row) for row in grid])

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    print(fill_grid(n, m))
