//Sourabh Jamalapuram
//library.h, contains the classes and class function prototypes for library and node class
#include "activity.h"
#pragma once


class node{
	
	public:
		node();
		node(activity *data);
		node(const node &toCopy);
		~node();
		
		node*  addNode(activity *toAdd, node *prev);
		int displayNodes();
		int addActivity(activity *toAdd, int index);
		int removeActivity(char *title);
		void removeAll(int index);
		bool retrieve(char *title, activity **a, int index);
		void display(int index);
		node* getNext();
		int displayByPriority(int userPriority);
		void displayAll();
		void displayMoviesByRating(char *rating, int index);
		void displayTop(int index);

	protected:
		activity **table;
		int topIndex;
		int priority;
		node *next;
		node *previous;

};

class library{

	public:
		library();
		library(const library &toCopy);	
		~library();

		void addActivity(activity *p);
		void remove(char *title);
		void removeAll();
		bool retrieve(char *title, activity **a);
		void display();

		void displayNodes();

		void displayByPriority(int userPriority);
		void displayTopPriority();

		void displayMoviesByRating(char *rating);
		
	protected:
		node *head;
		

};

