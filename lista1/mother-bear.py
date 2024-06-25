def is_palindrome(s):
  s = ''.join(c.lower() for c in s if c.isalnum())  # Remove non-alphanumeric characters and convert to lowercase
  return s == s[::-1]  # Check if the string is a palindrome

strings = []
while True:
  line = input()
  if line != "DONE":
    strings.append(line)
  else:
    break

for string in strings:
  if is_palindrome(string):
    print("You won't be eaten!")
  else:
    print("Uh oh..")
