class node:
    def __init__(self,data):
        self.data = data
        self.next = None

class linked_list:
    def __init__(self):
        self.head = None
    
    def add_to_end(self,data):
        new_node = node(data)
        if self.head==None:
            self.head = new_node
            return
        current_node = self.head
        while current_node.next is not None:
            current_node = current_node.next
        current_node.next = self.head

    def remove_from_beginning(self):
        if self.head==None:
            return
        self.head = self.head.next

    def print(self):
        if self.head == None:
            return
        print(self.head.data)

if __name__ == "__main__":
    list = linked_list()
    input_string = input().split(',')
    for command in input_string:
        try:
            part = command.split(' ')
            if part[0] == '1':
                list.add_to_end(part[1])
            elif part[0] == '2':
                list.remove_from_beginning()
            elif part[0] == '3':
                list.print()
            else:
                # Do nothing
                pass
        except IndexError:
            # Do nothing
            pass


