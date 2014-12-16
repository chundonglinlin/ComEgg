#ifndef _SIGNALS_H_
#define _SIGNALS_H_

const ub_2 REQ_MARK = 0x1000;

// Network <-> Parser
const ub_2 PARSER_RDS_REQ = 0x0001;
const ub_2 PARSER_RDS_RES = REQ_MARK | PARSER_RDS_RES;

struct TSignalHeader {
    ub_2 size;
    ub_2 cmd;
};

struct TSignalExtra {
    ub_4 extraLow;
    ub_4 extraHigh;
};

struct TSignalParserRdsReq {
    TSignalHeader header;
};

struct TSignalParserRdsRes {
    TSignalHeader header;
};

#endif // _SIGNALS_H_