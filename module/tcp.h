#ifndef _LINUX_TCP_H
#define _LINUX_TCP_H

#include <asm/byteorder.h>
#include <linux/skbuff.h>
#include <linux/socket.h>
#include <linux/types.h>
struct tcphdr {
    __be16 source;
    __be16 dest;
    __be32 seq;
    __be32 ack_seq;
#if defined(__LITTLE_ENDIAN_BITFIELD)
    __u16 res1 : 4, doff : 4, fin : 1, syn : 1, rst : 1, psh : 1, ack : 1, urg : 1, ece : 1, cwr : 1;
#elif defined(__BIG_ENDIAN_BITFIELD)
    __u16 doff : 4, res1 : 4, cwr : 1, ece : 1, urg : 1, ack : 1, psh : 1, rst : 1, syn : 1, fin : 1;
#else
#error "Adjust your <asm/byteorder.h> defines"
#endif
    __be16 window;
    __sum16 check;
    __be16 urg_ptr;
};

static inline struct tcphdr *tcp_hdr(const struct sk_buff *skb) {
    return (struct tcphdr *) skb_transport_header(skb);
}

static inline unsigned int tcp_hdrlen(const struct sk_buff *skb) { return tcp_hdr(skb)->doff * 4; }

#endif
