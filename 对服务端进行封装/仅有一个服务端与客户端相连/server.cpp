#include "EasyTcpServer.hpp"
int main()
{
	EasyTcpSetver  server;
	server.InitSocket();//我们在绑定的时候做了这个事情了，所以不用初始化了
	server.Bind(nullptr,4567);
	server.Listen(5);
	while (server.isRun())
	{
		server.OnRun();

	}

	while (true)
	{
		
		//printf("空闲时间处理其它业务..\n");
	}

	printf("已退出。\n");
	getchar();
	return 0;
}