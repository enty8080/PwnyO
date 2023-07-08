#ifndef _MAIN_H_
#define _MAIN_H_

#define UNPACK_SHORT(b) b[0] | b[1] << 8
#define UNPACK_INT(b) b[0] | b[1] << 8 | b[2] << 16 | b[3] << 24

#define PACK_SHORT(val, val_pkt) val_pkt[1] = (val >> 8) & 0xff; \
        val_pkt[0] = val & 0xff
#define PACK_INT(val, val_pkt) val_pkt[3] = (val >> 24) & 0xff; \
        val_pkt[2] = (val >> 16) & 0xff; \
        val_pkt[1] = (val >> 8) & 0xff; \
        val_pkt[0] = val & 0xff

typedef struct tlv_pkt {
    int tag;
    int size;
    char *data;
} tlv_pkt_t;

int tlv_connect(char *, int);
tlv_pkt_t read_tlv(int);
void send_tlv(int, tlv_pkt_t);

#endif