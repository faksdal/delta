/*
 * degtodec.cpp
 *
 *  Created on: 28 Oct 2022
 *      Author: jole
 *      
 *	source code for convert deg/min/sec to decimaldegrees      
 *      
 */

#include <stdio.h>
#include <stdlib.h>
#include "src/degrees.h"


convertDegrees::convertDegrees(char* input, mode m, char separator)
{
	degreeSeparator = separator;
	
	switch(m){
		case degToDec:	invoceDegreesToDecimalConvertion(input);
						break;
		case decToDeg:	break;
		default:		break;
	}
}


void convertDegrees::invoceDegreesToDecimalConvertion(char* input)
{
	//printf("Input: %s\n", input);
	deg = atoi(input);
	//printf("Deg: %d\n", deg);

	while(*input++ != degreeSeparator);

	//printf("Input: %s\n", input);
	min = atoi(input);
	//printf("Min: %d\n", min);

	while(*input++ != degreeSeparator);

	//printf("Input: %s\n", input);
	sec = atof(input);
	//printf("Sec: %f\n", sec);
	decDegrees = deg + min/60.0 + sec/3600.0;
	//printf("decimalDegrees: %f\n", decDegrees);
}
