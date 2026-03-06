n = int(input("Enter a positive integer greater than 9"))
steps = 0
print(n, end=" ")

while n >= 10:
    temp = n
    digit_sum = 0

    while temp > 0:
        digit_sum += temp % 10
        temp //= 10

        n = digit_sum
        steps += 1
    print("->", n, end= " ")

    print()
    print("Final Value :", n)
    print("Total steps:", steps)
