/*! \file CScalene.h
	\brief Declaration of the general class Scalene

	Details.
*/

#ifndef SCALENE_H
#define SCALENE_H

#include <iostream>

using namespace std;

/// @class Scalene
/// @brief an abstract base class for Scalene
class Scalene {
protected:

	float sides[3];
	
	void SetSides(float s1, float s2, float s3); 
	virtual double GetArea();

public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Scalene();
	Scalene(const Scalene &o);
	virtual ~Scalene();
	/// @}
	
	/// @name OPERATORS
	/// @{
	Scalene& operator=(const Scalene &o); 
	bool operator==(const Scalene &o);
	/// @}
	
	/// @name BASIC HANDLING
	/// @{
	void Init();												
	void Init(const Scalene &o);							
	void Reset();												
	/// @}
	
	/// @name GETTERS
	/// @{
	double GetPerimeter();
	void GetSides(float &s0, float &s1, float &s2);
	/// @}
	
	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); 
	void WarningMessage(const char *string);
	void Dump();
	/// @}
};

#endif