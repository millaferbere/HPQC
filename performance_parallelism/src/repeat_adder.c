import sys
import time

# usage: python repeat_adder.py a b
a = int(sys.argv[1])
b = int(sys.argv[2])

start = time.time()

result = 0

# repeated addition: a * b = add a to itself b times
for _ in range(b):
    result += a

end = time.time()

print("Result:", result)
print("Time:", end - start)import sys
import time

# usage: python repeat_adder.py a b
a = int(sys.argv[1])
b = int(sys.argv[2])

start = time.time()

result = 0

# repeated addition: a * b = add a to itself b times
for _ in range(b):
    result += a

end = time.time()

print("Result:", result)
print("Time:", end - start)
