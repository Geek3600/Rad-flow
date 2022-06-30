#pragma once

#define RADSIM_ROOT_DIR "/media/andrew/DATA/research/rad-flow/rad-sim"

// NoC-related Parameters
#define NOC_LINKS_PAYLOAD_WIDTH 166
#define NOC_LINKS_VCID_WIDTH 3
#define NOC_LINKS_PACKETID_WIDTH 32
#define NOC_LINKS_TYPEID_WIDTH 3
#define PACKET_TYPE_0 Flit::READ_REQUEST
#define PACKET_TYPE_1 Flit::WRITE_REQUEST
#define PACKET_TYPE_2 Flit::WRITE_DATA
#define PACKET_TYPE_3 Flit::READ_REPLY
#define PACKET_TYPE_4 Flit::WRITE_REPLY
#define NOC_LINKS_DEST_WIDTH 8
#define NOC_LINKS_DEST_INTERFACE_WIDTH 5

// AXI-Streaming Parameters
#define AXIS_MAX_DATAW 640
#define AXIS_STRBW 8
#define AXIS_KEEPW 8
#define AXIS_USERW 32

// Deduced Parameters
#define NOC_LINKS_WIDTH (NOC_LINKS_PAYLOAD_WIDTH + NOC_LINKS_VCID_WIDTH + NOC_LINKS_PACKETID_WIDTH + NOC_LINKS_DEST_WIDTH + NOC_LINKS_DEST_INTERFACE_WIDTH)
#define AXIS_IDW NOC_LINKS_DEST_INTERFACE_WIDTH
#define AXIS_DESTW NOC_LINKS_DEST_WIDTH
#define AXIS_TRANSACTION_WIDTH (AXIS_MAX_DATAW + AXIS_STRBW + AXIS_KEEPW + AXIS_IDW + AXIS_DESTW + AXIS_USERW + 1)
#define AXIS_TRANSACTION_PAYLOAD_WIDTH (AXIS_IDW + AXIS_MAX_DATAW + AXIS_USERW + 1)
#define AXIS_TID(t) t.range(AXIS_IDW - 1, 0)
#define AXIS_TLAST(t) t.range(AXIS_IDW, AXIS_IDW)
#define AXIS_TUSER(t) t.range(AXIS_USERW + AXIS_IDW, AXIS_IDW + 1)
#define AXIS_TDATA(t) t.range(AXIS_MAX_DATAW + AXIS_USERW + AXIS_IDW, AXIS_USERW + AXIS_IDW + 1)
#define AXIS_TDEST(t) t.range(AXIS_DESTW + AXIS_MAX_DATAW + AXIS_USERW + AXIS_IDW, AXIS_MAX_DATAW + AXIS_USERW + AXIS_IDW + 1)
#define AXIS_PAYLOAD(t) t.range(AXIS_IDW + AXIS_MAX_DATAW + AXIS_USERW, 0)