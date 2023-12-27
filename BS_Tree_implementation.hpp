//default constructor
template <typename T>
BS_Tree<T>::BS_Tree()
{
		root = nullptr;
}

//destructor
template <typename T>
BS_Tree<T>::~BS_Tree()
{
		clear();
		root = nullptr;
}

//function to insert a new leaf to a tree
template <typename T>
void BS_Tree<T>::insert(const T& nval)
{
		root =  own_insert(root, nval);
}

//helper function to a insert()
template <typename T>
typename BS_Tree<T>::Node* BS_Tree<T>::own_insert(Node* root, const T& nval)
{
	if(root == nullptr)											//creating a new node with nval value 
	{
			root = new Node(nval);
			return root;

	} else if (nval < root -> value) {							//we construct the tree the way that it holds smaller value in the left hand of the root

			root -> left = own_insert(root -> left, nval);

	} else if(nval > root -> value){							//if the value is greater than the root's value, we look for the insert position in the right subtree of the root

			root -> right = own_insert(root -> right, nval);
	}
	return  root;

	
}

//function to traverse the tree with left-root-right order
template <typename T>
void BS_Tree<T>::inorder() 
{
		own_inorder(root);
}

//helper function for the inoreder()
template <typename T>
void BS_Tree<T>::own_inorder(Node*  root)
{
		if(root != nullptr)
		{
				own_inorder(root -> left);
				std::cout << root -> value << " ";
				own_inorder(root -> right);
		}
}

//function to traverse the tree with root-left-right order
template <typename T>
void BS_Tree<T>::preorder()
{
		own_preorder(root);
}

//helper function for the preorder()
template <typename T>
void BS_Tree<T>::own_preorder(Node* root) 
{
		if(root != nullptr)
		{
			std::cout << root -> value << " ";
			own_preorder(root -> left);
			own_preorder(root -> right);
				
		}
}

//function to traverse the tree with left-right-root order
template <typename T>
void BS_Tree<T>::postorder()
{
		own_postorder(root);
}

//helper function to the postorder()
template <typename T>
void BS_Tree<T>::own_postorder(Node* root) 
{
	if(root != nullptr) {
		own_postorder(root -> left);
		own_postorder(root -> right);
		std::cout << root -> value << " ";
	}
}

//function to find the minimum value that the tree contains
template <typename T>
T BS_Tree<T>::find_min()
{
	return own_find_min(root) -> value;
}

//helper function for the find_min() function. This returns the node which holds the minimum value in the tree.
template <typename T>
typename BS_Tree<T>::Node* BS_Tree<T>::own_find_min(Node* root)
{
	if(root ->left == nullptr)
	{
			return root;
	}
	return own_find_min(root -> left);				//as smaller value is located in the left side of the tree we look for the smallest value int the left subtree
}

//function to get the maximum value contained in the tree
template <typename T>
T BS_Tree<T>::find_max()
{
		return own_find_max(root) -> value;
		
}

//helper function for the find_max()
template <typename T>
typename BS_Tree<T>::Node* BS_Tree<T>::own_find_max(Node* root)
{
	if(root -> right == nullptr)
	{
			return root;
	}
	return own_find_max(root -> right);
	

}

//function to remove a node from the tree
template <typename T>
void BS_Tree<T>::remove(const T& val)
{
	root = own_remove(root, val);		
}

//helper function for remove()
template <typename T>
typename BS_Tree<T>::Node* BS_Tree<T>::own_remove(Node* root, const T& val)
{
	if (root == nullptr)
	{
			return nullptr;
	}
	if (val < root -> value) {

			root -> left = own_remove(root -> left, val);			//looking for the node with the needed value in the left  subtree

	} else if (val > root -> value) {

			root -> right = own_remove(root -> right, val);			//looking for the node with the neede value in the right subtree

	} else {														//case when the node is found
			
		if(root -> left == nullptr)									//if the node doesn't have a left subtree, then delete the node and return pointer to its right subtree's root to connect this node to the one which pointed to the node we deleted
		{
				Node* tmp = root -> right;							
				delete root;
				return tmp;

		} else if (root -> right == nullptr) {					//if the node doesn't have a right subtree, then delete the node and return a pointer to its left subtree's root to connct this node to the one which pointed to the node we deleted

				Node* tmp = root -> left;
				delete root;
				return tmp;

		}

		Node* tmp = own_find_min(root -> right);				//if node has either left or right subtrees, then find the minumum value for the right subtree of the node which we are to delete and assigh to tmp
		root -> value = tmp -> value;							//assign tmp's value (holds the minimum value for the right subtree of the node we are to delete) to the node 
		root -> right = own_remove(root -> right, tmp -> value);  // call remove function for the root's right subtree, to delete the node  which holds subtree's minimum value
	}
	return root;
		
}

//function to check if the tree contains a node with the given value
template <typename T>
bool BS_Tree<T>::search(const T& val)
{
		Node* node = root;
		node = own_search(root, val);
		if(node) {
				return 1;
		}
		return 0;
}

//helper function for search()
template <typename T>
typename BS_Tree<T>::Node* BS_Tree<T>::own_search(Node* root, const T& val)
{
		if(!root) 
		{
			return nullptr;
		}
		if(root -> value == val)
		{
				return root;

		} else if (val > root -> value) {

			return own_search(root -> right, val);
		}
			return own_search(root -> left, val);
}

//function to clear the tree
template <typename T>
void BS_Tree<T>::clear()
{
    own_clear(root);
}

//helper for the clear()
template <typename T>
void BS_Tree<T>::own_clear(Node*& root)
{
    if(!root)
    {
        return;
    }

    own_clear(root -> left);				 //deletes nodes in  left-right-root order(postorder)
    own_clear(root -> right);
    delete root;
    root = nullptr;
}
/*
//another version of clear with queue
template <typename T>
void BS_Tree<T>::clear()
{
	if(root == nullptr)
	{
		return;
	}

	std::queue<Node*> q;
		
	q.push(root);
		
		while (!q.empty())
		{
				if(q.front() -> left) {
						q.push(q.front() -> left);
				}
				if(q.front() -> right) {
						q.push(q.front() -> right);
				}
				
				delete q.front();
				q.pop();
		}
		root = nullptr;

		
}
*/

//function to return how menay nodes are there in the tree
template <typename T>
size_t BS_Tree<T>::size() const
{
	std::queue<Node*> q;
	size_t tree_size = 0;
	if(root) {						//if tree is not empty

		q.push(root);				//pushing root to the queue so the size is already 1
		++tree_size;				

		while(!q.empty()){				
				
			
			if (q.front() -> left) {		//if the first element of the queue has left subtree then push the node* which points to the left subtree of the node, and add size by 1
							
						q.push(q.front()-> left);
						++tree_size;
	
			}
			if(q.front() -> right) {		//if the first element of the queue has right subtree then push the q.front()'s right  and indrease size by one

						q.push(q.front() -> right);
						++tree_size;

			} 
				q.pop();					//pop the first element of the queue
		}
	}
	return tree_size;						
}

//function to return tree's maximum height
template <typename T>
size_t BS_Tree<T>::height()
{
		return own_height(root);
}

//helper function for height()
template <typename T>
size_t BS_Tree<T>::own_height(Node* root)
{
		if(root == nullptr)
		{
				return 0;

		} else {

			int hleft = own_height(root ->left);
			int hright = own_height(root -> right);
		
			if(hleft > hright) {
				return 	hleft + 1;
			} 
				return hright + 1;
		
		}
}
//function to return given values successor
template <typename T>
T BS_Tree<T>::successor(const T& val) 
{
	if(contains(val)){					//if tree contains the value then findits successor
		Node*  succ = nullptr;
		succ = own_successor(root, succ, val);		
		if(succ == nullptr) {				//if succ is nullptr it means than the value hasn't a successor
				return  -1;
		}
		return succ -> value;				//returns a value of the successor's node
	}															//if the tree doesn't containt the value then show a messege   
	std::cout << "Tree doesn't contain the value you entered: " ;
	return -1;
	
}

//helper function for the successor()
template <typename T>
typename BS_Tree<T>::Node* BS_Tree<T>::own_successor(Node* root, Node*& succ, const T& val)
{
		if(root == nullptr) {
				return  nullptr;
		}
		// If the current node's value is equal to the target value
		if(root -> value == val) {			
			    // We are in the node whose successor we are looking for
				if(root -> right) {				
					//if the node has right subtree then find the node which holds the minimum value in that subtree and assign it to succ

				succ = own_find_min(root -> right);
				
				}
		} else if (root -> value > val) {		
			 // If the root's value is greater than the value whose successor we are looking for,
    // assign root to succ and call the function for the left subtree of the root
				succ =  root;
				return own_successor(root -> left, succ, val);
		} else {
			 // If the target value is greater than the current node's value, search in the right subtree
				return own_successor(root -> right, succ, val);
		}
		return succ;
}

//function to return predecessor of the given value
template <typename T>
T BS_Tree<T>::predecessor(const T& val)
{

    // Check if the tree contains the given value
	if(contains(val))										
	{
		Node* pred = nullptr;
		own_predecessor(root, pred, val);

        // Check if a predecessor is found
		if(pred) {											
            // Return the value of the predecessor
			return pred -> value;							
		} return -1;										//if the predecessor is nullptr (doesn't have a predecessor) then return a -1
	}														//if the tree doesn't contain a given value then show a messege
	std::cout << "Tree doesn't contain the value you entered: " ;
			// Return -1 to indicate that the value was not found in the tree
	return -1;
		
}
//helper function for the predecessor()
template <typename T>
typename BS_Tree<T>::Node* BS_Tree<T>::own_predecessor(Node* root, Node*& pred, const T& val)
{
	    // Base case: If the current node is nullptr, no predecessor is found
		if(root == nullptr)
		{
				return nullptr;
		}
		// If the current node's value is equal to the target value
		if(root -> value == val)					
		{
			        // If the current node has a left subtree, find the maximum value node in that subtree and assign it to a pred
				if (root -> left)				
				{
						pred = own_find_max(root -> left);
				}
		} else if (root -> value < val)
		{
			// If the target value is greater than the current node's value,
			// assign the current node to the predecessor and search in the right subtree
				pred = root;
				return own_predecessor(root -> right, pred, val);

		} else {
				  // If the target value is less than the current node's value,
				  // search in the left subtree
				return own_predecessor(root -> left, pred, val);
		}
		return pred;

}
//function to print a tree with levels
template < typename T>
void BS_Tree<T>::level_order()
{
		int h = height();		//getting the height of the tree

		for(int i = 1; i <= h; ++i)		//traverse each level of the tree
		{
				Current_Level(root, i);		        // Print nodes at the current level by calling Current_level() function
				std::cout << std::endl;
		}
}

template <typename T>
void  BS_Tree<T>::Current_Level(Node* root, const int& level)
{

	if(root == nullptr)					    //base case: If the current node is nullptr, return
	{
		return;
	}
	if (level == 1) {						//if the current level is 1, print the value of the current node
			std::cout << root -> value << " ";
	} 
	// Recursively call for left and right subtrees for the next level(to reach level == 1 case)
	if(level > 1)
	{
		Current_Level(root -> left, level - 1);
		Current_Level(root -> right, level - 1);
	}

}

//another version of level_order with queue
template <typename T>
void BS_Tree<T>::print_tree()
{

		if(!root) {					    //check if the tree is empty
				return;
		}
		std::queue<Node*> q;			//using a queue for level order traversal
		q.push(root);

		while(!q.empty())				//traversing the tree using the queue
		{
			if(q.front() -> left)			//push left and right children if they exist
			{
					q.push(q.front() -> left);						
			}
			if(q.front() -> right)
			{
				q.push(q.front() -> right);
			}									
			std::cout << q.front() -> value << " ";		        //Print the value of the front node and pop it
			q.pop();
					
		}
}
//function to check if the tree holds the given value
template <typename T>
bool BS_Tree<T>::contains(const T& val)
{
		return search(val);
}

//
template <typename T>
void BS_Tree<T>::copy(const BS_Tree<T>& other)
{
		clear();	// Clear the current tree

		if(!(other.root)){		    // Check if the other tree is empty
			
			return;
		}

		std::queue<Node*> q;		    // Use a queue for level order traversal of the other tree
		q.push(other.root);

		while(!q.empty())				// Traverse the other tree and insert nodes into the current tree
		{
				insert(q.front() -> value);					

				if(q.front() -> left)			  //push left and right children if they exist
				{
					q.push(q.front() -> left);
				}
				if(q.front() -> right)
				{
						q.push(q.front() -> right);
				}
				q.pop();
		}
		
}

//function to to print all the values that tree holds in the given range
template <typename T>
void BS_Tree<T>::range_query(const T& val1, const T& val2)
{
		own_range_query(root, val1, val2);
}

//helper funtion for the range_query()
template <typename T>
void BS_Tree<T>::own_range_query(Node*  root, const T& val1, const T& val2)
{
		if(root == nullptr)			 // Base case: If the current node is nullptr, return
		{
				return;
		}
		own_range_query(root -> left, val1, val2);		// Recursively call for left subtree (inorder calls)

		if(root -> value >= val1 && root -> value <= val2)		// If the value of the current node is within the specified range, print it
		{
				std::cout << root-> value  << " ";		
		}
		own_range_query(root -> right, val1, val2);			    // Recursively call for right subtree

}

//function to mae a vector from the values that the tree holds
template <typename T>
std::vector<T> BS_Tree<T>::serializer()
{
		std::vector<T> vec;
		own_serializer(root, vec);
		return vec;

}
//helper function for the serializer()
template <typename T>
void BS_Tree<T>::own_serializer(Node* root, std::vector<T>& vec)
{
	    // Base case: If the current node is nullptr, return
		if(root == nullptr)
		{
			return;
		}
		// Inorder traversal: left subtree, current node, right subtree
		own_serializer(root -> left, vec);
		vec.push_back(root -> value);
		own_serializer (root -> right, vec);
}

//function to check if the tree is valid or not
template <typename T>
bool BS_Tree<T>::is_valid_bst()
{
		return own_is_valid_bst(root);
}

//helper function for the is_valid_bst()
template <typename T>
bool BS_Tree<T>::own_is_valid_bst(Node* root)
{

	if(root == nullptr)					    // Base case: If the current node is nullptr, return true
	{ 
		return true;
	}
	if(root -> left != nullptr && root -> left -> value > root -> value)	// Check the left subtree: If any node in the left subtree has a value greater than the root, return false
	{
			return false;
	} 
	if(root -> right != nullptr && root -> right -> value < root -> value)	 // Check the right subtree: If any node in the right subtree has a value less than the root, return false
	{
			return false;
	}
														// Recursively check left and right subtrees
	bool left = own_is_valid_bst(root -> left);
	bool right = own_is_valid_bst(root -> right);
		
	// If both subtrees are valid, return true
	if(left && right)
	{
			return true;

	}
	return false;
		
}

//funtion to find kth smallest element in the tree
template <typename T>
T BS_Tree<T>::kth_smallest(const int& k) 
{
		if(k <= 0 || k > size()){							// Check if k is within a valid range
				return -1;									//invalid k
		}
		int ind = 0;
		Node* tmp = own_kth_smallest(root, ind, k);
		if(!tmp) {
				return -1;
		} return tmp -> value;

}
//helper function for kth_smallest()
template <typename T>
typename BS_Tree<T>::Node* BS_Tree<T>::own_kth_smallest(Node* root,  int& ind, const int& k)
{
		if( root == nullptr)		    // Base case: If the current node is nullptr, return nullptr
		{
			return nullptr;	
		}

		 Node* leftResult = own_kth_smallest(root->left, ind, k);	 // Recursively traverse the left subtree
		 if (leftResult != nullptr) {								// If kth smallest is found in the left subtree, return it
			
			return leftResult; 
		}		
		ind++;											    // Increment the index

		if(ind == k) {										    // If the current index is equal to k, return the current node
				return root;
		}
				return  own_kth_smallest(root -> right, ind, k);		 // Recursively traverse the right subtree

}			
//function to find kth_largest element of the tree
template <typename T>
T BS_Tree<T>::kth_largest(const int& k)
{
	// Check if k is within a valid range
    if (k <= 0 || k > size()) {
        return -1;															// Invalid k
    }
		int ind = 0;
		int real_k = size() - k + 1;								    // Calculate the real k for kth largest
		Node* tmp = own_kth_smallest(root, ind, real_k);
		if(!tmp) {
				return -1;
		} return tmp -> value;

}

template <typename T>
void BS_Tree<T>::update(const T& val, const T& nval)
{
	if(contains(val)) {					    // If the tree contains the value to be updated, remove it and insert the new value
		remove(val);
		insert(nval);
	}
}

