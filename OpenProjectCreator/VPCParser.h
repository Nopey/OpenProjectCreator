#pragma once

#include "BaseParser.h"
#include <vector>


class VPCParser : public BaseParser
{
public:

private:
	VPCParser() {}
	virtual instructionData_t* ParseInstruction(const char* str, size_t& i, size_t length, ErrorCode& error);
	virtual void ReadSubblock(const char* str, size_t& i, size_t length, ErrorCode& error);
	virtual void SeekEndOfSubblock(const char* str, size_t& i, size_t length, ErrorCode& error);

	//virtual instruction_t* GetInstruction(const char* str, size_t length);
	virtual void SkipWhitespace(const char* str, size_t& i, size_t length);

	virtual bool ParseCondition(const char* str, size_t& i, size_t length, ErrorCode& error);

	virtual instruction_t* GetInstruction(insetString_t str);
	virtual void CacheInstructionData(instructionData_t* instructionData) { m_instructionDataList.push_back(instructionData); }


	std::vector<instructionData_t*> m_instructionDataList;
	instruction_t* m_instructionSet;

};

