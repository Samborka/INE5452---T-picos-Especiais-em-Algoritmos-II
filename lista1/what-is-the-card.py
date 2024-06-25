def find_card(test_cases):
    results = []
    for idx, cards in enumerate(test_cases, start=1):
        pile = cards.split()
        hand = pile[-25:]
        pile = pile[:-25]
        y = 0
        for _ in range(3):
            top_card = pile.pop()
            if top_card[0] in '23456789':
                x = int(top_card[0])
            else:
                x = 10
            y += x
            pile = pile[:-10+x]
        target_card = pile[-y]
        results.append(f"Case {idx}: {target_card[0]}{target_card[1]}")
    return results

# Reading input
num_test_cases = int(input())
test_cases = []
for _ in range(num_test_cases):
    cards = input().strip()
    test_cases.append(cards)

# Finding the target card for each test case
output = find_card(test_cases)

# Printing the output
for result in output:
    print(result)
