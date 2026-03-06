n = int(input("Enter a number between 10 and 100: "))

while n < 10 or n > 100:
    print("invalid input")
    n = int(input())

    fizz = 0
    buzz = 0
    fizzbuzz = 0

    for i in range(1, n+1):
        if i % 7 == 0:
            print("(" + str(i) + "is skipped)" )
            continue

        if i % 3 == 0 and i % 5 == 0:
            print("FizzBuzz")
            fizzbuzz += 1

        elif i % 3 == 0:
            print("Fizz")
            fizz += 1

        elif i % 5 == 0:
            print("Buzz")
            buzz += 1

        else:
            print(i)

            print("--- Summary ---")
            print("Fizz count:",fizz)
            print("Buzz count:", buzz)
            print("FizzBuzz count:", fizzbuzz)


