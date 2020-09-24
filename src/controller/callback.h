//
// Created by y on 9/17/20.
//

#ifndef SRC_CALLBACK_H
#define SRC_CALLBACK_H

#include "io_callback.h"

class Parser;
class StructureDna;
class IWriter;
class IReader;
class UI;

template<typename cInstance>
class Callback{
public:
    typedef void (cInstance::*tMethod)(Parser&, StructureDna&, const IOCallback<UI>&);
    Callback(cInstance& cInst, tMethod pMethod): m_cInst(cInst), m_pMethod(pMethod){}
    void operator()(Parser&, StructureDna&, const IOCallback<UI>&);

private:
    cInstance& m_cInst;
    tMethod m_pMethod;
};

template<typename cInstance>
void Callback<cInstance>::operator()(Parser &parser, StructureDna &structureDna, const IOCallback<UI>& ioCallback) {
    (m_cInst.*m_pMethod)(parser, structureDna, ioCallback);
}


#endif //SRC_CALLBACK_H
