import time
import sys

if len(sys.argv) != 2:
    print("Usage: python file_write.py [N]")
    exit()

n = int(sys.argv[1])

start = time.time()

with open("data/output.txt", "w") as f:
    for i in range(n):
        f.write(f"{i}\n")

end = time.time()

print(f"Write time: {end - start} seconds")
