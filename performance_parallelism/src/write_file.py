import time

n = int(input("Number of lines: "))

start = time.time()

with open("performance_parallelism/data/output.txt", "w") as f:
    for i in range(n):
        f.write(f"This is line {i}\n")

end = time.time()

print("Write time:", end - start)
