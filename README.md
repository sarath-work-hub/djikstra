# djikstra
# Dijkstra’s Algorithm in C++

## Overview
This project demonstrates an implementation of **Dijkstra’s Algorithm** in C++.  
The program finds the **shortest path** between a given starting node and ending node in a weighted graph.  

The graph is **hardcoded** for simplicity, but the algorithm is generic and can work for any graph with **non-negative edge weights**.  

---

## Features
- Graph represented using an **adjacency list**  
- Efficient **priority queue (min-heap)** for shortest path selection  
- Prompts user for **starting** and **ending** nodes  
- Outputs both the **cost** of the shortest path and the **path itself**  
- Path reconstruction using a parent map  

---

## Example Graph Used
1 --(4)-- 2 --(10)-- 4 --(11)-- 6
| |
(2) (5)
| |
3 --(3)-- 5 --(4)--


---

## Example Run


Enter starting node: 1
Enter ending node: 6

Shortest path cost from 1 to 6: 20
Path: 1 -> 3 -> 5 -> 4 -> 6


---

##  How to Compile and Run

### 1. Clone the repository
```bash
git clone https://github.com/your-username/dijkstra-cpp.git
cd dijkstra-cpp

2. Compile the program
g++ dijkstra.cpp -o dijkstra

3. Run the executable
./dijkstra
