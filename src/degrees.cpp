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


convertDegrees::convertDegrees(char* _inputString, mode m, char separator)
{
	degreeSeparator = separator;
	inputString		= _inputString;
	
	switch(m){
		case degToDec:	degreesToDecimalConvertion();
						break;
		case decToDeg:	decimalToDegreesConvertion();
						break;
		default:		break;
	}
}


void convertDegrees::degreesToDecimalConvertion(void)
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



void convertDegrees::decimalToDegreesConvertion(void)
{
	double	outputValue, inputValue;
	char*	ptrBuffer = inputString;



	decDegrees = inputValue = atof(ptrBuffer);
	printf("inputValue: %f\n", inputValue);

	deg = (int) inputValue;
	outputValue = inputValue - deg;
	printf("deg: %d, outputValue: %8.5f, inputValue: %8.5f\n", deg, outputValue, inputValue);

	inputValue = outputValue * 60.0;
	min = (int) inputValue;
	outputValue = inputValue - min;
	printf("min: %d, outputValue: %8.5f, inputValue: %8.5f\n", min, outputValue, inputValue);

	inputValue = outputValue * 60.0;
	sec = (float)inputValue;
	printf("sec: %8.5f, outputValue: %8.5f, inputValue: %8.5f\n", sec, outputValue, inputValue);

	printf("\n");

	return;
}
