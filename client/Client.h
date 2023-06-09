#include "../base/Chat.h"
#pragma once

class Client: public Chat {
public:
	Client(int adress_family, int type, int protocol);
    /**
     * Способ подключения к серверу
     * @param servInfo
     * @param info_size
     * @return false, если подключение не удалось
     */
	bool connectSocket(sockaddr_in* servInfo, int info_size);

    void receiveData() override;
    void sendData() override;
};
