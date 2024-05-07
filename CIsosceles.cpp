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
/// @param w width of the isosceles
/// @param h height of the isosceles
Isosceles::Isosceles(float w, float h) {

	Init();

	cout << "Isosceles - constructor" << endl;

	if (w <= 0. || h <= 0.) {
		WarningMessage("constructor: width and height should be > 0"); 
		SetDim(0,0);
	}
	else
		SetDim(w,h);

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

	if (r.sides[0] == sides[0] && r.height == height)
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
	SetDim(r.sides[0],r.height);
}

/// @brief total reset of the object  
void Isosceles::Reset() {
	
	SetDim(0,0);
	
}


/// @brief set width of the object
/// @param w width 
void Isosceles::SetWidth(float w) {

	if (w < 0.) {
		WarningMessage("SetWidth: width should be > 0");
		return;
	}

	SetDim(w,height);

}

/// @brief set height of the object
/// @param h height 
void Isosceles::SetHeight(float h) {

	if (h < 0.) {
		WarningMessage("SetHeight: height should be > 0");
		return;
	}

	SetDim(sides[0],h);

}



/// @brief get width of the object
/// @return width 
float Isosceles::GetWidth() {

	return sides[0];

}

/// @brief get length of the object
/// @return height
float Isosceles::GetHeight() {

	return height;
}

/// @brief set width and length of the object
/// @param w width 
/// @param h height
void Isosceles::SetDim(float w, float h) {

	height = h;  
	float l = (float)sqrt(pow(w/2, 2) + pow(h, 2));
	Triangle::SetSides(w, l, l);
	
	return;
}

/// @brief get width and length of the object
/// @param w width 
/// @param h height
void Isosceles::GetDim(float &w, float &h) {

	w = sides[0];
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


/// @brief for debugging: all about the object
void Isosceles::Dump() {
	cout << endl;
	cout << "---Isosceles---" << endl; 
	cout << endl;
	
	cout << "Width = " << sides[0] << endl;
	cout << "Heigth = " << height << endl;
	
	Triangle::Dump();
	
	cout << endl;

}






