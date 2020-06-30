//Sourabh Jamalapuram
//activity.h, contains the class and function prototypes for activity and its derived classes such as zoom, travel, and restaurant
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include "string.h"
using namespace std;
#pragma once

class activity{


	public:
		activity();
		activity(String title, String subject, int priority);
		virtual void display() = 0;
		virtual ~activity();

		activity& operator =(const activity &a1);

		friend bool operator < (const activity &, const activity *);
		friend bool operator < (const String  , const activity *);
		friend bool operator < (const activity *, const String );
	
		friend bool operator <= (const activity &,const activity *);
		friend bool operator <= (const String  , const activity *); 
                friend bool operator <= (const activity *, const String );

		friend bool operator > (const activity &, const activity *);
		friend bool operator > (const String  , const activity *); 
                friend bool operator > (const activity *, const String );

		friend bool operator >= (const activity &,const activity *);
		friend bool operator >= (const String  , const activity *); 
                friend bool operator >= (const activity *, const String );

		friend bool operator == (const activity &a1, char *a2);
                friend bool operator == (char *a1, const activity &a2);
                friend bool operator ==(const activity &a1, const activity &a2);

                friend bool operator != (const activity &a1, char *a2);
                friend bool operator != (char *a1, const activity &a2);
                friend bool operator !=(const activity &a1, const activity &a2);

		friend ofstream& operator <<(ofstream&, const activity &);
	
		friend ifstream& operator >>(ifstream&, const activity &);
	

		


		
	protected:
		String title;
		String subject;
		int priority;

		virtual void writeOut(ofstream &out) const = 0;
		virtual void readIn(ifstream &infile) const = 0;

};

class zoom:public activity{

        public: 
		zoom();
		~zoom();
                zoom(String title,String subject,int priority,int ID);
                void display();



        protected:
                int ID;

		void writeOut(ofstream& out) const;
		void readIn(ifstream& infile) const;
};


class travel:public activity{

        public: 
		travel();
                travel(String title,String subject, int priority, String startLocation, String destination);
		~travel();
                void display(); 

        protected:
                String startLocation;
		String destination;

		void writeOut(ofstream& out) const;
		void readIn(ifstream &infile) const;

};

class restaurant:public activity{

        public: 
		restaurant();
                restaurant(String title,String subject, int priority, String method);
		~restaurant();
                void display();

        protected:
                String method;

		void writeOut(ofstream& out) const;
		void readIn(ifstream& infile) const;

};


