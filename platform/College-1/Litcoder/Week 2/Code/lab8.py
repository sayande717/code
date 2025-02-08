def get_id(sightings):
    sightings = sorted(sightings)
    freq_dict = {}
    max_freq = 0

    for bird_id in sightings:
        freq_dict[bird_id] = freq_dict.get(bird_id, 0) + 1
        curr_freq = freq_dict.get(bird_id)
        if curr_freq > max_freq:
            max_freq = curr_freq

    for bird_id in freq_dict.keys():
        if freq_dict.get(bird_id) == max_freq:
            print(bird_id, end='')

# Example input (replace with your actual input)
sightings_list = ["3", "2", "4", "3", "2", "5"]
get_id(sightings_list)
