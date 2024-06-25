def f_to_c(f: float):
  c = (f - 32) * 5 / 9
  return c

def c_to_f(c: float):
  f = c * 9 / 5 + 32
  return f

number_cases = int(input())
result = []
for _ in range(number_cases):
  c, f = map(int, input().split())
  c_to_f_result = c_to_f(c)
  sum_result = c_to_f_result + f
  result.append(f_to_c(sum_result))

for i in range(len(result)):
  print(f"Case {i + 1}: {result[i]:.2f}")