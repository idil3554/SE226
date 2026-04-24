class Vehicle:
    def _init_(self, vid, model, year):
        self.vid = vid
        self.model = model
        self.year = int(year)

    def is_new(self, n):
        return self.year >= (2026 - n)

    def _eq_(self, other):
        if isinstance(other, Vehicle):
            return self.vid == other.vid
        return False

    def _str_(self):
        return f"VID: {self.vid} | {self.model} ({self.year})"



class Car(Vehicle):
    def _init_(self, vid, model, year, fuel_type, doors):
        super()._init_(vid, model, year)
        self.fuel_type = fuel_type
        self.doors = doors

    def _str_(self):
        return f"[Car]       " + super()._str_() + f" | Fuel: {self.fuel_type} | {self.doors} Doors"


class Truck(Vehicle):
    def _init_(self, vid, model, year, max_load, axles):
        super()._init_(vid, model, year)
        self.max_load = max_load
        self.axles = axles

    def _str_(self):
        return f"[Truck]     " + super()._str_() + f" | Load: {self.max_load}kg | {self.axles} Axles"


class Motorcycle(Vehicle):
    def _init_(self, vid, model, year, engine_cc, m_type):
        super()._init_(vid, model, year)
        self.engine_cc = engine_cc
        self.m_type = m_type

    def _str_(self):
        return f"[Motorcycle]" + super()._str_() + f" | Eng: {self.engine_cc}cc | Type: {self.m_type}"



def save_fleet_to_file(vehicles, filename):
    with open(filename, 'w') as f:
        for v in vehicles:
            if isinstance(v, Car):
                line = f"Car, {v.vid}, {v.model}, {v.year}, {v.fuel_type}, {v.doors}\n"
            elif isinstance(v, Truck):
                line = f"Truck, {v.vid}, {v.model}, {v.year}, {v.max_load}, {v.axles}\n"
            elif isinstance(v, Motorcycle):
                line = f"Motorcycle, {v.vid}, {v.model}, {v.year}, {v.engine_cc}, {v.m_type}\n"
            f.write(line)


def load_fleet_from_file(filename):
    fleet = []
    try:
        with open(filename, 'r') as f:
            for line in f:
                parts = [p.strip() for p in line.split(',')]
                v_type = parts[0]
                if v_type == "Car":
                    fleet.append(Car(parts[1], parts[2], parts[3], parts[4], parts[5]))
                elif v_type == "Truck":
                    fleet.append(Truck(parts[1], parts[2], parts[3], parts[4], parts[5]))
                elif v_type == "Motorcycle":
                    fleet.append(Motorcycle(parts[1], parts[2], parts[3], parts[4], parts[5]))
        return fleet
    except FileNotFoundError:
        return []


#Main

if _name_ == "_main_":

    initial_fleet = [
        Car("V001", "Tesla Model 3", 2023, "Electric", 4),
        Car("V002", "Toyota Corolla", 2018, "Petrol", 4),
        Truck("T101", "Volvo FH16", 2019, 25000, 6),
        Truck("T102", "Mercedes Actros", 2021, 18000, 4),
        Motorcycle("M301", "Yamaha R1", 2024, 998, "Sport"),
        Motorcycle("M302", "Harley Davidson", 2015, 1200, "Cruiser")
    ]


    save_fleet_to_file(initial_fleet, 'fleet.txt')

    print("Loading fleet data from 'fleet.txt'...")
    loaded_fleet = load_fleet_from_file('fleet.txt')
    print(f"{len(loaded_fleet)} vehicles loaded successfully.\n")


    print("--- All Vehicles ---")
    for v in loaded_fleet:
        print(v)


    print("\n--- Recent Vehicles (Last 4 Years) ---")
    for v in loaded_fleet:
        if v.is_new(4):
            print(v)

    print("\n--- Electric Cars Only ---")
    for v in loaded_fleet:
        if isinstance(v, Car) and v.fuel_type == "Electric":
            print(v)