#include "EasyTcpClient.hpp"
#include<thread>

void cmdThread(EasyTcpClient* client)//因为线程只跟输入数据有关，所以不用封装到类中
{
	while (true)
	{
		char cmdBuf[256] = {};
		scanf("%s", cmdBuf);
		if (0 == strcmp(cmdBuf, "exit"))
		{
			client->Close();
			printf("退出cmdThread线程\n");
			break;
		}
		else if (0 == strcmp(cmdBuf, "login"))
		{
			Login login;
			strcpy(login.userName, "lyd");
			strcpy(login.PassWord, "lydmm");
			client->SendData(&login);

		}
		else if (0 == strcmp(cmdBuf, "logout"))
		{
			Logout logout;
			strcpy(logout.userName, "lyd");
			client->SendData(&logout);
		}
		else {
			printf("不支持的命令。\n");
		}
	}
}

int main()
{

	EasyTcpClient client;
	client.Connect("127.0.0.1", 4568);
	//EasyTcpClient client2
	//client2.Connect("127.0.0.1", 4568);

	//启动UI线程
	//std::thread t1(cmdThread, &client);//因为thread在linux和window下实现是有区别的，所以用指针是最方便的
	//t1.detach();
	//std::thread t2(cmdThread, &client2);//因为thread在linux和window下实现是有区别的，所以用指针是最方便的
	//t2.detach();

	Login login;
	strcpy(login.userName, "lyd");
	strcpy(login.PassWord, "lydmm");

	while (client.isRun())
	{
		client.OnRun();
		client.SendData(&login);
		//client2.OnRun();
		//printf("空闲时间处理其它业务..\n");
		//Sleep(1000);
	}
	client.Close();
	//client2.Close();

	printf("已退出。\n");
	getchar();
	return 0;
}