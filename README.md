# An ant's life / Une vie de fourmi

## 1. The Problem

The subterranean ant hill is modeled as a graph where:
* **Rooms** are nodes with a specific capacity (usually 1 ant at a time).
* **Tunnels** are edges that ants traverse instantaneously.

The constraint is to avoid bottlenecks: two ants cannot occupy the same intermediate room during the same step. We need to find the best paths and coordinate the movements step-by-step so that the entire colony reaches the dormitory as fast as possible.

## 2. Our Solution: DFS Pathfinding

To solve this problem efficiently, we implemented an object-oriented approach in C++ using a **Depth-First Search (DFS)** algorithm with a virtual tracking system to simulate and predict ant placement.

### Algorithmic Strategy & DFS Routing

The core of the routing relies on the `Room::DFSPath` function:
1. **Path Discovery:** The algorithm explores the graph using DFS starting from the Vestibule to find a clear path to the Dormitory destination.
2. **Virtual Occupancy Tracking (`virtualAntCount`):** To prevent multiple ants from scheduling a move to the same room during the same step, we use an `unordered_map` tracking virtual ant counts. The DFS checks this map before considering a room "free".
3. **Simulation Loop:** The `Anthill::run()` orchestration loop advances the simulation step by step, extracting ants from their current rooms, moving them to their next destination along the discovered paths, and printing the synchronized movements.

### Code Architecture

The implementation is mapped across three explicit classes:

* **`Ant`**: Represents an individual ant. It contains a static counter to automatically assign a unique `antId` to each unit upon instantiation.
* **`Room`**: Represents a node in the anthill. It manages its capacity (`size`), its `name`, pointers to neighboring rooms (`adjacencies`), and the ants currently inside it (`ants`). It contains the recursive `DFSPath` function.
* **`Anthill`**: The main manager class. It handles the parsing data structures (`roomLinking`, `roomSizes`), manages all dynamically allocated rooms, tracks the `stepCounter`, and runs the global simulation via `run()`.


## 3. Conclusion

This project demonstrates how a classic graph traversal algorithm like DFS can be successfully adapted to solve complex scheduling and capacity-restricted flow problems. 

By leveraging object-oriented design in C++ and a virtual tracking system, the engine ensures optimal ant distribution without structural collisions, keeping the simulation loop clean and decoupled from the parsing logic.

<small>This project has been realised by [Nicolas](https://github.com/nicolas-riera/), [Arthur](https://github.com/arthur-georget) and [Hugo](https://github.com/hugo-belaloui).</small>