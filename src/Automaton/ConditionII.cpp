/*
 * ConditionII.cpp
 *
 *  Created on: Aug 27, 2016
 *      Author: Kai Yan
 */

#include "ConditionII.h"

namespace kai
{

ConditionII::ConditionII()
{
	ConditionBase();
	m_p1 = NULL;
	m_p2 = NULL;
}

ConditionII::~ConditionII()
{
}

bool ConditionII::isSatisfied(void)
{
	if(m_p1==NULL)return false;
	if(m_p2==NULL)return false;

	int p1 = (int)(*m_p1);
	int p2 = (int)(*m_p2);

	switch (m_condition)
	{
	case bt:
		if(p1 > p2)return true;
		break;
	case beq:
		if(p1 >= p2)return true;
		break;
	case st:
		if(p1 < p2)return true;
		break;
	case seq:
		if(p1 <= p2)return true;
		break;
	case eq:
		if(p1 == p2)return true;
		break;
	case neq:
		if(p1 != p2)return true;
		break;
	default:
		return false;
		break;
	}

	return false;
}

bool ConditionII::setPtrByName(string name, int* ptr)
{
	if(ptr==NULL)return false;
	if(name=="")return false;

	if(name==m_namePtr1)m_p1 = ptr;
	if(name==m_namePtr2)m_p2 = ptr;

	return true;
}

bool ConditionII::setPtrByName(string name, double* ptr)
{
	if(ptr==NULL)return false;
	if(name=="")return false;

	if(name==m_namePtr1)m_p1 = (int*)ptr;
	if(name==m_namePtr2)m_p2 = (int*)ptr;

	return true;
}


} /* namespace kai */
