#include "Client.h"

Client::Client(int adress_family, int type, int protocol) : Chat(adress_family, type, protocol) {}

bool Client::connectSocket(sockaddr_in* servInfo, int info_size) {
	int erStat = connect(sock, (sockaddr*)servInfo, sizeof(*servInfo));
	if (erStat != 0) {
		this->~Client();
		return false;
	}
    const char welcome[] = "Hi there!";
    send(sock, welcome, sizeof(welcome), 0);
	return true;
}

void Client::receiveData() {
    packet_size = recv(sock, recvBuff.data(), recvBuff.size(), 0);

    cout << "Client's message: " << recvBuff.data() << endl;
}

void Client::sendData() {
    cin.getline(sendBuff.data(), sendBuff.size());

    packet_size = send(sock, sendBuff.data(), sendBuff.size(), 0);
}