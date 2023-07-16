
import heapq

def get_medians(arr, k):
    n = len(arr)
    result = []
    max_heap = []
    min_heap = []

    for i in range(n):
        # Add element to the heaps
        if i >= k:
            # Remove the first element of the window from the heaps
            if arr[i - k] <= -max_heap[0]:
                # Remove from max-heap
                max_heap.remove(-arr[i - k])
                heapq.heapify(max_heap)
            else:
                # Remove from min-heap
                min_heap.remove(arr[i - k])
                heapq.heapify(min_heap)

        if not max_heap or arr[i] <= -max_heap[0]:
            # Add to max-heap
            heapq.heappush(max_heap, -arr[i])
        else:
            # Add to min-heap
            heapq.heappush(min_heap, arr[i])

        # Balance the heaps
        if i >= k - 1:
            if len(max_heap) > len(min_heap) + 1:
                # Move the top element of max-heap to min-heap
                heapq.heappush(min_heap, -heapq.heappop(max_heap))
            elif len(min_heap) > len(max_heap):
                # Move the top element of min-heap to max-heap
                heapq.heappush(max_heap, -heapq.heappop(min_heap))

            # Calculate the median
            if k % 2 == 0:
                median = (-max_heap[0] + min_heap[0]) / 2
            else:
                median = -max_heap[0]

            result.append(int(median))

    return result

# Read input
n, k = map(int, input().split())
arr = list(map(int, input().split()))

# Get medians
medians = get_medians(arr, k)

# Print medians
print(*medians)
