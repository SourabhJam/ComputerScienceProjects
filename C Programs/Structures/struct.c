#include <stdio.h>
#include <string.h>
 
struct Students {
   char  name[50];
   char  address[50];
   char  teacher[100];
   int  student_id;
};


void printStudent( struct Students student );

void main( ) {

   struct Students student1;       
   struct Students student2;        
   Students *pStudent;

   pStudent = &student1;
 
   
   strcpy( student1.name, "Sourabh Jamalapuram");
   strcpy( student1.address, "17003 NW Tucson Street"); 
   strcpy( student1.teacher, "Mr.Guthrie");
   student1.student_id = 327002;

 
   printStudent( student1 );



}

void printStudent( struct Students student ) {

   printf( "Student name : %s\n", student.name);
   printf( "Student address : %s\n", student.address);
   printf( "Student teacher : %s\n", student.teacher);
   printf( "Student ID : %d\n", student.student_id);
}