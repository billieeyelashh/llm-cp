
n = int(input())
playlist = list(map(int, input().split()))

# Set to store unique songs
unique_songs = set()

# Variables to keep track of the current sequence
current_length = 0
max_length = 0

# Sliding window approach
for song in playlist:
    if song in unique_songs:
        # Remove the songs from the beginning of the sequence
        while playlist[current_length] != song:
            unique_songs.remove(playlist[current_length])
            current_length += 1
        # Move the pointer to the next song
        current_length += 1
    else:
        unique_songs.add(song)
    
    # Update the maximum length if necessary
    max_length = max(max_length, len(unique_songs))

print(max_length)
