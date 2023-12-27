#include <iostream>
#include "BS_Tree_Prototypes.hpp"

// Assume your BST class definition is already included here

int main() {
    // Create a binary search tree
    BS_Tree<int> myBST;

    // Insert some elements into the BST
    myBST.insert(5);
    myBST.insert(13);
    myBST.insert(7);
    myBST.insert(22);
    myBST.insert(4);
    myBST.insert(6);
    myBST.insert(0);
    myBST.insert(3);
    myBST.insert(15);
    myBST.insert(8);
    myBST.insert(79);
    myBST.insert(20);


    // Perform various operations
    std::cout << "In-order traversal: ";
    myBST.inorder();
    std::cout << std::endl;

    std::cout << "Pre-order traversal: ";
    myBST.preorder();
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    myBST.postorder();
    std::cout << std::endl;

	std::cout << "Minimum element of the tree is: "<< myBST.find_min() << std::endl;
	std::cout << "Maximum element of the tree is: "<< myBST.find_max() << std::endl;
    
	std::cout << "Size of the BST: " << myBST.size() << std::endl;
    std::cout << "Height of the BST: " << myBST.height() << std::endl;

    std::cout << "Does BST ontain 40?. " << (myBST.contains(40) ? "Yes" : "No") << std::endl;

    std::cout << "Successor of 30: " << myBST.successor(30) << std::endl;
    std::cout << "Successor of 3: " << myBST.successor(3) << std::endl;
    std::cout << "Predecessor of 15: " << myBST.predecessor(15) << std::endl;

    std::cout << "Nodes in the range [30, 70]: ";
    myBST.range_query(10, 20);
    std::cout << std::endl;

    std::vector<int> serializedTree = myBST.serializer();
    std::cout << "Serialized BST: ";
	for(int i = 0; i < serializedTree.size(); ++ i)
	{
			std::cout << serializedTree[i] << " ";
	}
	std::cout << std::endl;

    std::cout << "Is valid BST? " << (myBST.is_valid_bst() ? "Yes" : "No") << std::endl;

    int k = 3;
    std::cout << "Kth smallest element (k = " << k << "): " << myBST.kth_smallest(k) << std::endl;

    int kLargest = 2;
    std::cout << "Kth largest element (k = " << kLargest << "): " << myBST.kth_largest(kLargest) << std::endl;

    std::cout << "Updating 4 to 45: ";
    myBST.update(4, 45);
    myBST.inorder();
	std::cout << std::endl << "After removing 7: ";
	myBST.remove(7);
	myBST.inorder();
    std::cout << std::endl;

	BS_Tree<int> tree_copy;
	tree_copy.copy(myBST);
	std::cout << "Tree made by copy: ";
	tree_copy.inorder();
    std::cout << std::endl;
    
	std::cout << "Tree Structure:\n";
    tree_copy.level_order();


    return 0;
}
