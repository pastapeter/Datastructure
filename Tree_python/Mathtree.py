from os import remove
import re
from queue import Queue

class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

def inorder(root):
    if root == None:
        return 
    inorder(root.left)
    print(root.data, end="")
    inorder(root.right)

def preorder(root):
    if root == None:
        return 
    print(root.data, end="")
    preorder(root.left)
    preorder(root.right)

def postorder(root):
    if root == None:
        return 
    postorder(root.left)
    postorder(root.right)
    print(root.data, end="")

def levelorder(root):
    queue = Queue()
    queue.put(root)
    while queue.empty() is not True :
        node = queue.get()
        if node is not None:
            print(node.data)
            if node.left is not None:
                queue.put(node.left)
            if node.right is not None:
                queue.put(node.right) 


def makeMathTree(list) -> Node :
    operatorList = {'*':3, '/':3, '+':2, '-':2}
    stack = []
    result = []

    #TODO 후위수식으로 만들기
    for element in list:
        if element.isdigit():
            result += element
        else:
            while(len(stack)!=0 and operatorList[element] <= operatorList[stack[-1]]):
                result += stack.pop()
            stack.append(element)
    while(len(stack)!=0):
        result += stack.pop()


    stack2 = []
    #TODO 후위수식 바탕으로 트리만들기`
    for index in range(0, len(result)):
        if result[index].isdigit() == False:
            op2 = stack2.pop()
            op1 = stack2.pop()
            if(type(op1) is int):
                leftNode = Node(op1)
            else:
                leftNode = op1
            if(type(op2) is int):
                rightNode = Node(op2)
            else:
                rightNode = op2
            motherNode = Node(result[index],leftNode, rightNode)
            stack2.append(motherNode)
        else:
            stack2.append(int(result[index]))

    return stack2.pop()
    
def evaluate(root) -> int:
    if(root == None):
        return 0
    if(root.left == None and root.right == None):
        return root.data
    else:
        op1 = evaluate(root.left)
        op2 = evaluate(root.right)
    if(root.data == '+'):
        return op1+op2
    elif(root.data == '-'):
        return op1-op2
    elif root.data == '*':
        return op1*op2
    else:
        return op1/op2
    return 0

print('Enter the Expression')
expression = input()
list = []
for character in expression:
    list.append(character)

root = makeMathTree(list)
print('값은?')
print(evaluate(root))
print('중위 순회', end="")
inorder(root)
print('\n')
print('전위 순회', end="")
preorder(root)
print('\n')
print('후위 순회', end="")
postorder(root)
print('\n')
print('레벨 순회', end="")
levelorder(root)
