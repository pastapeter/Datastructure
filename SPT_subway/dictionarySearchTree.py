import random
from typing import overload


dictionaryFile = open("randdict_utf8.TXT", "r")
lines = dictionaryFile.readlines()
print('사전을 모두 읽었습니다. ' + str(len(lines)) + '개의 단어가 있습니다')

class Node:
    def __init__(self, word, meaning, left = None, right = None):
        self.word = word
        self.meaning = meaning
        self.left = left
        self.right = right

class BinaryTree:
    def __init__(self):
        self.head = None
    
    def search(self, data, level):
        if self.head is not None:
            return self.__searchNode(self.head, data, level)
        else:
            return None

    def __searchNode(self, node, target, level):
        while(node is not None):
            if(target == node.word):
                return node, level
            elif target < node.word:
                level += 1
                node = node.left
            else :
                level += 1
                node = node.right
        return None
    
    #TODO 단어 순차적으로 이진탐색트리 민들기
    def insert(self, data):
        if self.head is not None:
            return self.__insertNode(self.head, data)
        else:
            self.head = Node(data.word, data.meaning)
    
    def __insertNode(self, node, target):
        # head값이 크면 왼쪽으로
        if(node.word >= target.word):
            if node.left is not None:
                self.__insertNode(node.left, target)
            else:
                node.left = Node(target.word, target.meaning)
        # head값이 작으면 오른쪽으로
        else:
            if node.right is not None:
                self.__insertNode(node.right, target)
            else:
                node.right= Node(target.word, target.meaning)
    
    def getHeight(self, node) -> int:
        if node is None: return 0
        return 1 + max(self.getHeight(node.left), self.getHeight(node.right))

    def getHeightDiff(self, node):
        if node is None: return False
        leftroot = node.left
        rightroot = node.right
        return self.getHeight(leftroot) - self.getHeight(rightroot)

    def getCount(self, node):
        if node is None:
            return 0
        else:
            return 1 + self.getCount(node.left) + self.getCount(node.right)

class SortedTree(BinaryTree):
    def makeTree(self, left, right):
        if left > right: 
            return
        pivot = (left+right ) // 2
        word, meaning = lines[pivot].split(" : ")
        node1 = Node(word, meaning)
        self.insert(node1)
    
        self.makeTree(left, pivot - 1)
        self.makeTree(pivot+1, right)


class AVLTree(BinaryTree):

    def goLL(self, root): ##왼쪽이 불균형
        child = root.left
        root.left = child.right
        child.right = root
        return child
    
    def goRR(self, root): #오른쪽이 불균형
        child = root.right
        root.right = child.left
        child.left = root
        return child

    def goLR(self, root): #왼쪽의 오린쪽이 불균형
        child = root.left
        root.left = self.goRR(child)
        return self.goLL(root)

    def goRL(self, root):
        child = root.right
        root.right = self.goLL(child)
        return self.goRR(root)

    def rebalancing(self, root):
        diff = self.getHeightDiff(root)

        if diff > 1: #왼쪽에서 오른쪽뺏을때, 1이상이면 왼쪽이 기울었다는 뜻
            if self.getHeightDiff(root.left) > 0:
                root = self.goLL(root)
            else:
                root = self.goLR(root)
        elif diff < -1: #오른쪽이 기울었다.
            if self.getHeightDiff(root.right) < 0:
                root = self.goRR(root)
            else :
                root = self.goRL(root)
        return root #균형을 이룬다는 뜻 

    def insert(self, data):
        if self.head is None:
            self.head = data
        else:
            self.head = self.__insertNode(self.head, data); 
    
    def __insertNode(self, node, target):
        if(node.word > target.word):
            if node.left is not None:
                node.left = self.__insertNode(node.left, target)
            else:
                node.left = Node(target.word, target.meaning)
            return self.rebalancing(node)
        # head값이 작으면 오른쪽으로
        elif(node.word < target.word):
            if node.right is not None:
                node.right = self.__insertNode(node.right, target)
            else:
                node.right= Node(target.word, target.meaning)
            return self.rebalancing(node)
        else:
            print("중복")

def improvedMakeTree(root, left, right): #insert 함수를 쓰지 않아, root 처음부터 내려가면서 insert를 하지않고 바로 옆에다가 자식으로 Node를 생성하는 방법
    if left > right :
        return
    pivot = (left + right) // 2
    root.word, root.meaning = lines[pivot].split(" : ")
                
    if left <= pivot -1 :
        root.left = Node(None, None)
        improvedMakeTree(root.left, left, pivot-1)
    if right >= pivot+1 :
            root.right = Node(None, None)
            improvedMakeTree(root.right, pivot+1, right)

def getHeight(node) -> int:
        if node is None: return 0
        return 1 + max(getHeight(node.left), getHeight(node.right))

def searchNode(node, target, level):
    while(node is not None):
        if(target == node.word):
            return node, level
        elif target < node.word:
            level += 1
            node = node.left
        else :
            level += 1
            node = node.right
    return None


#TODO 파일읽기
root = BinaryTree()
root3 = SortedTree()
root4 = Node(None, None)



for line in lines:
    word, meaning = line.split(" : ")
    node = Node(word, meaning)
    root.insert(node)
    
wordList = [lines[random.randint(0, len(lines)-1)].split(" : ")[0] for index in range(0, 10)]
treeHeight1 = root.getHeight(root.head)

print(f'A 트리의 전체 높이는 {treeHeight1} 입니다.')

print(f'랜덤하게 선택된 단어 10개: {wordList}')

lines.sort()

root3.makeTree(0, len(lines)-1)


improvedMakeTree(root4, 0, len(lines)-1)

treeHeight3 = root3.getHeight(root3.head)
treeHeight4 = getHeight(root4)
print(f'C 트리의 전체 높이는 {treeHeight3} 입니다.')
print(f'D 트리의 전체 높이는 {treeHeight4} 입니다.')



for element in wordList:
    target, level = root.search(element, 0)
    print(f"A 트리 : {target.word} {target.meaning} (레벨 {level})")


for element in wordList:
    target, level = root3.search(element, 0)
    print(f"C 트리 : {target.word} {target.meaning} (레벨 {level})")

for element in wordList:
    target, level = searchNode(root4, element, 0)
    print(f"D 트리 : {target.word} {target.meaning} (레벨 {level})")

