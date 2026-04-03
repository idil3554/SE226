#Question 1
def factorial(x):
    if x == 0 or x ==1:
        return 1
    return x * factorial(x - 1)

#Question 2
abs_val = lambda x: x if x >= 0 else -x

def exp_x(x, n):
    total_sum = 0
    for i in range(n) :
        power_term = x ** (2 * i)
        denom_term = factorial(2 * 1)
        term = power_term / denom_term

        if i % 2 == 0:
            total_sum += term
        else:
            total_sum -= term

    return total_sum

#Question 3
result_gn = 0

def calculate_gn(n,r):
    global result_gn
    if n < 0:
        return

    result_gn += r ** n
    calculate_gn(n-1, r)


    #For TEST

# for second quesiton
x_input = float(input("Enter x: "))
n_input = int(input("Enter n: "))
print(f"Question 2 result is {exp_x(x_input, n_input)}")

# for third question
r_input = float(input("Enter r: "))
calculate_gn(n_input, r_input)
print(f"Question 3 result is {result_gn}")
