////////////////////////////////////////////////////////////////////////////////
// SExpression.cpp
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////////////////////////
#include "SExpression.hpp"
#include <sstream>

SExpression::VariableMap SExpression::m_variables;

////////////////////////////////////////////////////////////////////////////////
SExpression::SExpression()
{
	m_type = Nil;
}

////////////////////////////////////////////////////////////////////////////////
SExpression::SExpression(int number)
{
	m_type   = Number;
	m_number = number;
}

////////////////////////////////////////////////////////////////////////////////
SExpression::SExpression(const std::string& atom)
{
	m_type = Atom;
	m_atom = atom;
}

////////////////////////////////////////////////////////////////////////////////
SExpression::SExpression(SExpressionPtr car,SExpressionPtr cdr)
{
	m_type = DottedPair;
	m_car  = car;
	m_cdr  = cdr;
}

////////////////////////////////////////////////////////////////////////////////
int SExpression::getNumber() const
{
	if(m_type != Number)
		throw std::string("Error: Number type required");
	return m_number;
}

////////////////////////////////////////////////////////////////////////////////
const std::string& SExpression::getAtom() const
{
	if(m_type != Atom)
		throw std::string("Error: Atom type required");
	return m_atom;
}

////////////////////////////////////////////////////////////////////////////////
SExpression::SExpressionPtr SExpression::getCar() const
{
	if(m_type != DottedPair)
		throw std::string("Error: DottedPair type required");
	return m_car;
}

////////////////////////////////////////////////////////////////////////////////
SExpression::SExpressionPtr SExpression::getCdr() const
{
	if(m_type != DottedPair)
		throw std::string("Error: DottedPair type required");
	return m_cdr;
}

////////////////////////////////////////////////////////////////////////////////
SExpression::Type SExpression::getType() const
{
	return m_type;
}

////////////////////////////////////////////////////////////////////////////////
int SExpression::stringToInteger(const std::string& str)
{
	int number;
	std::istringstream(str) >> number;
	return number;
}

////////////////////////////////////////////////////////////////////////////////
SExpression::SExpressionPtr SExpression::stringToAtom(const std::string& token)
{
	if(m_variables.find(token) == m_variables.end())
	{
		m_variables.insert(VariablePair(token,new SExpression(token)));
	}

	return m_variables[token];
}
