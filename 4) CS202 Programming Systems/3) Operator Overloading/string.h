//Sourabh Jamalapuram
//string.h string class with function prototypes of operators used to create a string
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
#pragma once

class String{

	public:

		String():str(0),len(0){};
		String(const String &toCopy);
		~String();

		String& operator =(const String &str2);
		String& operator =(const char* str2);

		String& operator += (const String & s2);


		friend ostream& operator <<(ostream&, const String &s);
		friend istream& operator >>(istream&, String &s);
		
		friend bool operator < (const String &, char *);
		friend bool operator < (char *, const String &);
		friend bool operator < (const String &, const String &);

		friend bool operator <= (const String &, char *);
		friend bool operator <= (char *, const String &);
		friend bool operator <= (const String &,const String &);

		friend bool operator > (const String &, char *);
		friend bool operator > (char *, const String &);
		friend bool operator > (const String &, const String &);

		friend bool operator >= (const String &, char *);
		friend bool operator >= (char *, const String &);
		friend bool operator >= (const String &,const String &);

		friend bool operator == (const String &s, char *s2);
		friend bool operator == (char *s1, const String &s2);
		friend bool operator ==(const String &s1, const String &s2);

		friend bool operator != (const String &, char *);
		friend bool operator != (char *, const String &);
		friend bool operator !=(const String &s1, const String &s2);

		bool isEmpty();




	protected:
		char *str;
		int len;


};
