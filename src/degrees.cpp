/*
 * degtodec.cpp
 *
 *  Created on: 28 Oct 2022
 *      Author: jole
 *      
 *	source code for convert deg/min/sec to decimaldegrees      
 *      
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "src/degrees.h"


convertDegrees::convertDegrees(char* _inputString, mode m, char separator, bool _verbose)
{
	degreeSeparator = separator;
	inputString		= _inputString;
	verbose			= _verbose;
	
	switch(m){
		case degToDec:	degreesToDecimalConversion();
						break;
		case decToDeg:	decimalToDegreesConversion();
						break;
		default:		break;
	}
}


void convertDegrees::degreesToDecimalConversion(void)
{
	char*	ptrBuffer = inputString;

	//printf("Input: %s\n", input);
	deg = atoi(ptrBuffer);
	//printf("Deg: %d\n", deg);

	while(*ptrBuffer++ != degreeSeparator);

	//printf("Input: %s\n", input);
	min = atoi(ptrBuffer);
	//printf("Min: %d\n", min);

	while(*ptrBuffer++ != degreeSeparator);

	//printf("Input: %s\n", input);
	sec = atof(ptrBuffer);
	//printf("Sec: %f\n", sec);
	decDegrees = deg + min/60.0 + sec/3600.0;
	//printf("decimalDegrees: %f\n", decDegrees);

	return;
}



//	TODO: Add capability to use , (comma) as decimal separator instead of . (puntuation mark)

void convertDegrees::decimalToDegreesConversion(void)
{
	double	outputValue, inputValue;
	char*	ptrBuffer = inputString;



	decDegrees = inputValue = atof(ptrBuffer);
	if(verbose)
		printf("inputValue: %f\n", inputValue);

	deg = (int) inputValue;
	outputValue = inputValue - deg;
	if(verbose)
		printf("deg: %d, outputValue: %8.5f, inputValue: %8.5f\n", deg, outputValue, inputValue);

	inputValue = outputValue * 60.0;
	min = (int) inputValue;
	outputValue = inputValue - min;
	if(verbose)
		printf("min: %d, outputValue: %8.5f, inputValue: %8.5f\n", min, outputValue, inputValue);

	inputValue = outputValue * 60.0;
	sec = (float)inputValue;
	if(verbose)
		printf("sec: %8.5f, outputValue: %8.5f, inputValue: %8.5f\n", sec, outputValue, inputValue);

	if(verbose)
		printf("\n");

	return;
}
