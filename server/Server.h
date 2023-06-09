#include "../base/Chat.h"
#pragma once

class Server: public Chat {
    SOCKET other_sock;
public:
	Server(int adress_family, int type, int protocol);
    /**
     * Функция используется для прослушивания входящих подключений
     * @param max_connects
     * @return false, если невозможно прослушать
     */
	bool listenData(int max_connects);
    /**
     * Функция используется для приема входящих подключений и получения информации о клиенте.
     * @param clientInfo
     * @param info_size
     * @return false, если ошибка при принятии подключения
     */
	bool acceptData(sockaddr_in* clientInfo, int* info_size);

    /**
     * Функции используются для приема и отправки данных по сети соответственно.
     */
    void receiveData() override;
    void sendData() override;
};
