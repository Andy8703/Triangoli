/*! \file CIsosceles.h
	\brief Declaration of the class Isosceles

	Details.
*/

#ifndef ISOSCELES_H
#define ISOSCELES_H

#include<iostream>

#include "CTriangle.h"

using namespace std;

/// @class Isosceles
/// @brief to manage an object with the shape of an isosceles triangle
class Isosceles : public Triangle
{
protected:
	float height;

public:
	
	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Isosceles();
	Isosceles(float w, float h);
	Isosceles(const Isosceles &r);
	
	~Isosceles();
	/// @}
	
	/// @name OPERATORS
	/// @{
	Isosceles& operator=(const Isosceles &r); 
	bool operator==(const Isosceles &r);
	/// @}
	
	/// @name BASIC HANDLING
	/// @{
	void Init();												
	void Init(const Isosceles &r);							
	void Reset();												
	/// @}
	
	
	/// @name GETTERS / SETTERS
	/// @{
	void SetHeight(float h);
	void SetWidth(float w);
	void SetDim(float w, float h);
	
	void GetDim(float &w, float &h);
	float GetHeight();
	float GetWidth(); 
	
	/// @}
	
	
	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); 
	void WarningMessage(const char *string);
	void Dump();
	/// @}
		
};

#endif