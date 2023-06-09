#include "../base/Chat.h"
#pragma once

class Client: public Chat {
public:
	Client(int adress_family, int type, int protocol);
    /**
     * ������ ����������� � �������
     * @param servInfo
     * @param info_size
     * @return false, ���� ����������� �� �������
     */
	bool connectSocket(sockaddr_in* servInfo, int info_size);

    void receiveData() override;
    void sendData() override;
};
