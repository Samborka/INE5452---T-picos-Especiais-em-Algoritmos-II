def calculate_score(cards):
    score = sum(min(card, 10) for card in cards)
    return score

def find_lowest_winning_card(N, john_cards, mary_cards, common_cards):
    # Calcular a pontuação atual de John e Mary
    john_score = calculate_score(john_cards)
    mary_score = calculate_score(mary_cards)

    # Adicionar as cartas comuns à pontuação de cada jogador
    for card in common_cards:
        john_score += min(card, 10)
        mary_score += min(card, 10)

    # Encontrar o valor mínimo da carta para Mary vencer
    lowest_card = -1
    for card in range(1, 14):
        if mary_score + min(card, 10) <= 23:
            lowest_card = card

    return lowest_card

N = int(input())
john_cards = list(map(int, input().split()))
mary_cards = list(map(int, input().split()))
common_cards = list(map(int, input().split()))

lowest_card = find_lowest_winning_card(N, john_cards, mary_cards, common_cards)

# Output do resultado
print(lowest_card)
