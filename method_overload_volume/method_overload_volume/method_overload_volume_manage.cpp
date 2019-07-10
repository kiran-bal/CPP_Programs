
/**
 * File func_manage.cpp - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains implementation of function overloading for Volume of shapes.
 *
 * Author   : Kiran Bal
 * Version  : 1.0.0
 * Date     : 05-07-2019
 *
 */

#include "method_overload_volume_manage.h"

float fResult;
int nChoice;
int nRadius;
int nLengthInput;
int nBreadthInput;
int nHeightInput;

// -------------------------------------------------------
// Method      : Volume
// Parameters  :
//	<param 1> - <int iLength> - length of the Prism.
//  <param 2> - <int iBreadth> - Breadth of the Prism.
// Returns     : <int nVolumePrism> - Volume calculated by the function.
// Description : Returns the Volume of Prism.
// -------------------------------------------------------

float Volume( /*IN*/ float fLength, /*IN*/ float fBreadth, /*IN*/ float fHeight )
{
    float fVolumePrism;
    fVolumePrism = fLength * fBreadth * fHeight;
    return fVolumePrism;
}

// -------------------------------------------------------
// Method      : Volume
// Parameters  :
//	<param 1> - <int fRadius> - Radius of the Cube.
// Returns     : <int nVolumeCube> - Volume calculated by the function.
// Description : Returns the Volume of Cube.
// -------------------------------------------------------

float Volume( /*IN*/ float fLength )
{
    float fVolumeCube;
    fVolumeCube = fLength * fLength * fLength;
    return fVolumeCube;
}

// -------------------------------------------------------
// Method      : Volume
// Parameters  :
//	<param 1> - <int iLength> - length of the Prism.
//  <param 2> - <int iBreadth> - Breadth of the Prism.
//  <param 3> - <int iHeight> - Height of the Pyramid.
// Returns     : <int nVolumePyramid> - Volume calculated by the function.
// Description : Returns the Volume of Pyramid.
// -------------------------------------------------------

float Volume( /*IN*/ int nLength, /*IN*/ int nHeight )
{
    float fVolumePyramid;
    fVolumePyramid = (1/3) * nLength * nHeight;
    return fVolumePyramid;
}

// -------------------------------------------------------
// Method      : CubeVolume
// Parameters  : Nil
// Returns     : void
// Description : Displays the Volume of Cube.
// -------------------------------------------------------

void CubeVolume()
{
    float nSide1;
    cout << "Enter Length of cube: ";
    cin  >> nSide1;

	//overload function
    fResult = Volume( nSide1 );
    cout << "Volume of cube is : " << fResult << "\n\n";
}

// -------------------------------------------------------
// Method      : PrismVolume
// Parameters  : Nil
// Returns     : void
// Description : Displays the Volume of Prism.
// -------------------------------------------------------

void PrismVolume()
{
    float fLengthPrism;
    float fBreadthPrism;
    float fHeightPrism;

    cout << "\nEnter length of prism: ";
    cin >> fLengthPrism;
    cout << "\nEnter breadth of prism: ";
    cin >> fBreadthPrism;
    cout << "\n Enter Height of Prism: ";
    cin >> fHeightPrism;

	//overload function
    fResult = Volume(fLengthPrism, fBreadthPrism, fHeightPrism);
    cout << "Volume of prism is:" << fResult << "\n\n";
}

// -------------------------------------------------------
// Method      : PyramidVolume
// Parameters  : Nil
// Returns     : void
// Description : Displays the Volume of Pyramid.
// -------------------------------------------------------

void PyramidVolume()
{
    float fBaseLength;
    float fHeightPyramid;
    cout << "\nEnter base length of Pyramid: ";
    cin >> fBaseLength;
    cout << "\nEnter the height of pyramid: ";
    cin >> fHeightPyramid;

	//overload function
    fResult = Volume(fBaseLength, fHeightPyramid);
    cout << "Volume of pyramid is: " << fResult << "\n\n";
}
