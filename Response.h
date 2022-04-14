#pragma once
#include"Codec.h"
#include<iostream>
#include"message.pb.h"
using namespace std;

struct RespondInfo {
	int status;
	int seckeyID;
	string clientID;
	string serverID;
	string data;
};

class RespondCodec : public Codec {
public:
	RespondCodec();
	RespondCodec(string encstr);
	RespondCodec(RespondInfo* info);
	void initMessage(string encstr);
	void initMessage(RespondInfo* info);
	string encodeMsg();
	void* decodeMsg();
	~RespondCodec();

private:
	string m_encstr;
	RespondMsg m_msg;
};