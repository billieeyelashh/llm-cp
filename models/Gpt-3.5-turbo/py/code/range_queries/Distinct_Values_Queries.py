
def build_frequency_array(arr):
    freq = {}
    for num in arr:
        if num not in freq:
            freq[num] = 0
        freq[num] += 1
    return freq

def create_bit(n):
    bit = [0] * (n + 1)
    return bit

def update(bit, idx, val):
    while idx < len(bit):
        bit[idx] += val
        idx += idx & -idx

def query(bit, idx):
    count = 0
    while idx > 0:
        count += bit[idx]
        idx -= idx & -idx
    return count

# Read input
n, q = map(int, input().split())
arr = list(map(int, input().split()))

# Build frequency array
freq = build_frequency_array(arr)

# Create BIT
bit = create_bit(n)

# Update BIT with initial frequencies
for num, count in freq.items():
    update(bit, num, count)

# Answer queries
for _ in range(q):
    a, b = map(int, input().split())
    distinct_count = query(bit, b) - query(bit, a - 1)
    print(distinct_count)
