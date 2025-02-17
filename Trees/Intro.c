/*


--------------------------------------Tree--------------------------------

->Tree is a non-linear data structure which stores the data elements in a hierarchical manner. 
    Each node of the tree stores a data value, and is linked to other nodes in a hierarchical fashion. 
->A tree is defined as a finite set of elements or nodes, such that 
    1. One of the nodes present at the top of the tree is marked as root node. 
    2. The remaining elements are partitioned across multiple subtrees present below the root node.



--------------------------------------Tree Terminologies--------------------------------
Node: It is the data element of a tree. Apart from storing a value, it also specifies links to the other nodes.

Root Node: The topmost node of a tree or the node which does not have any parent node is called the root node. 

Parent Node: A node that has one or more child nodes present below it is referred as parent node.
            The node which is an immediate predecessor of a node is called the parent node of that node.

Child Node:  The node which is the immediate successor of a node is called the child node of that node.    

Leaf Node : It is the terminal node that does not have any child nodes. 


Internal Node: All nodes except root and leaf nodes are referred as internal nodes.
Sibling: All the child nodes of a parent node are referred as siblings.
        Children of the same parent node are called siblings.

Level of a node: The count of edges on the path from the root node to that node. The root node has level 0.

Path: It is the sequence of nodes from source node till destination node.

Degree:     The degree of a node is the number of subtrees coming out of the node.

Height of a node: The height of a node can be defined as the length of the  path from the node to a leaf node of the tree.

Depth of a Node: The depth of a node is defined as the length of the  path from the root to that node.

Height of the Tree: The height of a tree is the length of the longest path from the root of the tree to a leaf node of the tree.

Depth of the Tree: The depth of a tree is the length of the longest path from a leaf node to the root node of the tree.
    "Height of the tree = Depth of the tree and It is the maximum level of a node in the tree."



----------------------------------Binary Tree--------------------------------
Strictly binary tree: A binary tree is called strictly binary if all its nodes barring the leaf nodes contain two child nodes. 
Perfect binary tree: A binary tree is called perfect binary tree if all its leaf nodes are at the lowest level and all the non-leaf nodes contain two child nodes. 
*/