
n, x = map(int, input().split())
prices = list(map(int, input().split()))
pages = list(map(int, input().split()))

# Create a list of tuples (price per page, book index)
book_info = [(prices[i] / pages[i], i) for i in range(n)]

# Sort the books based on price per page in non-decreasing order
book_info.sort()

max_pages = 0
total_price = 0

for book in book_info:
    # Check if buying this book exceeds the maximum total price
    if total_price + prices[book[1]] > x:
        break

    # Buy the book and update the total price and maximum number of pages
    total_price += prices[book[1]]
    max_pages += pages[book[1]]

print(max_pages)
