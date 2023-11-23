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
	bool	verbose;
	double	sec, decDegrees;
	
	char	*inputString;
	char	degreeSeparator;
	
	void degreesToDecimalConversion(void);
	void decimalToDegreesConversion(void);

public:
	convertDegrees(char* _inputString, mode m, char separator, bool _verbose);
	
	
	int		getDeg(void)		{return deg;}
	int		getMin(void)		{return min;}
	double	getSec(void)		{return sec;}
	
	double getDecDegrees(void)	{return decDegrees;}
	
};

#endif
