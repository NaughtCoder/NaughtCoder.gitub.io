import itertools
import sys
import crypt

def main():
    if len(sys.argv) != 2:
        print("Usage: python crack.py hash", file=sys.stderr)
        return 1


    word = []
    for c in sys.argv[1][0:2]:
        word.append(c)

    salt = ''.join(str(c) for c in word)


    chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

    ones_letter = [''.join(x) for x in itertools.product(chars, repeat=1)]
    twos_letter = [''.join(x) for x in itertools.product(chars, repeat=2)]
    threes_letter = [''.join(x) for x in itertools.product(chars, repeat=3)]
    fours_letter = [''.join(x) for x in itertools.product(chars, repeat=4)]

    for one_letter in ones_letter:
        oneword_password = crypt.crypt(one_letter, salt)
        if oneword_password == sys.argv[1]:
            print(one_letter)
            return 0

    for two_letter in twos_letter:
        twoword_password = crypt.crypt(two_letter, salt)
        if twoword_password == sys.argv[1]:
            print(two_letter)
            return 0

    for three_letter in threes_letter:
        threeword_password = crypt.crypt(three_letter, salt)
        if threeword_password == sys.argv[1]:
            print(three_letter)
            return 0

    for four_letter in fours_letter:
        fourword_password = crypt.crypt(four_letter, salt)
        if fourword_password == sys.argv[1]:
            print(four_letter)
            return 0

    print("Dammit, did not crack password!")

if __name__ == "__main__":
    main()