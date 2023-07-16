
from heapq import *

n = int(input())
customers = []

for _ in range(n):
    a, b = map(int, input().split())
    customers.append((a, b))

# Sort customers based on arrival day
customers.sort()

# Initialize a heap to keep track of the departure days of customers in each room
rooms = []
room_allocations = []

for customer in customers:
    a, b = customer

    if rooms and rooms[0] <= a:
        # If there is an available room, assign the customer to that room
        _, room_number = heappop(rooms)
    else:
        # Otherwise, assign the customer to a new room
        room_number = len(rooms) + 1

    # Add the customer's departure day to the heap
    heappush(rooms, (b, room_number))
    
    # Keep track of room allocations
    room_allocations.append(room_number)

# Print the minimum number of rooms required
print(len(rooms))

# Print the room number for each customer
print(*room_allocations)
