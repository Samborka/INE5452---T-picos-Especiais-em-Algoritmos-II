def calculate_win_average(n, k, games):
    # Inicializar dicionário para armazenar vitórias e derrotas de cada jogador
    win_count = {player: 0 for player in range(1, n+1)}
    loss_count = {player: 0 for player in range(1, n+1)}

    # Processar cada jogo
    for game in games:
        p1, m1, p2, m2 = game
        if m1 == m2:  # Empate
            continue
        elif (m1 == 'rock' and m2 == 'scissors') or \
             (m1 == 'scissors' and m2 == 'paper') or \
             (m1 == 'paper' and m2 == 'rock'):  # p1 ganha
            win_count[p1] += 1
            loss_count[p2] += 1
        else:  # p2 ganha
            win_count[p2] += 1
            loss_count[p1] += 1

    # Calcular e retornar a média de vitórias para cada jogador
    averages = []
    for player in range(1, n+1):
        total_games = k * (n-1)
        if total_games == 0:
            averages.append('-')
        else:
            win_avg = win_count[player] / total_games
            averages.append(round(win_avg, 3))

    return averages

# Input dos casos de teste
while True:
    try:
        n, k = map(int, input().split())
        if n == 0 and k == 0:
            break
        games = []
        for _ in range(k * (n-1)):
            p1, m1, p2, m2 = input().split()
            games.append((int(p1), m1, int(p2), m2))
        averages = calculate_win_average(n, k, games)
        for avg in averages:
            print(avg)
        print()  # Linha vazia entre casos de teste
    except ValueError:
        print("Erro: forneça um input válido.")
