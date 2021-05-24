import random
from typing import overload

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


#TODO 파일읽기
dictionaryFile = open("/Users/abc/Desktop/C/자료구조 수업/Tree_python/randdict_utf8.TXT", "r")
root = BinaryTree()
root2 = AVLTree()
lines = dictionaryFile.readlines()
print('사전을 모두 읽었습니다. ' + str(len(lines)) + '개의 단어가 있습니다')

for line in lines:
    word, meaning = line.split(" : ")
    node = Node(word, meaning)
    root.insert(node)
    root2.insert(node)
    
wordList = [lines[random.randint(0, len(lines)-1)].split(" : ")[0] for index in range(0, 10)]
treeHeight1 = root.getHeight(root.head)
treeHeight2 = root2.getHeight(root2.head)

print(f'A 트리의 전체 높이는 {treeHeight1} 입니다.')
print(f'B 트리의 전체 높이는 {treeHeight2} 입니다.')
print(f'랜덤하게 선택된 단어 10개: {wordList}')


for element in wordList:
    target, level = root.search(element, 0)
    print(f"A 트리 : {target.word} {target.meaning} (레벨 {level})")


for element in wordList:
    target, level = root2.search(element, 0)
    print(f"B 트리 : {target.word} {target.meaning} (레벨 {level})")

