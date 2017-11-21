import cs50
import sys

def main():
    cc_number = input("Number: " )
    if len(str(cc_number)) >= 13 and len(str(cc_number)) <= 16:

        times_two = []
        result = []
        other = []
        timestwo = False

        for digit in cc_number:
            if timestwo == False:
                other.append(int(digit))
                timestwo = True
            else:
                times_two.append(int(digit))
                timestwo = False

        sum_other = sum(other)
        result = [x * 2 for x in times_two]

        poop = []
        for x in result:
            if len(str(x)) is 2:
                for d in str(x):
                    poop.append(int(d))
            else:
                poop.append(int(x))

        sum_poop = sum(poop)
        sum_overall = int(sum_other) + (sum_poop)

        if (sum_overall % 10) == 0:
            if len(str(cc_number)) == 13 and other[0] == 4:
                print("VISA")

            elif len(str(cc_number)) == 15 and other[0] == 3 and times_two[0] == 4 or times_two[0] == 7:
                print("AMEX")

            elif len(str(cc_number)) == 16 and other[0] == 4:
                print("VISA")

            elif len(str(cc_number)) == 16 and other[0] == 5 and times_two[0] == 1 or times_two[0] == 2 times_two[0] == 3
                print("MASTERCARD")

            else:
                print("INVALID", file=sys.stderr)

        else:
            print("INVALID", file=sys.stderr)
    else:
            print("INVALID", file=sys.stderr)
if __name__ == "__main__":
    main()