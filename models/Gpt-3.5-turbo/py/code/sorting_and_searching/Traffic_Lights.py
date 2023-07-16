
def calculate_longest_passage(x, n, positions):
    longest_passage = x
    previous_position = 0
    
    for position in positions:
        passage_length = position - previous_position - 1
        longest_passage = max(longest_passage, passage_length)
        previous_position = position
    
        print(longest_passage, end=' ')

    print()


x, n = map(int, input().split())
positions = list(map(int, input().split()))

calculate_longest_passage(x, n, positions)
