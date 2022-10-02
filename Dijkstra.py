from heapq import heapify
import random
from queue import PriorityQueue as pq

# ============================== ADJACENCY MATRIX DEFINITIONS=======================================
class Graph(object):
    def __init__(self,size):
        self.adjMatrix = []
        self.size = size
        self.EdgeCount = 0
        self.pi = []
        self.edge = 0
        
        for i in range(size):
            self.adjMatrix.append([0 for i in range(size)])
            
            
    def add_edge(self,v1,v2):
        if v1 == v2:
            return
        
        self.adjMatrix[v1][v2] = 1
        self.adjMatrix[v2][v1] = 1
        self.EdgeCount += 1 
        
    def remove_edge(self,v1,v2):
        if (self.adjMatrix[v1][v2] == 0):
            print(f"no edge between v1 (f{v1}) and v2 (f{v2})")
            return
        self.adjMatrix[v1][v2] = 0
        self.adjMatrix[v2][v1] = 0
        self.EdgeCount -= 1
        
    def edge_count(self):
        return self.edge_count
    
    def print_matrix(self):
        print("[")
        for row in self.adjMatrix:
            for val in row:
                print(f'{val}', end=''),
            print("")
        print("]")
 
    # ==============================DIJKSTRA ALGORITHM DEFINITIONS=======================================
    # WITHIN GRAPH CLASS

    def dijkstra_algo(self,graph,start_node):
        for v in graph:
            d[v] = 1e7
            pi = [False]
        
 
        
# ==============================PRIORITY QUEUE DEFINITIONS=======================================
class PriorityQueue(object):
    def __init__(self):
        self.queue = []
        self.queue_size = 0
        
    
    def find_parent(self,node):
        return node/2
    
    # A recursive method to heapify a subtree with the root at given index
    # This method assumes that the subtrees are already heapified
    def heapify(self,arr,n,i): #initially i is root, and i starts from index 0, n is size ### RECURSIVE HEAPIFY ###
        largest = i
        left = 2*i + 1
        right = 2*i + 2
        
        if(left<n) and (arr[largest] < arr[left]): 
            largest = left
        
        if(right<n) and (arr[largest] < arr[right]):
            largest = right
            
        if (largest != i):
            arr[i], arr[largest] = arr[largest], arr[i]
            heapify(arr,n,largest)
        
    def find_max(self,array):
        if(self.queue_size <= 0):
            return -1
        if(self.queue_size == 1):
            self.queue_size = self.queue_size - 1
            return array[0]
        
        root = array[0]
        array[0] = array[]
        
    def heap_sort(self,array,n):
        for i in range(n,0,-1):
            currentMax = max(array)
            array.remove(currentMax)
            
            array[i] = currentMax
            
        
    def insert(self,array,newNum):
        self.queue_size +=1
        if self.queue_size == 0:
            array.append(newNum)
        else:
            array.append(newNum)
            for i in range((self.queue_size //2)-1,-1,-1):
                heapify(array,self.queue_size,i)
            
    def delete_node(self,array,num):
        if(self.queue_size < 1):
            return
        for i in range(0,self.queue_size):
            if num == array[i]:
                break
        array[i],array[self.queue_size - 1] =  array[self.queue_size - 1],array[i]
        array.remove(self.queue_size - 1)
        
        for i in range((self.queue_size // 2) - 1,-1,-1):
            heapify(array,self.queue_size,i)
    
    def print_pq(self,array):
        for i in range(self.queue_size+1):
            print(array[i])
    

# ============================== GENERATE random integers into adjacency matrix =======================================        
SIZE = random.randint(3,10)
g = Graph(SIZE)
for i in range(SIZE):
    x  = random.randint(0,SIZE-1)
    y  = random.randint(0,SIZE-1)
    print("amogus",x , y)
    
    if (x > y):
        g.add_edge(y,x)
    else:
        g.add_edge(x,y)
    
g.print_matrix()



