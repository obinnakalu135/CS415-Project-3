"""
    Project 3 Main Code for Obinna and Jacob

"""

"""
    Main code taken from GeeksForGeeks
    Was using it as a reference for a BFS algorithm
    Need to modify it so we can take an array of vectors and output it using numpy or scripy 

"""


import numpy
#import scripy
import collections

#Best First Search


#Breath First Search
class Graph:
    def __init___(self):
        
        self.graph=defaultdict(list)

    # Function to add an edge to graph
    def addEdge(self, u, v):
        self.graph[u].append(v)
 
    # Function to print a BFS of graph
    def BFS(self, s):
 
        # Mark all the vertices as not visited
        visited = [False] * (max(self.graph) + 1)
 
        # Create a queue for BFS
        queue = []
 
        # Mark the source node as
        # visited and enqueue it
        queue.append(s)
        visited[s] = True
 
        while queue:
 
            # Dequeue a vertex from
            # queue and print it
            s = queue.pop(0)
            print(s, end=" ")
 
            # Get all adjacent vertices of the
            # dequeued vertex s.
            # If an adjacent has not been visited,
            # then mark it visited and enqueue it
            for i in self.graph[s]:
                if visited[i] == False:
                    queue.append(i)
                    visited[i] = True

def main():
    #quest = input("Enter the graph you would like to traverse: ")

    #match quest:

  
    
    print("Hello World")



main()