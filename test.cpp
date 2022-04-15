#include<iostream>
#include"Codec.h"
#include"Request.h"
#include"Response.h"
#include"RequestFactory.h"
#include"RespondFactory.h"

int main() {
	//数据编码
	RequestInfo info{ 1, "拉姆", "蕾姆", "YingYing", "Cute" };		//创建要进行编码的数据
	CodecFactory* factory = new RequestFactory(&info);				//使用工厂类创建编码类
	Codec* codec = factory->createCodec();
	string str = codec->encodeMsg();
	cout << "序列化后的数据为:" << str << endl;
	delete factory;		factory = nullptr;							//释放地址空间
	delete codec;		  codec = nullptr;
	//解码数据
	factory = new RequestFactory(str);								//使用工厂类创建编解码类
	codec = factory->createCodec();									
	RequestMsg* r1 = (RequestMsg*)codec->decodeMsg();				//解码, 返回void* 强转
	cout
		<< "cmdType:"  << r1->cmdtype()  << "\t"
		<< "clientID:" << r1->clientid() << "\t"
		<< "serverID:" << r1->serverid() << "\t"
		<< "sign:"     << r1->sign()     << "\t"
		<< "data:"     << r1->data()     << endl;
	delete factory;		factory = nullptr;							
	delete codec;		  codec = nullptr;

	cout << "===================================================================================" << endl;

	//数据编码
	RespondInfo info_res{ 2, 2012, "曹玄兵", "曹玄亮", "Cool" };		//创建进行编码的数据
	factory = new RespondFactory(&info_res);						//创建工厂类
	codec = factory->createCodec();									//生成编码类
	str = codec->encodeMsg();										//编码
	cout << "序列化后的数据为:" << str << endl;						//对序列化后的数据进行展示
	delete factory;		factory = nullptr;
	delete codec;		  codec = nullptr;

	//数据解码
	factory = new RespondFactory(str);								//创建工厂类
	codec = factory->createCodec();									//生成编解码类
	RespondMsg* r2 = (RespondMsg*)codec->decodeMsg();				//解码,将返回值强转成RespondMsg
	cout
		<< "status:"   << r2->status()   << "\t"
		<< "secketID:" << r2->seckeyid() << "\t"
		<< "clientID:" << r2->clientid() << "\t"
		<< "serverID:" << r2->serverid() << "\t"
		<< "data:"     << r2->data()     << endl;
	delete factory;		factory = nullptr;
	delete codec;		  codec = nullptr;

	return 0;
}