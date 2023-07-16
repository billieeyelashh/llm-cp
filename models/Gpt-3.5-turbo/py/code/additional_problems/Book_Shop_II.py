
n, x = map(int, input().split())
prices = list(map(int, input().split()))
pages = list(map(int, input().split()))
copies = list(map(int, input().split()))

# Create a list of (price per page, book index) tuples
book_ratios = [(prices[i] / pages[i], i) for i in range(n)]
book_ratios.sort()

total_pages = 0
total_price = 0

for ratio, book_index in book_ratios:
    max_copies = min(copies[book_index], (x - total_price) // prices[book_index])
    total_pages += max_copies * pages[book_index]
    total_price += max_copies * prices[book_index]

print(total_pages)
