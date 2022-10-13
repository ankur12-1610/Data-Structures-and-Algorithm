"""
  Top-View Of a Binary Tree in Python
  Given a Binary tree in preorder traversal, output the top   view of the tree
"""
class Node:
    def __init__(self, info): 
        self.info = info  
        self.left = None  
        self.right = None 
        self.level = None 

    def __str__(self):
        return str(self.info) 

class BinarySearchTree:
    def __init__(self): 
        self.root = None

    def create(self, val):  
        if self.root == None:
            self.root = Node(val)
        else:
            current = self.root
         
            while True:
                if val < current.info:
                    if current.left:
                        current = current.left
                    else:
                        current.left = Node(val)
                        break
                elif val > current.info:
                    if current.right:
                        current = current.right
                    else:
                        current.right = Node(val)
                        break
                else:
                    break

def traverse(root,coord_info_map,x,y):

    if x not in coord_info_map or  y < coord_info_map[x][1]:
        coord_info_map[x] = [root.info,y]
    
    if root.left:
        traverse(root.left,coord_info_map, x - 1, y + 1)
    if root.right:
        traverse(root.right,coord_info_map, x + 1, y + 1)
    
def topView(root):
    x = 0
    y = 0
    coord_info_map = {}
    traverse(root, coord_info_map, x, y)
    for key in sorted(coord_info_map):
        print(coord_info_map[key][0], end=" ")



tree = BinarySearchTree()
print('Input the number of tree nodes :')
t = int(input())
print('Input the tree node values in preorder :')
arr = list(map(int, input().split()))

for i in range(t):
    tree.create(arr[i])

topView(tree.root)

"""This Code is contributed By Shruti Avhad"""
