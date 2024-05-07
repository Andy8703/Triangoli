#include <iostream>

#include "CTriangle.h"
#include "CIsosceles.h"
#include "CEquilateral.h"

int main() {

	Triangle *A, *B, *C; 
	float s1,s2,s3;
	
	Isosceles isoA(10,5);
	Isosceles isoB(3,7);
	Equilateral equC(2);
	
	A = &isoA;
	B = &isoB;
	C = &equC;

	cout << endl;
	cout << "**** Triangle A ****" << endl;
	A->Dump(); 
	cout << "**** ***** ****" << endl;
	cout << "**** Triangle B ****" << endl;
	B->Dump(); 
	cout << "**** ***** ****" << endl;
	cout << "**** Triangle C ****" << endl;
	C->Dump(); 
	cout << "**** ***** ****" << endl;
	
	cout << endl;
	cout << "**** Isosceles A ****" << endl;
	isoA.Dump(); 
	cout << "**** ***** ****" << endl;
	cout << "**** Isosceles B ****" << endl;
	isoB.Dump(); 
	cout << "**** ***** ****" << endl;
	cout << "**** Equilateral C ****" << endl;
	equC.Dump(); 
	cout << "**** ***** ****" << endl;
	
	isoA = isoB; 
	
	cout << endl;
	cout << "**** Triangle A ****" << endl;
	A->Dump(); 
	cout << "**** ***** ****" << endl;
	cout << "**** Triangle B ****" << endl;
	B->Dump(); 
	cout << "**** ***** ****" << endl;
	
	isoB.SetWidth(12);
	cout << endl;
	cout << "**** Triangle A ****" << endl;
	A->Dump(); 
	cout << "**** ***** ****" << endl;
	cout << "**** Triangle B ****" << endl;
	B->Dump(); 
	cout << "**** ***** ****" << endl;
	
	B->GetSides(s1,s2,s3);
	cout << "Isosceles B - sides:" << s1 << " " << s2 << " "<< s3 << endl; 
	
	C->GetSides(s1,s2,s3);
	cout << "Equilateral C - sides:" << s1 << " " << s2 << " "<< s3 << endl;
	
	equC.SetDims(8);
	C->GetSides(s1,s2,s3);
	cout << "Equilateral C - sides:" << s1 << " " << s2 << " "<< s3 << endl;

//	C->GetArea(); 
	
		
	
	return 0;

}