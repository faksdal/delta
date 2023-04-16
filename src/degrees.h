/*
 * degrees.h
 *
 *  Created on: 28 Oct 2022
 *      Author: jole
 *      
 *	source definitions for convertion between deg.min.sec and decimaldegrees
 *      
 */

#ifndef __degrees_h__
#define __degrees_h__

//float degtodec(char *inputString);

enum	mode {degToDec, decToDeg};

class convertDegrees {
	int		deg, min;
	float	decDegrees;
	float	sec;
	
	char	*inputString;
	char	degreeSeparator;
	
	void invoceDegreesToDecimalConvertion(char* input);

public:
	convertDegrees(char* input, mode m, char separator);
	
	
	int		getDeg(void){return deg;}
	int		getMin(void){return min;}
	float	getSec(void){return sec;}
	
	float getDecDegrees(void){return decDegrees;}
	
};

#endif
