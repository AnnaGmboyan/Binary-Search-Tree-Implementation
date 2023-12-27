#ifndef BS_TREE_PROTOTYPES_HPP
#define BS_TREE_PROTOTYPES_HPP

#include <queue>
#include <vector>

template <typename T>
class BS_Tree
{
	public:
		BS_Tree();
		BS_Tree(const BS_Tree&);
		BS_Tree(BS_Tree&&);

		~BS_Tree();

	private:
		class Node{

			public:
				Node* right;
				Node* left;
				int  value;

				Node(const T& val): value(val), right(nullptr), left(nullptr) {}
				
		};
		
		Node* root;
		Node* own_insert(Node*, const T&);	
		void own_inorder(Node*);
		void own_preorder(Node*);
		void own_postorder(Node*);
		Node* own_search(Node*, const T&);
		Node* own_find_min(Node*);
		Node* own_find_max(Node*);
		Node* own_remove(Node*, const T&);
		void own_clear(Node*&);
		size_t own_height(Node*);
		Node* own_successor(Node*, Node*&, const T&);
		Node* own_predecessor(Node*, Node*&, const T&);
		void Current_Level(Node*, const int&);
		void own_range_query(Node*, const T&, const T&);
		void own_serializer(Node*, std::vector<T>&);
		Node* own_kth_smallest(Node*, int&, const int&);
		bool own_is_valid_bst(Node* root);
		

	public:
		void insert(const T& val);
		void inorder();
		void preorder();
		void postorder();
		T find_min();
		T find_max();
		bool search(const T& val);
		size_t size() const;
		size_t height();
		void clear();
		void remove(const T&);
		T successor(const T&);
		T predecessor(const T&);
		void level_order();
		void print_tree();	
		bool contains(const T&);
		void copy(const BS_Tree<T>& other);
		void range_query(const T&, const T&);
		std::vector<T> serializer();
		T kth_smallest(const int&);
		T kth_largest(const int&);
		bool is_valid_bst();
		void update(const T&, const T&);
};
	
#include "BS_Tree_implementation.hpp"

#endif // BS_TREE_PROTOTYPES_HPP
