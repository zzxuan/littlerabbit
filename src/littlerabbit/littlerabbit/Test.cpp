#include <stdio.h>
#include "GetMsgInfo.h"
#include "windows.h" 
#include "iostream"
#include "string"



using namespace std;



void main()
{
	GetMsgInfo msg ;
	msg.GetComputerMsg();
	cout<<"本机信息如下:"<<endl;
	vector<PCMsg>::iterator it;
	for(it=msg.msgVec.begin();it!=msg.msgVec.end();it++)
		cout<<it->msgType<<":"<<it->msgName<<":"<<it->msgVal<<endl;
	getchar();
}