#pragma once
#include "windows.h" 
#include "iostream"
#include "string"


void ExeCPUID(DWORD veax);//初始化CPU
long GetCPUFreq();//获取CPU频率,单位: MHZ
void GetManID(char *ID,int len);//获取制造商信息
void GetCpuTypeMsg(char *CPUType,int len);