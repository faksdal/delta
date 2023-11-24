/*
 * dtd.cpp
 *
 *  Created on: 28 Oct 2022
 *      Author: jole
 *      
 * dtd is a command line utility to convert between deg/min/sec and decimal degrees, and vice versa
 *  - expanded to include celcuis-fahrenheit conversion
 *  - restructuring into c++ classes
 */


#include <math.h>
#include <stdio.h>
#include <getopt.h>
#include "src/degrees.h"


void printUsage(void);




int main(int argc, char *argv[])
{
	int		c, optionIndex, deg, min, sec;
	bool	verbose = false;
	char	*shortOptions = (char*)"";
	float	float_sec;
	float	input = 0L, output;
	

	struct option longOptions[] = {
		{"degtodec",	required_argument,	NULL,	1},
		{"dectodeg",	required_argument,	NULL,	2},
		{"verbose",		no_argument,		NULL,	3},
		{"ctof",		required_argument,	NULL,	4},
		{"ftoc",		required_argument,	NULL,	5},
		{"help",		required_argument,	NULL,	6},
		{0, 0, 0, 0}
	};
	
	//printf("\ndelta, a command line converting utility by Jon Leithe!\n\n");

	if(argc < 2){
		printf("Too few arguments!\n");
		printUsage();
		return (2);
	}
	
	
	
	while((c = getopt_long(argc, argv, shortOptions, longOptions, &optionIndex)) != -1){
		switch(c){
			case 1:		{
							convertDegrees d(optarg, degToDec, '-', verbose);

							if(verbose)
								printf("Conversion: %d°%d'%f'' =  %12.9f°\n", d.getDeg(), d.getMin(), d.getSec(), d.getDecDegrees());
							else
								printf("%12.9f°\n", d.getDecDegrees());
							break;
						}
			case 2:		{
							convertDegrees d(optarg, decToDeg, '-', verbose);

							if(verbose)
								printf("Conversion: %12.9f° = %d°%d'%12.9f''\n", d.getDecDegrees(), d.getDeg(), d.getMin(), d.getSec());
							else
								printf("%d°%d'%12.9f''\n", d.getDeg(), d.getMin(), d.getSec());
							break;
						}
			case 3:		{
							verbose = true;
							break;
						}
			case 4:		{
							input = atof(optarg);
							output = ((input * 9/5) + 32);
							printf("%f°C = %f°F\n\n", input, output);
							break;
						}
			case 5:		{
							input = atof(optarg);
							output = ((input - 32) * 5/9);
							printf("%f°F = %f°C\n\n", input, output);
							break;
						}
			case 6:		//invoceatob()
						printUsage();
						break;
			default:	//printf("No option set!\n");
						printUsage();
						break;
		}
	}
	

	//printf("\n");
	return 0;
}



void printUsage(void)
{
	printf("Usage: delta --degtodec <deg>-<min>-<sec>\n");
	printf("       delta --dectodeg <decimaldegrees>\n");
	printf("       delta --ctof <degrees Celcius>\n");
	printf("       delta --ftoc <degrees Fahrenheit>\n");
}
