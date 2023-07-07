#ifndef _MAIN_H_
#define _MAIN_H_

#define UNPACK_SHORT(b) b[0] | b[1] << 8
#define UNPACK_INT(b) b[0] | b[1] << 8 | b[2] << 16 | b[3] << 24

typedef struct tlv_pkt {
    int tag;
    int size;
    char *data;
} tlv_pkt_t;

int tlv_connect(char *, int);
tlv_pkt_t read_tlv(int);

#endif