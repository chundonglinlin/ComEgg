#ifndef _C_OPT_SAVE_FILE_H_
#define _C_OPT_SAVE_FILE_H_

#include "COperator.h"

class COptSaveFile : public COperator {
public:
    COptSaveFile(const CVariable *filePath,
            const CVariable *fileName,
            const CVariable *fileContent,
            const CVariable *result)
            : COperator(OT_SAVE_FILE) {
        _filePath = filePath->clone();
        _fileName = fileName->clone();
        _fileContent = fileContent->clone();
        _result = result->clone();
    }

    virtual ~COptSaveFile() {
        _DEL(_filePath);
        _DEL(_fileName);
        _DEL(_fileContent);
        _DEL(_result);
    }

    COptSaveFile(const COptSaveFile &opt) : COperator(opt) {
        _filePath = opt._filePath->clone();
        _fileName = opt._fileName->clone();
        _fileContent = opt._fileContent->clone();
        _result = opt._result->clone();
    }

    const COptSaveFile &operator=(const COptSaveFile &opt) {
        if (this != &opt) {
            COperator::operator=(opt);

            _DEL(_filePath);
            _DEL(_fileName);
            _DEL(_fileContent);
            _DEL(_result);
            _filePath = opt._filePath->clone();
            _fileName = opt._fileName->clone();
            _fileContent = opt._fileContent->clone();
            _result = opt._result->clone();
        }

        return *this;
    }

    virtual COperator *clone() const {
        return (COperator *) new COptSaveFile(*this);;
    }

    virtual none_ init(const optUnit *unit) {
        COperator::init(unit);

        _filePath->init(unit->data);
        _fileName->init(unit->data);
        _fileContent->init(unit->data);
        _result->init(unit->data);
    }

    virtual none_ work(const TMessageUnit *tmu);

private:
    CVariable *_filePath;
    CVariable *_fileName;
    CVariable *_fileContent;
    CVariable *_result;
};

#endif // _C_OPT_SAVE_FILE_H_

