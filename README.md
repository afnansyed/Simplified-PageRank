# Simplified-PageRank
Graph implemented using map data stucture for COP3530 course


The key is a string and the value is a vector pair. The key is used to store the “to page” and the vector pair is used to store the “from page” as a string and 1/dj is stored as a double, if there is an edge (dj is the outdegree of node j). This is used because by using a map, there will be no empty index spaces and also, stores the 1/dj (where d is the outdegree of node j) with its corresponding page value. Two other maps with a string were used as the key and the value is a double. These were used to store the ranks of every web page. Two were used so that when doing the multiplication to find the page ranks, the same map is not updated to avoid geeting different values.


- computational complexity of each method:

  - insertEdge(string to, string from)
  
      (inserting into the graph)

      Best:O(1) when the first element is inserted

      Worst: O(log(n)) where n is the number of elements in the map.

      Average: O(log(n)) where n is the number of elements in the map.
    
  - ranks()
  
      (assigning initial page rank values (when power_iteration = 0))

      Best:O(1) when there is only one element in both the adjacency list and the page ranks map
      
      Worst: O(nlog(m)) where n is the number of elements in the map (adjacency list).
      
      And m is the number of elements in the map (page ranks)
      
      Average: O(nlog(m)) where n is the number of elements in the map (adjacency list). And m is the number of elements in the map (page ranks)
      
  - PageRank(int n)
  
      Best:O(1), when there is only one element in the map.
      
      Worst: O(n) where n is the number of elements in the map.
      
      Average: O(n) where n is the number of elements in the map.
      
  - countEachVal()
  
      (assigning the 1/dj in the vector pair value of a map, if there is an edge (dj is the outdegree of node j) )
      
      Best:O(1), when there is only one element in the map and the size of the vector is 1
      
      Worst: O(n(nm) where n is the number of elements in the map and m is the size of a vector pair of a value in the map
      
      Average: O(n(nm) where n is the number of elements in the map where n is the number of keys in the map and m is the size of a vector pair of a value in the map
      
  - multiply(int n)
  
      (multiply the 1/dj in the vector pair value of a map with the ranks, if there is an edge (dj is the outdegree of node j) )
      
      Best:O(1), when there is only one element in the map, and the size of the vector is 1
      
      Worst: O(n(n+m)) where n is the number of elements in the map.
      
      Average: O(n(n+m)) where n is the number of elements in the map
      
      
      
- computational complexity of main method:

    Best:O(1), when there is only one element in the graph, and the number of lines is only 1
    
    Worst: O(m(logn)) where n is the number of vertices in the graph and m is the number of lines.
    
    Average: O(m(logn)) where n is the number of vertices in the graph and m is the number of lines.

      
