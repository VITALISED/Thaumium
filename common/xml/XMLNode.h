#pragma once

#include "../../pch.h"

#include "XMLAttribute.h"
#include "XMLClear.h"

struct XMLNode
{
	struct ALIGN(8) XMLNodeDataTag
	{
		const char* lpszName;
		int nChild;
		int nText;
		int nClear;
		int nAttribute;
		char isDeclaration;
		XMLNode::XMLNodeDataTag* pParent;
		XMLNode* pChild;
		const char** pText;
		XMLClear* pClear;
		XMLAttribute* pAttribute;
		int* pOrder;
		int ref_count;
	};

	XMLNode::XMLNodeDataTag* d;
};
