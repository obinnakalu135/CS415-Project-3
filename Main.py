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
"""
def Best_First_Search(I,s,t):
    #Image
    #Verticies s,t
    # s is the start vertex, t is the destination
    # h is a function as described above

    queue = []
    q.insert(s)
    Set visited[v] = false all vertices;
 visited[s] = true;
 set d[s] = h[s] and d[u] = MaxInt for all other u.
 while (Q is not empty and (not visited[t])):
    u = Q.deleteMin()
    for each neighbor v of u:
        if (not visited[v])
            visited[v] = true
            set color of v to Green
            d[v] = d[u] + 1
            prev[v] = u
            Q.insert(v, d[v] + h[v])
        // end-for
    //end-while 

    v = t
    while(v != s):
        #Set s to red 
        v = prev[v]

    #create output image
    #output d[t]
"""

#Breath First Search
def Breath_First_Search(I,s,t):
    #Image
    #Verticies s start,t end
    # s is the start vertex, t is the destination
    Q = []
    Q.insert(s)
    Visited = [False]
    Visited[s] = True
    """
    while (Q is not empty and (not visited[t])):
    u = Q.deleteMin()
    for each neighbor v of u:
        if (not visited[v])
            visited[v] = true
            set color of v to Green
            d[v] = d[u] + 1
            prev[v] = u
            Q.insert(v, d[v] + h[v])
        // end-for
    //end-while 
    """
    v = t
    while(v != s):
        #Set s to red 
        v = prev[v]

    #create output image
    #output d[t]

def main():
    #quest = input("Enter the graph you would like to traverse: ")

    #match quest:

  
    
    print("Hello World")



main()