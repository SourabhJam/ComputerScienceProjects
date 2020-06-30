//Sourabh Jamalapuram
//activity.h, contains the class and function prototypes for activity and its derived classes such as hike class, movie class, and eat class
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
using namespace std;
#pragma once

class activity{


	public:
		activity();
		activity(char *title,int priority,int length,bool group);
		activity(const activity &toCopy);
		virtual ~activity();
		
		virtual void display() = 0;
		int isMatch(char *title);
		bool isGreater(activity *a);
		int getPriority();
	
	protected:
		char *title;
		int priority;
		int length;
		bool group;
	

};

class movie:public activity{

        public: 
		movie();
                movie(char *title,int priority,int length,bool group, char *rating);
		movie(const movie &toCopy);
                ~movie();
                
		void display();

		int isRatingMatch(char *rating);
		void displayByRating();

        protected:
		char *rating;
                
};


class hike:public activity{

        public: 
		hike();
                hike(char *title,int priority,int length,bool group, int elevation);
		hike(const hike &toCopy);
		~hike();
                
		void display(); 

        protected:
		int elevation;
		
                

};

class eat:public activity{

        public: 
		eat();
                eat(char *title,int priority,int length,bool group, char *cuisine);
		eat(const eat &toCopy);
		~eat();
                
		void display();

        protected:
		char *cuisine;
                

};


