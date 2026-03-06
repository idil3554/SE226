n = int(input("Enter a number between 3 and 9: "))

while n < 3 or n > 9:
    n = int(input("Enter a number between 3 and 9: "))

    for i in range (1,2*n):
        if i <= n:
            k = i
        else:
            k = 2*n - i
            for j in range (1,k+1):
                print(j, end='')
            print()