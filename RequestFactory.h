#pragma once
#include"CodecFactory.h"
#include"Request.h"
#include<iostream>

class RequestFactory : public CodecFactory {
public:
	RequestFactory(std::string encstr);
	RequestFactory(RequestInfo* info);
	Codec* createCodec();
	~RequestFactory();

private:
	bool m_flag;
	std::string m_encStr;
	RequestInfo* m_info;
};
