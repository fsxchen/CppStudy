###5.poll模式

```c
int poll(
    struct pollfd *fds, //要监控的描述符号
    int nfd,            //监控的描述符号个数
    int timeout,        //阻塞超时
    );

struct pollfd {
    int   fd;         /* file descriptor */
    short events;     /* requested events */
    short revents;    /* returned events */
};

```
##二.socket选项
###1.socket有哪些选项可以设置
ARP-IP-UDP/TCP

* **通用选项(SOL_SOCKET):**
    * SO_BROADCAST 广播
    * SO_DONTROUTE 不使用路由
    * SO_KEEPALIVE  保持链接
    * SO_OOBINLINE  带外数据
    * SO_RCVBUF    接受的缓冲
    * SO_SNDBUF     描述符号发送的大小
    * SO_REUSEADDR  地址可以反复绑定
    * SO_TYPE       描述符号的类型SOCK_STREAM/SOCK_DGRAM

* **ICMP选项:**IPPROTO_ICMP
    * ICMP_FILTER(只有这一个)

* **IP选项(干预系统生成IP的头):**加上IPPROTO_IP
    * ......
    * ......

* **UDP选项:**IPPROTO_UDP

* **TCP选项:**IPPROTO_TCP

setsockopt设置选项
getsockopt获取选项

###案例一
* 判定一个socket的数据类型SOCK_STREAM/SOCK_DGRAM/SOCK_RAW
###案例二
* 使用选项进行广播数据,只能是UDP
* cast_A:发送方
    * 建立socket
    * 设置广播
    * 发送数据(广播方式发送)
* cast_B:接受方
    * 建立socket
    * 绑定一个地址(为了演示,地址设置可重用)
    * 接受数据据


##三.OOB数据(TCP)
优先数据

send(, MSG_OOB)

recv(, MSG_OOB)
###案例:
* oob_server.c
    * recv MSG_OOB
* oob_client.c
    * send MSG_OOB

* 1.OOB数据只能只能一个字符
* 2.普通数据使用一般方式接收与发送,OOB数据使用MSG_OOB发送
* 3.一个字符串里面使用MSS_OOB,则最后一个数据是OOB数据,则其他数据是非OOB数据
* 4.问题:OOB数据是优先数据.优先体现在什么地方?
* 02:16
##四.
