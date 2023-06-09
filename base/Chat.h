#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <stdio.h>
#include <vector>
#pragma once
using namespace std;

class Chat {
protected:
    /// Дескриптор сокета, представляющий конечную точку двустороннего канала связи
    /// между клиентом и сервером.
    SOCKET sock;

    /// Структура, содержащая адрес интернет-протокола (IP) и номер порта
    sockaddr_in info;

    /// Размер пакетов, которые будут отправлены и получены.
    short packet_size;

    /// Два вектора, recvBuff и sendBuff, которые используются для хранения
    /// полученных и отправленных данных соответственно.
    vector<char> recvBuff;
    vector<char> sendBuff;

public:
    Chat();
    Chat(int adress_family, int type, int protocol);
    ~Chat();

    /**
     * getInfo()
     * @return sockaddr_in
     */
    sockaddr_in getInfo() const;

    /**
     * Функция, которая проверяет, является ли дескриптор сокета допустимым.
     */
    bool checkSocket();
    /**
     * Функция, которая привязывает сокет к определенному IP-адресу и номеру порта.
     * @param adress_family
     * @param ip_address
     * @param port
     * @return false, если привязать не удалось
     */
    bool bindSocket(int adress_family, const char* ip_address, unsigned short port);

    /// Чисто виртуальная функция, которая получает данные из сокета.
    virtual void receiveData()=0;
    /// Чисто виртуальная функция, которая отправляет данные через сокет.
    virtual void sendData()=0;
    /**
     * Функция, которая проверяет, подключен ли сокет к удаленному хосту.
     * @return false, если подключение разорвано
     */
    bool checkConnection();
};

