
n = int(input())
games = list(map(int, input().split()))

players = [(i+1, games[i]) for i in range(n)]
players.sort(key=lambda x: x[1], reverse=True)

pairs = []
while len(players) > 1:
    player1 = players[0]
    player2 = players[-1]
    if player1[1] == 0 or player2[1] == 0:
        break
    pairs.append((player1[0], player2[0]))
    players[0] = (player1[0], player1[1] - 1)
    players[-1] = (player2[0], player2[1] - 1)
    players.sort(key=lambda x: x[1], reverse=True)

if len(pairs) == n // 2:
    print(len(pairs))
    for pair in pairs:
        print(pair[0], pair[1])
else:
    print("IMPOSSIBLE")
