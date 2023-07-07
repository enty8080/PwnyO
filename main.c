#include <stdio.h>
#include <stdlib.h>
#include <main.h>

int main(void)
{
    int sockfd = tlv_connect("127.0.0.1", 8888);

    if (sockfd == -1)
        return 1;

    tlv_pkt_t pkt = read_tlv(sockfd);

    if (pkt.tag == 0)
        printf(" tag: %d\n size: %d\n data: %s\n", pkt.tag, pkt.size, pkt.data);

    free(tlv.data);

    return 0;
}
