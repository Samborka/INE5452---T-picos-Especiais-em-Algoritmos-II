from collections import Counter

def find_anagrams(phrases):
    anagrams = []
    phrase_counts = [Counter(phrase.replace(' ', '')) for phrase in phrases]

    for i in range(len(phrases)):
        for j in range(i + 1, len(phrases)):
            if phrase_counts[i] == phrase_counts[j]:
                anagrams.append((phrases[i], phrases[j]))

    return anagrams

# Input dos casos de teste
num_test_cases = int(input())
input_lines = []
while True:
    line = input().strip()
    if not line:
        break
    input_lines.append(line)

# Processar cada caso de teste
current_line = 0
for _ in range(num_test_cases):
    if current_line >= len(input_lines):
        break
    num_lines = int(input_lines[current_line])
    phrases = input_lines[current_line + 1: current_line + 1 + num_lines]
    current_line += num_lines + 1

    anagrams = find_anagrams(phrases)

    # Output dos pares de anagramas
    for pair in anagrams:
        print(' = '.join(pair))
    if _ < num_test_cases - 1:
        print()  # Linha em branco entre os casos de teste, exceto o último
