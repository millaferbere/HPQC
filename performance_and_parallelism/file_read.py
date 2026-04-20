import time

start = time.time()

with open("data/output.txt", "r") as f:
    data = f.readlines()

end = time.time()

print(f"Read time: {end - start} seconds")
