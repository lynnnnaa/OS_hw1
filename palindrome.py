import sys

def main():
    max_pali = ""
    while True:
        line = sys.stdin.readline()
        line = line.lower()
        if len(line) == 0: break
        words = line.split()
        for word in words:
            if len(word) <= len(max_pali):
                continue
            if word == word[::-1]:
                max_pali = word
    print(f"Largest palindrome: {max_pali}")

main()
