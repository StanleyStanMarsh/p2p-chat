#include "Chat.h"

Chat::Chat() : recvBuff(256), sendBuff(256), packet_size(0) {
    sock = socket(AF_INET, SOCK_STREAM, 0);
    ZeroMemory(&info, sizeof(info));
}

Chat::Chat(int adress_family, int type, int protocol) : recvBuff(256), sendBuff(256), packet_size(0) {
    sock = socket(adress_family, type, protocol);
    ZeroMemory(&info, sizeof(info));
}

Chat::~Chat() {
    closesocket(sock);
    WSACleanup();
}

bool Chat::checkSocket(){
    if (sock == INVALID_SOCKET) {
        this->Chat::~Chat();
        return false;
    }
    return true;
}

bool Chat::bindSocket(int adress_family, const char* ip_address, unsigned short port) {
    in_addr ip_to_num;
    int erStat = inet_pton(adress_family, ip_address, &ip_to_num);
    if (erStat <= 0) {
        return false;
    }
    info.sin_family = adress_family;
    info.sin_addr = ip_to_num;
    info.sin_port = htons(port);
    erStat = bind(sock, (sockaddr*)&info, sizeof(info));

    if (erStat != 0) {
        this->Chat::~Chat();
        return false;
    }
    return true;
}

bool Chat::checkConnection() {
    if (packet_size == SOCKET_ERROR) {
        cout << "Can't send message to Client. Error # " << WSAGetLastError() << endl;
        closesocket(sock);
        WSACleanup();
        this->Chat::~Chat();
        return false;
    }
    return true;
}
