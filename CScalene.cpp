/// \file CScalene.cpp
///	\brief class Scalene: implementation of the functions
///
///	Details.
///

#include "CScalene.h"
#include <math.h>
#include <iostream>

/// @brief default constructor 
Scalene::Scalene() {

	cout << "Scalene - constructor - default" << endl;

	Reset();
} 

/// @brief copy constructor 
/// @param o reference to the object that should be copied 
Scalene::Scalene(const Scalene &o) {
	
	cout << "Scalene - copy constructor" << endl;

	Init(o);
}

/// @brief destructor
Scalene::~Scalene() {

	cout << "Scalene - destructor" << endl;

	Reset();
}  


/// @brief sets the value of the three sides 
/// @param s1 side 1 
/// @param s2 side 2 
/// @param s3 side 3
void Scalene::SetSides(float s1, float s2, float s3) {
	
	if (s1 >= s2+s3 || s2 >= s1+s3 || s3 >= s1+s2) {
		printf ("Scalene -- SetSides ERROR -- Scalene is not possible to create");
		Reset();
		return;
	}

	sides[0] = s1;
	sides[1] = s2;
	sides[2] = s3;
	
	return;
} 

/// @brief overload of operator = 
/// @param o reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
Scalene& Scalene::operator=(const Scalene &o) { 
	return *this;
}

/// @brief overload of operator == 
/// @param o reference to the object on the right side of the operator 
/// @return true if sides are all equal 
bool Scalene::operator==(const Scalene &o) {
	if(sides[0] == o.sides[0] && sides[1] == o.sides[1] && sides[2] == o.sides[2])
		return true;
	if(sides[0] == o.sides[0] && sides[1] == o.sides[2] && sides[2] == o.sides[1])
		return true;
	if(sides[0] == o.sides[1] && sides[1] == o.sides[0] && sides[2] == o.sides[2])
		return true;
	if(sides[0] == o.sides[1] && sides[1] == o.sides[2] && sides[2] == o.sides[0])
		return true;
	if(sides[0] == o.sides[2] && sides[1] == o.sides[0] && sides[2] == o.sides[1])
		return true;
	if(sides[0] == o.sides[2] && sides[1] == o.sides[1] && sides[2] == o.sides[0])
		return true;
	return false;
}


/// @brief default initialization of the object
void Scalene::Init() {
	sides[0] = sides[1] = sides[2] = 0.;
}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void Scalene::Init(const Scalene &o) {
	Init();
	sides[0] = o.sides[0]; 
	sides[1] = o.sides[1]; 
	sides[2] = o.sides[2]; 
}

/// @brief total reset of the object  
void Scalene::Reset() {
	sides[0] = sides[1] = sides[2] = 0.;
}


/// @brief get the perimeter of the object
/// @return perimeter 
double Scalene::GetPerimeter() {
	return (sides[0]+sides[1]+sides[2]);
} 

/// @brief get the area of the object
/// @return area
double Scalene::GetArea() {
	double p = (Scalene::GetPerimeter())/2.0;
	return (sqrt(p*(p-sides[0])*(p-sides[1])*(p-sides[2])));
}

/// @brief get the sides of the object 
/// @param s0 side 0 
/// @param s1 side 1
/// @param s2 side 2
void Scalene::GetSides(float &s0, float &s1, float &s2) {
	s0 = sides[0]; 
	s1 = sides[1];
	s2 = sides[2];
}

/// @brief write an error message 
/// @param string message to be printed
void Scalene::ErrorMessage(const char *string) {	
	cout << endl << "ERROR -- Scalene --";
	cout << string << endl;
}

/// @brief write a warning message 
/// @param string message to be printed
void Scalene::WarningMessage(const char *string) {	
	cout << endl << "WARNING -- Scalene --";
	cout << string << endl;
}


/// @brief for debugging: all about the object
void Scalene::Dump() {
	cout << endl;
	cout << "Sides = " << sides[0] << "; " << sides[1] << "; " << sides[2] << "; " << endl;
	cout << "Perimeter = " << GetPerimeter() << endl;
	cout << "Area = " << GetArea() << endl;
	cout << endl;
}

