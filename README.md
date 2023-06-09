P2P chat
========
## Проект (*децентрализованного?*) чата под операционную систему Windows.
Основой проекта послужила [статья на Хабре](https://habr.com/ru/articles/582370/) от ***Mr_Dezz***. В ней подробно описаны основы сетевого программирования под Windows.
____
В проекте используется Windows Socket API ([Winsock](https://ru.wikipedia.org/wiki/Winsock)). Для написания, как и в статье, используется язык C++ и [Win32API](https://learn.microsoft.com/en-us/windows/win32/api/), в частности библиотеки:
 ```c++
    #include <WinSock2.h>
    #include <WS2tcpip.h>

    #pragma comment(lib, "Ws2_32.lib")
 ```
____
 Базовый класс `Chat` - обертка для основных функций сокета. `Client` и `Server` - дочерние классы, описывающие поведение клиента и сервера соотвественно.

### Notes:
> v 1.0
> Используется логика, представленная в статье от ***Mr_Dezz***. Для большей наглядности, ниже приведена схема:
> ![Scheme_socket_TCP](https://player.slidesplayer.com/65/11723337/slides/slide_4.jpg "Socket TCP")
