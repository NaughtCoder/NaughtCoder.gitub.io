import cs50

def main():
    while True:
        print("Enter an integer value between 0 and 23 inclusive: ", end="")
        height = cs50.get_int()
        if height >= 0 and height <= 23:
            break

    print("Height:", height)
    i = 1

    for row in range(height):
        for space in range(height-i):
            print(" ", end="")

        for hash in range(i):
            print("#", end="")

        print("  ", end="")

        for hash in range(i):
            print("#", end="")
        print()
        i+=1


if __name__ == "__main__":
    main()