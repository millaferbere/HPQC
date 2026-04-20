import sys

def main():
    try:
        in_arg = int(sys.argv[1])
        multiple = int(sys.argv[2])
    except:
        raise Exception("Usage: python repeat_adder.py [NUM] [NUM]")

    output = 0

    for i in range(in_arg):
        output += multiple

    print(output)

if __name__ == "__main__":
    main()
