/// \file CEquilateral.cpp
///	\brief class Equilateral: implementation of the functions
///
///	Details.
///

#include <iostream> 
#include <cmath>
#include "CEquilateral.h"

/// @brief default constructor 
Equilateral::Equilateral() {

	cout << "Equilateral - constructor - default" << endl;

	Init();

}

/// @brief constructor 
/// @param s side
Equilateral::Equilateral(float s) {

	Init();

	cout << "Equilateral - constructor" << endl;

	if (s <= 0.) {
		WarningMessage("constructor: side should be > 0"); 
		SetDims(0);
	}
	else
		SetDims(s);

}

/// @brief destructor 
Equilateral::~Equilateral() {

	cout << "Equilateral - destructor" << endl;
	Reset();

}

/// @brief copy constructor 
/// @param o reference to the object that should be copied 
Equilateral::Equilateral(const Equilateral &r) { 

	cout << "Equilateral - copy constructor" << endl;

	Init(r);
	
}

/// @brief overload of operator = 
/// @param o reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
Equilateral& Equilateral::operator=(const Equilateral &r) { 

	cout << "Equilateral - operator =" << endl;

	Init(r);
	
	return *this;
	
}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two objects have the same side
bool Equilateral::operator==(const Equilateral &r) { 

	if (r.sides[0] == sides[0])
		return true;
		
	return false;
}

/// @brief default initialization of the object
void Equilateral::Init() {
	SetDims(0);
}

/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void Equilateral::Init(const Equilateral &r) {
	Init();
	SetDims(r.sides[0]);
}

/// @brief total reset of the object  
void Equilateral::Reset() {
	SetDims(0);
}

/// @brief get side of the object
/// @return side 
float Equilateral::GetSide() {
	return sides[0];
}

/// @brief set the diagonals of the object
/// @param s side
void Equilateral::SetDims(float s) {

	Triangle::SetSides(s, s, s);
	
	return;
}

/// @brief write an error message 
/// @param string message to be printed
void Equilateral::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- Equilateral --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void Equilateral::WarningMessage(const char *string) {
	
	cout << endl << "WARNING -- Equilateral --";
	cout << string << endl;

}


/// @brief for debugging: all about the object
void Equilateral::Dump() {
	cout << endl;
	cout << "---Equilateral---" << endl; 
	cout << endl;
	
	cout << "Side = " << GetSide() << endl;
	
	Triangle::Dump();
	
	cout << endl;
}








