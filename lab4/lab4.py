
num_users = int(input("enter number of users:"))

user_data = { }

for i in range (num_users) :
    username = input("enter username")
    num_items = int(input("How many items?"))

    items = []
    for j in range (num_items) :
        item = input(f"item {j +1}: ")
        items.append(item)

    user_data[username] = items

print("\nUser Data")
for user, items in user_data.items() :
    print(f"{user} -> {items}")

all_items = []
for items in user_data.values():
                all_items.extend(items)
                unique_set = set(all_items)

common_items = []
unique_items = []

for item in unique_set:
     count = all_items.count(item)
     if count > 1:
         common_items.append(item)
     else:
        unique_items.append(item)

max_count = 0
most_popular = []


for item in unique_set:
     count = all_items.count(item)
     if count > max_count:
         max_count = count
         most_popular = [item]
     elif count == max_count:
         most_popular.append(item)

print("\ncommon ıtems:")
for item in common_items:
    print(item)

print("\nunique items")
for item in unique_items:
    print(item)

print("\nmost popular item(s):")
for item in most_popular:
    print(item)