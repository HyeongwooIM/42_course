#include <cstdlib>
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <vector>
#include <map>
#include <fcntl.h>
#include <errno.h>
#include "Client.hpp"
#include "Channel.hpp"
#include "Server.hpp"

Server server;

void signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		std::map<int, Client> client = server.getClients();
		for (std::map<int, Client>::iterator it = client.begin(); it != client.end(); it++)
			close(it->first);
		close(server.getSocket());
		exit(0);
	}
}

int main(int ac, char** av){
	signal(SIGINT, signal_handler);
	if (ac != 3) {
		std::cout << "Error : Arguments error" << std::endl;
		return (1);
	}
	int tmp_port_num = atoi(av[1]);
	if (tmp_port_num < 1024 || tmp_port_num > 65535){
		std::cout << "Numeric port number " << std::endl;
		return (1);
	}
	if (strlen(av[2]) < 4){
		std::cout << "Error : Arguments error" << std::endl;
		return (1);
	}
	server.serverInit(tmp_port_num, av[2]);
	server.sockCreat();
	std::cout << "port : " << tmp_port_num << "\n" << "password : " << av[2] <<std::endl;
	if (listen(server.getSocket(), 50) == -1) {
		std::cout << "Socket listen failed" << std::endl;
		return (1);
	}
	fcntl(server.getSocket(), F_SETFL, O_NONBLOCK);
	server.addServerSocket();
	
	server.runServer();
	return 0;
}
	
	// int	serverSocket, clientSocket;
	// struct sockaddr_in	serverAddr, clientAddr;
	// socklen_t clientAddrSize; //unsigned int

	// //socket 을 AF_INET(IPv4), SOCK_STREAM(TCP) 로 뚫겠다!~
	// if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
	// 	std::cout << "Error : Socket error" << std::endl;
	// 	return (1);
	// }

	// serverAddr.sin_family = AF_INET; //AF_INET(IPv4)
	// serverAddr.sin_addr.s_addr = htonl(INADDR_ANY); //IPv4주소 저장.
	// serverAddr.sin_port = htons(atoi(av[1]));
	
	// if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
	// 	std::cout << "Error : Bind error" << std::endl;
	// 	return (1);
	// }
	
	// if (listen(serverSocket, 50) == -1) {
	// 	std::cout << "Error : Listen error" << std::endl;
	// 	return (1);
	// }

	// std::cout << "Server listening on part" << av[1] << "..." << std::endl;

	// std::vector<Client *> clients;
	// fd_set	readfds;

	// while (1){
	// 	FD_ZERO(&readfds);
	// 	FD_SET(serverSocket, &readfds);
	// 	int maxSocket = serverSocket;

	// 	for (const auto& clientSock : clients) {
	// 		FD_SET(clientSocket, &readfds);
	// 		maxSocket = std::max(maxSocket, clientSock);
	// 	}
	// }


// 	return 0;
// }
