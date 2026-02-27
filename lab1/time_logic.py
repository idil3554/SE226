total_seconds = int(input("Enter total seconds"))
hours = total_seconds // 3600
remaining = total_seconds % 3600

minutes = remaining // 60
seconds = remaining % 60

print(str(total_seconds) + " seconds is " + str(hours) + " hours, " + str(minutes) + " minutes, and " + str(seconds) + " seconds." )
