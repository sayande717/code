file = ""
last = ""

def insert(value):
    global file
    global last
    last = file
    file = file + value

def delete(value):
    global file
    global last
    last = file
    file = file[:len(file) - value]

def get(value):
    global file
    return file[value - 1]

def undo():
    global file
    global last
    file = last

commands = input().split(',')
for command in commands:
    current_command = command.split(' ')
    choice = int(current_command[0])
    
    if choice == 1:
        value = current_command[1]
        insert(value)
    else:
        value = int(current_command[1])
        if choice == 2:
            delete(value)
        elif choice == 3:
            print(get(value))
        elif choice == 4:
            undo()
