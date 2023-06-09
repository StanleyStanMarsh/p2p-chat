#include "Server.h"

Server::Server(int adress_family, int type, int protocol) : Chat(adress_family, type, protocol) {}

bool Server::listenData(int max_connects) {
	int erStat = listen(sock, max_connects);
	if (erStat != 0) {
		this->~Server();
		return false;
	}
	return true;
}

bool Server::acceptData(sockaddr_in* clientInfo, int* info_size){
	other_sock = accept(sock, (sockaddr*)clientInfo, info_size);

	if (other_sock == INVALID_SOCKET) {
		this->~Server();
		return false;
	}
	return true;
}

void Server::receiveData() {
    packet_size = recv(other_sock, recvBuff.data(), recvBuff.size(), 0);

    cout << "Client's message: " << recvBuff.data() << endl;
}

void Server::sendData() {
    cin.getline(sendBuff.data(), sendBuff.size());

    packet_size = send(other_sock, sendBuff.data(), sendBuff.size(), 0);
}