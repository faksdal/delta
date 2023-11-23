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

enum	mode {degToDec, decToDeg};



class convertDegrees {

	int		deg, min;
	bool	verbose;
	char	*inputString;
	char	degreeSeparator;
	double	sec, decDegrees;
	
	

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
