#pragma once
#include<iostream>

class Codec
{
public:
	Codec();
	virtual std::string encodeMsg();
	virtual void* decodeMsg();

	virtual ~Codec();
};

int main() {
	int a = 10;
	int b = 20;
	string a = "asd";
}