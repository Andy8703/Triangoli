/*! \file CIsosceles.h
	\brief Declaration of the class Isosceles

	Details.
*/

#ifndef ISOSCELES_H
#define ISOSCELES_H

#include<iostream>
#include "CScalene.h"

using namespace std;

/// @class Isosceles
/// @brief to manage an object with the shape of an isosceles triangle
class Isosceles : public Scalene {
protected:
	float base;
	float height;
	double GetArea();

public:
	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Isosceles();
	Isosceles(float b, float h);
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
	void SetBase(float b);
	void SetDim(float b, float h);
	
	void GetDim(float &b, float &h);
	float GetHeight();
	float GetBase(); 
	/// @}
	
	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); 
	void WarningMessage(const char *string);
	void Dump();
	/// @}	
};

#endif