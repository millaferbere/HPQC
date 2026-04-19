import time

start = time.time()

with open("performance_parallelism/data/output.txt", "r") as f:
    data = f.read()

end = time.time()

print("Characters read:", len(data))
print("Read time:", end - start)
