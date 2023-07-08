#include <main.h>

#include <unistd.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int tlv_connect(char *host, int port)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1)
        return -1;

    struct sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    hint.sin_addr.s_addr = inet_addr(host);

    if (connect(sockfd, (struct sockaddr *)&hint, sizeof(hint)) != 0)
        return -1;

    return sockfd;
}

void send_tlv(int sockfd, tlv_pkt_t tlv_packet)
{
    char tlv_tag[2];
    PACK_SHORT(tlv_packet.tag, tlv_tag);

    send(sockfd, tlv_tag, 2, 0);

    char tlv_size[4];
    PACK_INT(tlv_packet.size, tlv_size);

    send(sockfd, tlv_size, 4, 0);

    if (tlv_packet.size > 0)
        send(sockfd, tlv_packet.data, tlv_packet.size, 0);
}

tlv_pkt_t read_tlv(int sockfd)
{
    tlv_pkt_t tlv;

    char tag_buf[2];
    recv(sockfd, tag_buf, 2, 0);

    char size_buf[4];
    recv(sockfd, size_buf, 4, 0);

    int tag = UNPACK_SHORT(tag_buf);
    int size = UNPACK_INT(size_buf);

    tlv.tag = tag;
    tlv.size = size;

    tlv.data = malloc(size + 1);

    if (tlv.data != NULL)
    {
        recv(sockfd, tlv.data, size, 0);

        tlv.data[size] = '\0';
    }

    return tlv;
}
