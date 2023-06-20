import sys

stack = []

def push(arg):
    stack.append(arg)

def pall():
    for item in reversed(stack):
        print(item)

def process_instruction(instruction):
    opcode = instruction[0]
    if opcode == 'push':
        push(instruction[1])
    elif opcode == 'pall':
        pall()
    # Add more opcode handlers as needed

def parse_file(file_path):
    line_number = 0
    with open(file_path, 'r') as file:
        for line in file:
            line_number += 1
            line = line.strip()
            if line and not line.startswith('#'):
                try:
                    instruction = line.split()
                    process_instruction(instruction)
                except IndexError:
                    print(f'Error: Invalid instruction at line {line_number}')
                    sys.exit(1)

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print('USAGE: monty file')
        sys.exit(1)
    file_path = sys.argv[1]
    try:
        parse_file(file_path)
    except FileNotFoundError:
        print(f"Error: Can't open file {file_path}")
        sys.exit(1)

