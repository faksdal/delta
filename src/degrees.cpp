/*
 * degtodec.cpp
 *
 *  Created on: 28 Oct 2022
 *      Author: jole
 *      
 *	source code for convert deg/min/sec to decimaldegrees      
 *      
 */

#include "math.h"
#include <stdio.h>
#include <stdlib.h>
#include "src/degrees.h"


convertDegrees::convertDegrees(char* optarg, mode m, char separator)
{
	degreeSeparator = separator;
	
	switch(m){
		case degToDec:	invoceDegreesToDecimalConvertion(optarg);
						break;
		case decToDeg:	invoceDecimalToDegreesConvertion(optarg);
						break;
		default:		break;
	}
}


void convertDegrees::invoceDegreesToDecimalConvertion(char* optarg)
{
	//printf("Input: %s\n", input);
	deg = atoi(optarg);
	//printf("Deg: %d\n", deg);

	while(*optarg++ != degreeSeparator);

	//printf("Input: %s\n", input);
	min = atoi(optarg);
	//printf("Min: %d\n", min);

	while(*optarg++ != degreeSeparator);

	//printf("Input: %s\n", input);
	sec = atof(optarg);
	//printf("Sec: %f\n", sec);
	decDegrees = deg + min/60.0 + sec/3600.0;
	//printf("decimalDegrees: %f\n", decDegrees);

	return;
}



void convertDegrees::invoceDecimalToDegreesConvertion(char* optarg)
{
	float	output, input;



	input = atof(optarg);
	printf("Optarg: %s, Input %f\n", optarg, input);

	deg = atoi(optarg);
	printf("Deg: %d\n", deg);

	input = atof(optarg) - deg;
	printf("Input: %f\n", input);

	output = input * 60.0;
	printf("Output: %f, input: %f\n", output, input);

	min = (output);
	printf("Min: %d\n", min);

	input

	/*
	while(*optarg++ != '.');
	*optarg--;
	printf("Optarg %s\n", optarg);

	min = round(output = atof(optarg) * 60.0);
	printf("Min: %d\n", min);

	output -= min;
	sec = (output * 60);
	printf("%f° = %d°%d'%f''\n\n", input, deg, min, sec);
	*/

	/*
	printf("Input: %s\n", input);
	deg = atoi(input);
	printf("Degrees: %d\n", deg);

	while(*input++ != ".");
	*input--;
	min = round(output = atof(input) * 60.0);

	printf("Input: %s\n", input);
	*input--;
	printf("Input: %s\n", input);
	min = round(output = atof(input) * 60.0);

	//printf("\n\n Output: %f", output);
	//output -= min;
	//printf("\n\n Output: %f\n", output);
	//float_sec = (output*60);
	//printf("%f° = %d°%d'%f''\n\n", input, deg, min, float_sec);
	*/
	return;
}
