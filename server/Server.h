#include "../base/Chat.h"
#pragma once

class Server: public Chat {
    SOCKET other_sock;
public:
	Server(int adress_family, int type, int protocol);
    /**
     * ������� ������������ ��� ������������� �������� �����������
     * @param max_connects
     * @return false, ���� ���������� ����������
     */
	bool listenData(int max_connects);
    /**
     * ������� ������������ ��� ������ �������� ����������� � ��������� ���������� � �������.
     * @param clientInfo
     * @param info_size
     * @return false, ���� ������ ��� �������� �����������
     */
	bool acceptData(sockaddr_in* clientInfo, int* info_size);

    /**
     * ������� ������������ ��� ������ � �������� ������ �� ���� ��������������.
     */
    void receiveData() override;
    void sendData() override;
};
