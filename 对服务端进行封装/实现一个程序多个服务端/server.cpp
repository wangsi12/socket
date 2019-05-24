#include "EasyTcpServer.hpp"
int main()
{
	EasyTcpSetver  server1;
	server1.InitSocket();//我们在绑定的时候做了这个事情了，所以不用初始化了
	server1.Bind(nullptr,4567);
	server1.Listen(5);

	EasyTcpSetver  server2;
	server2.InitSocket();
	server2.Bind(nullptr, 4568);
	server2.Listen(5);

	while (server1.isRun()|| server2.isRun())
	{
		server1.OnRun();
		server2.OnRun();

	}
	server1.Close();
	server2.Close();
	printf("已退出。\n");
	getchar();
	return 0;
}