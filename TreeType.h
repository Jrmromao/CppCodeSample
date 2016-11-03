/////////////////////////////////////////
//	Author: Joao Filipe Romao	//
//	K00201566			//
//////////////////////////////////////////
template<class ItemType>
struct TreeNode
{
	PDetails info;
	TreeNode<ItemType>* left;
	TreeNode<ItemType>* right;
};

template<class ItemType>
class TreeType
{
public:
	TreeType(); 	// constructor
	~TreeType(); 	// destructor
	bool IsEmpty();
	void InsertItem(ItemType item);
	void DeleteItem(PDetails item);
	void ResetTree();
	void PrintTree();
	void Destroy(TreeNode<ItemType>*& tree);
	void RetrieveItem(string item, bool& found);
	void RetrieveItemByFullS(string item, bool & found);
private:
	TreeNode<ItemType> * root;
	void Insert(TreeNode<ItemType>*& tree, ItemType item);
	void Print(TreeNode<ItemType>* tree);
	void Retrieve(TreeNode<ItemType>* tree, string& item, bool& found);
	void RetrieveByFullS(TreeNode<ItemType>* tree, string item, bool& found);
	void Delete(TreeNode<ItemType>*& tree, PDetails item);
	void GetPredecessor(TreeNode<ItemType>* tree, PDetails& data);
	void DeleteNode(TreeNode<ItemType>*& tree);
};
//class implementation


template<class ItemType>
TreeType<ItemType>::TreeType()
{
	root = NULL;
}
template<class ItemType>
TreeType<ItemType>::~TreeType()
// Calls recursive function Destroy to destroy the tree.
{
	Destroy(root);
}


template<class ItemType>
void TreeType<ItemType>::Retrieve(TreeNode<ItemType>* tree, string& item, bool& found)
{

		if (tree != NULL)
		{
			if (item== tree->info.LastNam.substr(0,1))
			{
				found = true;
				tree->info.print();
				Retrieve(tree->left, item, found);
				Retrieve(tree->right, item, found);
			}
			else
			{
				Retrieve(tree->left, item, found);
				Retrieve(tree->right, item, found);
			}
		}
		
}
template<class ItemType>
void TreeType<ItemType>::RetrieveItem(string item, bool& found)

{
	Retrieve(root, item, found);
}

template<class ItemType>
void TreeType<ItemType>::RetrieveByFullS(TreeNode<ItemType>* tree, string item, bool& found)

{

	if (tree == NULL)
		found = false;
	// item is not found.
								
	else if (tree->info > item){// Search left subtree.
		RetrieveByFullS(tree->left, item, found);
		RetrieveByFullS(tree->right, item, found);
	}
								
	else if (tree->info < item){// Search right subtree.
		RetrieveByFullS(tree->right, item, found);
		RetrieveByFullS(tree->left, item, found);
	}
		
	else{
		// item is found.
		tree->info.print();
		found = true;
	}

}

template<class ItemType>
void TreeType<ItemType>::RetrieveItemByFullS(string item, bool & found)
{
	RetrieveByFullS(root, item, found);
}



template<class ItemType>
void TreeType<ItemType>::Insert(TreeNode<ItemType>*& tree, ItemType item)
// Inserts item into tree.
// Post:  item is in tree; search property is
// maintained.
{
	if (tree == NULL)
	{
		// Insertion place found.
		tree = new TreeNode<ItemType>;
		tree->right = NULL;
		tree->left = NULL;
		tree->info = item;
	}
	else if (item < tree->info)
	Insert(tree->left, item);   // Insert in left subtree.
	else
		Insert(tree->right, item);  // Insert in right subtree.
}



template<class ItemType>
void TreeType<ItemType>::InsertItem(ItemType item)
// Calls recursive function Insert to insert item into tree.
{
	Insert(root, item);
}

template<class ItemType>
void TreeType<ItemType>::PrintTree()
// Calls recursive function Print to print items in the tree.
{
	Print(root);
}


template<class ItemType>
void TreeType<ItemType>::Print(TreeNode<ItemType>* tree)
// Prints info member of items in tree in sorted 
// order on outFile.
{
	if (tree != NULL)
	{
		Print(tree->left);	    // Print left subtree.
		tree->info.print();
		Print(tree->right);	// Print right subtree.
	}
}

template<class ItemType>
void TreeType<ItemType>::Destroy(TreeNode<ItemType>*& tree)
// Post: tree is empty; nodes have been deallocated.
{
	if (tree != NULL)
	{
		Destroy(tree->left);
		Destroy(tree->right);
		delete tree;
	}
}

template<class ItemType>
void TreeType<ItemType>::ResetTree(){

	Destroy(root);
	root = NULL;
}



template<class ItemType>
void TreeType<ItemType>::Delete(TreeNode<ItemType>*& tree, PDetails item)
// Deletes item from tree.
// Post:  item is not in tree.
{
	if (item < tree->info.LastNam) Delete(tree->left, item);  // Look in left subtree.

	else if (item > tree->info.LastNam) Delete(tree->right, item); // Look in right subtree.


	else DeleteNode(tree); // Node found; call DeleteNode.
	
	
}

template<class ItemType>
void TreeType<ItemType>::DeleteItem(PDetails item)
// Calls recursive function Delete to delete item 
// from tree.
{
	Delete(root, item);
}


template<class ItemType>
void TreeType<ItemType>::DeleteNode(TreeNode<ItemType>*& tree)

{
	PDetails data;
	TreeNode<ItemType>* tempPtr;
	tempPtr = tree;
	if (tree->left == NULL)
	{
		tree = tree->right;
		delete tempPtr;
	}
	else if (tree->right == NULL)
	{
		tree = tree->left;
		delete tempPtr;
	}
	else
	{
		GetPredecessor(tree->left, data);
		tree->info = data;
		Delete(tree->left, data);	// Delete predecessor node.
	}
}



template<class ItemType>
void TreeType<ItemType>::GetPredecessor(TreeNode<ItemType>* tree, PDetails& data)
// Sets data to the info member of the right-most
// node in tree.
{
	while (tree->right != NULL)
		tree = tree->right;
	data = tree->info;
}



template<class ItemType>
bool TreeType<ItemType>::IsEmpty()
// Returns true if the tree is empty; 
// false otherwise.
{
	return root == NULL;
}


