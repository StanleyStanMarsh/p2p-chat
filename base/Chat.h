#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <stdio.h>
#include <vector>
#pragma once
using namespace std;

class Chat {
protected:
    /// ���������� ������, �������������� �������� ����� ������������� ������ �����
    /// ����� �������� � ��������.
    SOCKET sock;

    /// ���������, ���������� ����� ��������-��������� (IP) � ����� �����
    sockaddr_in info;

    /// ������ �������, ������� ����� ���������� � ��������.
    short packet_size;

    /// ��� �������, recvBuff � sendBuff, ������� ������������ ��� ��������
    /// ���������� � ������������ ������ ��������������.
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
     * �������, ������� ���������, �������� �� ���������� ������ ����������.
     */
    bool checkSocket();
    /**
     * �������, ������� ����������� ����� � ������������� IP-������ � ������ �����.
     * @param adress_family
     * @param ip_address
     * @param port
     * @return false, ���� ��������� �� �������
     */
    bool bindSocket(int adress_family, const char* ip_address, unsigned short port);

    /// ����� ����������� �������, ������� �������� ������ �� ������.
    virtual void receiveData()=0;
    /// ����� ����������� �������, ������� ���������� ������ ����� �����.
    virtual void sendData()=0;
    /**
     * �������, ������� ���������, ��������� �� ����� � ���������� �����.
     * @return false, ���� ����������� ���������
     */
    bool checkConnection();
};

