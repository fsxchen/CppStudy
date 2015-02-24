TEMPLATE=app
SOURCES=chatServer.cpp  \
        ServerWindow.cpp    \
        chatException.cpp   \
        ServerSocket.cpp    \
        ThAccept.cpp        \
        ThClient.cpp
HEADERS=ServerWindow.h  \
        chatException.h \
        ServerSocket.h  \
        ThAccept.h      \
        ThClient.h
CONFIG=release qt
QT=core gui
TARGET=server
