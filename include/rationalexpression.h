/** Rational Calculator: Rational expression class header.
 *
 *  @file rationalexpression.h
 *  @brief A class that represents a rational expression.
 *
 *  In this class header file, comments will shorten RationalExpression to Rex.
 *
 *  @author Rafe Saltman, Chris Lawrence, and Santiago Daza
 *  @version 0.1.0
 *  @date March 21, 2023
 */

#ifndef rationalexpression_h
#define rationalexpression_h

#include <stdio.h>
#include <string>
#include "ratio.h"
using namespace std;

class RationalExpression {
private:
	Ratio * _knownRatio;
	char _operator;
	RationalExpression * _leftOperand;
	RationalExpression * _rightOperand;

public:
	// Rex constructors, destructor, and move assignment.
	RationalExpression ();
	RationalExpression (Ratio *);
	~RationalExpression () {}
	RationalExpression (RationalExpression &&);
	RationalExpression & operator = (RationalExpression &&);

	// Ratio getter.
	Ratio * getRatio();

	// Give whether a Rex has a particular operand.
	bool hasLeft();
	bool hasRight();

	// Converts a sequence of tokens into a Rex.
	void interpret (string * token, int first, int last);

	// Evaluates a Rex (that has one or two operands) by rational arithmetic.
	void evaluate ();
};


// Helper non-member functions.
// From an opening parenthesis, finds the index of the token just before the matching closing parenthesis.
int matchingParenthesis (string * token, int first, int last);


#endif