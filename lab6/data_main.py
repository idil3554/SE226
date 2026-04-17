from data_package import remove_duplicates, strip_whitespaces, calculate_mean, find_minimum, find_maximum

def main():
    user_input = input("Enter a comma-separated list of numbers (e.g., 12, 5, 12, 8 , 21):")

    try:
        raw_list = user_input.split(",")
        stripped_list = strip_whitespaces(raw_list)
        num_list = [float(x) for x in stripped_list]
        unique_data = remove_duplicates(num_list)
        print(f"Cleaned and unique data : {unique_data}")
        print("-" * 20)
        print(f"Mean : {calculate_mean(unique_data): }")
        print(f"Maximum : {find_maximum(unique_data)} ")
        print(f"Minimum : {find_minimum(unique_data)} ")

    except ValueError :
        print("Data Error:  Please make sure you only enter numbers separated by commas.")

if __name__ == "__main__" :
    main()