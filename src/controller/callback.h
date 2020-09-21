//
// Created by y on 9/17/20.
//

#ifndef SRC_CALLBACK_H
#define SRC_CALLBACK_H

class Parser;
class StructureDna;
class IWriter;
class IReader;

template<typename cInstance>
class Callback{
public:
    typedef void (cInstance::*tMethod)(Parser&, StructureDna&, IWriter&, IReader&);
    Callback(cInstance& cInst, tMethod pMethod): m_cInst(cInst), m_pMethod(pMethod){}
    void operator()(Parser&, StructureDna&, IWriter&, IReader&);

private:
    cInstance m_cInst;
    tMethod m_pMethod;
};

template<typename cInstance>
void Callback<cInstance>::operator()(Parser &parser, StructureDna &structureDna, IWriter &output, IReader &input) {
    (m_cInst.*m_pMethod)(parser, structureDna, output, input);
}


#endif //SRC_CALLBACK_H
