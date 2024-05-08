/// \file CIsosceles.cpp
///	\brief class Isosceles: implementation of the functions
///
///	Details.
///

#include <iostream>
#include "CIsosceles.h"
#include <math.h>

/// @brief default constructor 
Isosceles::Isosceles() {

	cout << "Isosceles - constructor - default" << endl;

	Init();

}

/// @brief constructor 
/// @param b base of the isosceles
/// @param h height of the isosceles
Isosceles::Isosceles(float b, float h) {
	Init();

	cout << "Isosceles - constructor" << endl;

	if (b <= 0. || h <= 0.) {
		WarningMessage("constructor: width and height should be > 0"); 
		SetDim(0,0);
	}
	else
		SetDim(b,h);
}

/// @brief destructor 
Isosceles::~Isosceles() {
	cout << "Isosceles - destructor" << endl;
	Reset();
}

/// @brief copy constructor 
/// @param o reference to the object that should be copied 
Isosceles::Isosceles(const Isosceles &r) { 
	cout << "Isosceles - copy constructor" << endl;

	Init(r);
}

/// @brief overload of operator = 
/// @param o reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
Isosceles& Isosceles::operator=(const Isosceles &r) { 
	cout << "Isosceles - operator =" << endl;

	Init(r);
	
	return *this;
}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two objects have the same width and the same length  
bool Isosceles::operator==(const Isosceles &r) { 
	if (r.base == base && r.height == height)
		return true;
		
	return false;
}

/// @brief default initialization of the object
void Isosceles::Init() {
	SetDim(0,0);
}

/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void Isosceles::Init(const Isosceles &r) {
	Init();
	SetDim(r.base,r.height);
}

/// @brief total reset of the object  
void Isosceles::Reset() {
	SetDim(0,0);
}


/// @brief set base of the object
/// @param b base 
void Isosceles::SetBase(float b) {

	if (b < 0.) {
		WarningMessage("SetBase: width should be > 0");
		return;
	}

	SetDim(b,height);
}

/// @brief set height of the object
/// @param h height 
void Isosceles::SetHeight(float h) {

	if (h < 0.) {
		WarningMessage("SetHeight: height should be > 0");
		return;
	}

	SetDim(base,h);
}

/// @brief get base of the object
/// @return base 
float Isosceles::GetBase() {
	return sides[0];
}

/// @brief get length of the object
/// @return height
float Isosceles::GetHeight() {

	return height;
}

/// @brief set base and height of the object
/// @param b base 
/// @param h height
void Isosceles::SetDim(float b, float h) {

	height = h;  
	float l = (float)sqrt(pow(b/2, 2) + pow(h, 2));
	Scalene::SetSides(b, l, l);
	
	return;
}

/// @brief get base and height of the object
/// @param b base 
/// @param h height
void Isosceles::GetDim(float &b, float &h) {

	b = base;
	h = height; 
	
	return;
}

/// @brief write an error message 
/// @param string message to be printed
void Isosceles::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- Isosceles --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void Isosceles::WarningMessage(const char *string) {
	
	cout << endl << "WARNING -- Isosceles --";
	cout << string << endl;
}

/// @brief get the area of the object
double Isosceles::GetArea() {
	return (base*height)/2;
}


/// @brief for debugging: all about the object
void Isosceles::Dump() {
	cout << endl;
	cout << "---Isosceles---" << endl; 
	cout << endl;
	
	cout << "Width = " << sides[0] << endl;
	cout << "Heigth = " << height << endl;
	
	Scalene::Dump();
	
	cout << endl;
}






