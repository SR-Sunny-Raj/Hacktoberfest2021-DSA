# Here head is Top
class Node:
	def __init__(self, data):
		self.data = data
		self.next = None

class Stack:
	def __init__(self):
		self.head = None

	def isEmpty(self):
		if self.head == None:
			return True
		else:
			return False

	def push(self, data):
		if self.head == None:
			self.head = Node(data)
		else:
			newnode = Node(data)
			newnode.next = self.head
			self.head = newnode

	def popS(self):
		if self.isEmpty():
			print("Queue is empty.")
			return None
		else:
			temp = self.head
			self.head = self.head.next
			temp.next = None
			return temp.data

	def peek(self):
		if self.isEmpty():
			print("Queue is empty.")
			return None
		else:
			return self.head.data

	def display(self):
		if self.isEmpty():
			print("Queue is empty.")
		else:
			i = self.head
			print(i.data, "<--- Top")
			i = i.next
			while i != None:
				print(i.data)
				i = i.next

s = Stack()
s.push(1)
s.push(2)
s.push(3)
s.push(4)
s.push(5)
s.display()