#include "EasyTcpServer.hpp"
int main()
{
	EasyTcpSetver  server;
	server.InitSocket();//�����ڰ󶨵�ʱ��������������ˣ����Բ��ó�ʼ����
	server.Bind(nullptr,4567);
	server.Listen(5);
	while (server.isRun())
	{
		server.OnRun();

	}

	while (true)
	{
		
		//printf("����ʱ�䴦������ҵ��..\n");
	}

	printf("���˳���\n");
	getchar();
	return 0;
}