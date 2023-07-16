
# read the number of queries
q = int(input())

# iterate through each query
for _ in range(q):
    # read the values of n and k
    n, k = map(int, input().split())
    
    # calculate the position of the k-th child in the original circle
    position = (k - 1) % n + 1
    
    # print the answer for the query
    print(position)
