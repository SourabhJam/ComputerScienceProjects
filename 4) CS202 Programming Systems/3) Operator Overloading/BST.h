//Sourabh Jamalapuram
//BST.h contains the node class and BST class and the function prototypes and data members for each class
#include "activity.h"
#pragma once

class node{


	public:
		node();
		node(activity *data);
		node(const node &toCopy);
		~node();

		int insert(activity &toAdd);
		node* remove(String title, node *parent, node *&root,int direction);
		node * findIOS(node *& current, node *& parent);
		int display();
		bool retrieval(String title, activity **a);
		int removeAll();
		int updateFile(ofstream &out);

		node& operator =(const node &n1);




	private:
		activity *data;
		node *left;
		node *right;

};



class BST{


	public:
		BST();
		BST(const BST &toCopy);
		~BST();

		int insert(activity *toAdd);
		int remove(String title);
		bool retrieval(String title, activity **a);
		int removeAll();
		int display();
	
		int updateFile();
		int loadData();

		BST& operator =(const BST &b1);

	private:
		node *root;

};
