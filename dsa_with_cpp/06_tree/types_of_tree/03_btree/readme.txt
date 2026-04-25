1. Each node contains multiple sorted keys
2. A node with k keys has k + 1 children
3. All leaves are at the same level (perfectly balanced)
4. Max keys in a node = 2t − 1, Min keys (except root) = t − 1
5. Root has at least 1 key (can have fewer than others)
6. Subtree ordering rule: left < key < right (range must be maintained)
7. Insertion: always in leaf, split if node is full (middle key goes up)
8. Deletion: maintain minimum keys using borrow or merge