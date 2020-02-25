#include <iostream>
#include <cctype>
#include <cstring>
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
	node *next;
};


class table{

	public:
		table(int size = 5);
		~table();
		int hash(char *key) const;
		int insert(char *mealName,char *venueName,int price, int rating, char *review, char *venueType);
		int display(char *key);
		int removeByMeal(char *mealName);
		int removeByVenue(char *venueName);
		bool retrieve(char *toFind, char mealName[],char venueName[], int price, int rating, char review[], char venueType[]);


	private:
		node ** hashTable;
		int hashTableSize;




};
