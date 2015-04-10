#pragma once
#include<vector>

typedef struct PCMsg
{
	char msgType[20];
	char msgName[256];
	char msgVal[256];
	int msgID;
	
};

void SetPCMsg(PCMsg *msg,int id,char* tpye,char* name,char* val);



class GetMsgInfo
{
	
public:
	std::vector<PCMsg> msgVec;
	GetMsgInfo(void);
	~GetMsgInfo(void);
	void GetComputerMsg();

	void GetCpuType();

	void GetMemMsg();
};

