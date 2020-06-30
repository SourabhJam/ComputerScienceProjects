#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;


struct mealInfo{
	char *mealName;
	char *venueName;
	int price;
	int rating;
	char *review;
	char *venueType;
};

struct node{
	struct mealInfo info;
	node *right;
	node *left;
};




class table{


	public:
		table();
		~table();
		int addNewMeal(char *mealName,char *venueName,int price, int rating, char *review, char *venueType); 
		int displayAll(); 
		int searchMeal(char *key, mealInfo matches[]);
		int removeMeal(char *mealName, char *venueName);
		int displayMatches(char *key); 
		int height();
		bool isEfficient();



	private:
		node *root;

		node * addNewMeal(node * root, char *mealName,char *venueName,int price, int rating, char *review, char *venueType);
		int displayAll(node *root,int level);
		int searchMeal(node *root,char *key, mealInfo matches[], int currentMatchIndex);
		node * removeMeal(node *root, char *mealName, char *venueName);
		node * getIOS(node* root);
		int displayMatches(node *root,char *key);
		int height (node * root);
		int deallocate(node * root);
		int isEfficient(node *root);



};
