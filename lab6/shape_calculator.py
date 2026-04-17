import  geometry_utils

def run_calculator() :
    print("Available shapes: circle, rectangle, triangle")
    print("Available calculations: _area, _perimeter (e.g., circle_area)")

    operation = input("Enter the operation you want to perform: ").strip().lower()

    functions = {
        "circle_area" :
            geometry_utils.circle_area,
        "circle_perimeter" :
            geometry_utils.circle_perimeter,
        "rectangle_area" :
            geometry_utils.rectangle_area,
        "rectangle_perimeter" :
            geometry_utils.rectangle_perimeter,
        "triangle_area" :
            geometry_utils.triangle_area,
    }

    if operation not in functions:
        print("Invalid operation")
        return

    try:
        if "circle" in operation :
            r = float(input("Enter radius : "))
            result = functions[operation](r)
        elif "rectangle" in operation :
            w = float(input("Enter width : "))
            h = float(input("Enter height : "))
            result = functions[operation](w, h)
        elif "triangle" in operation :
            b = float(input("Enter base : "))
            h = float(input("Enter height : "))
            result = functions[operation](b, h)
        print(f"result : {result:.2f}")

    except ValueError as e:
        print(f"Input error : {e} ")

if __name__ == "__main__" :
    run_calculator()