#ifndef _C_PDU_INFO_H_
#define _C_PDU_INFO_H_

#include "ProtocolCommon.h"

class CPduInfo : public CBase {
public:
    CPDUInfo(const CField *field) {
        start(field);
    }

    virtual ~CPDUInfo() {
    }

    // If GroupName is not null, Field is sub-field, GroupName is the name
    // of group.
    b_4 addField(const TField &field,
            const ch_1 *groupName = null_v);

    // Get field
    CField *getField(const ch_1 *name);

    // Get PDU structure
    CField *getStruct() {
        return _field;
    }

protected:
    b_4 start(const CField *headField);

    none_ stop();

private:
    mapField _fieldMap;

    CField *_field;
    CField *_curField;
};

#endif // _C_PDU_INFO_H_