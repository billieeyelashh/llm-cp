
from bisect import bisect_left

# Read the inputs
n, m = map(int, input().split())
ticket_prices = list(map(int, input().split()))
customer_prices = list(map(int, input().split()))

# Sort the ticket prices
ticket_prices.sort()

# Iterate over each customer
for price in customer_prices:
    # Find the index of the ticket price that is just greater than the customer's maximum price
    index = bisect_left(ticket_prices, price)
    
    # If there are no tickets available for the customer, print -1 and continue
    if index == 0:
        print(-1)
        continue
    
    # Decrement the index to get the index of the ticket price that does not exceed the maximum price
    index -= 1
    
    # Remove the ticket price from the list of ticket prices
    del ticket_prices[index]
    
    # Print the price that the customer will pay
    print(ticket_prices[index])
