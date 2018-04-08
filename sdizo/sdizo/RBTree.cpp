#include "RBTree.h"



RBTree::RBTree()
{
	hOut = GetStdHandle(STD_OUTPUT_HANDLE); //Handle is our console now
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
	// Guard is initialized
	guard.color = black; //always black         
	guard.parent = &guard; //all guards pointers points himself
	guard.left = &guard;
	guard.right = &guard;
	root = &guard;           // When there is no nodes. Root will point guard

}


RBTree::~RBTree()
{
}

void RBTree::print(std::string sp, std::string sn, Node * pointer)
{
		std::string t;

		if (pointer != &guard)
		{
			t = sp;
			if (sn == cr) t[t.length() - 2] = ' ';
			print(t + cp, cr, pointer->right);

			t = t.substr(0, sp.length() - 2);
			std::cout << t << sn << ":";
			if (pointer->color == red)SetConsoleTextAttribute(hOut, FOREGROUND_RED);
			else  SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			std::cout <<pointer->value << std::endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			t = sp;
			if (sn == cl) t[t.length() - 2] = ' ';
			print(t + cp, cl, pointer->left);
		}
}

void RBTree::rotateRight(Node * node)
{
	Node *brother, *parent;

	brother = node->left;
	if (brother != &guard)
	{
		parent = node->parent;
		node->left = brother->right;
		if (node->left != &guard)
			node->left->parent = node;

		brother->right= node;
		brother->parent = parent;
		node->parent = brother;
		if (parent != &guard)
		{
			if (parent->left == node)
				parent->left = brother;
			else
				parent->right = brother;
		}
		else root = brother;

	}

}

void RBTree::rotateLeft(Node * node)
{
	Node *brother, *parent;

	brother = node->right;
	if (brother != &guard)
	{
		parent = node->parent;
		node->right = brother->left;
		if (node->right != &guard)
			node->right->parent = node;

		brother->left = node;
		brother->parent = parent;
		node->parent = brother;
		if (parent != &guard)
		{
			if (parent->left == node)
				parent->left = brother;
			else
				parent->right = brother;
		}
		else root = brother;

	}
}

void RBTree::addElement(int x)
{
	Node * newNode, *uncle;
	newNode = new Node();
	newNode->left = &guard;//new nodes childer should be guard
	newNode->right = &guard;
	newNode->parent = root;
	newNode->value = x;
	if (newNode->parent == &guard) root = newNode; //If there is no other node. New node is root
	else
		while (true)
		{
			if (newNode->value < newNode->parent->value)
			{
				if (newNode->parent->left == &guard)
				{
					newNode->parent->left = newNode;
					break;
				}
				newNode->parent = newNode->parent->left;
			}
			else
			{
				if (newNode->parent->right == &guard)
				{
					newNode->parent->right = newNode;
					break;
				}
				newNode->parent = newNode->parent->right;
			}

		}
	newNode->color = red; // newNodes are always red. Later they can be recolored
	while ((newNode != root) && (newNode->parent->color == red))
	{
		if (newNode->parent == newNode->parent->parent->left)
		{
			uncle = newNode->parent->parent->right;

			if (uncle->color == red) //first situation
			{
				newNode->parent->color = black;
				uncle->color = black;
				newNode->parent->parent->color = red;
				newNode = newNode->parent->parent;
				continue;
			}
			if (newNode == newNode->parent->right) //2nd sitaution
			{
				newNode = newNode->parent;
				rotateLeft(newNode);
			}
			newNode->parent->color = black;
			newNode->parent->parent->color = red;
			rotateRight(newNode->parent->parent);
			break;
		}
		else
		{
			uncle = newNode->parent->parent->left; // mirror uncle
			if (uncle->color == red)
			{
				newNode->parent->color = black;
				uncle->color = black;
				newNode->parent->parent->color = red;
				newNode = newNode->parent->parent;
				continue;
			}
			if (newNode == newNode->parent->left)
			{
				newNode = newNode->parent;
				rotateRight(newNode);
			}
			newNode->parent->color = black;
			newNode->parent->parent->color = red;
			rotateLeft(newNode->parent->parent);
			break;
		}
	}
	root->color = black; // root always black;
}

void RBTree::addElementOnIndex(int x, int index)
{
}

void RBTree::addElementOnBeginning(int x)
{
}

void RBTree::deleteLastElement()
{
}

void RBTree::deleteIndex(int index)
{
}

void RBTree::deleteFirst()
{
}

void RBTree::printAll()
{
	print("", "", root);
}

int RBTree::getVaule(int index)
{
	return 0;
}

void RBTree::clearAll()
{

}

bool RBTree::contains(int x)
{
	return false;
}
