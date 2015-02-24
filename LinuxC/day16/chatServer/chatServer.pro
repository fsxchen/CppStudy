TEMPLATE=app
SOURCES=chatServer.cpp  \
        ServerWindow.cpp    \
        chatException.cpp   \
        ServerSocket.cpp
HEADERS=ServerWindow.h  \
        chatException.h \
        ServerSocket.h
CONFIG=release qt
QT=core gui
TARGET=server
