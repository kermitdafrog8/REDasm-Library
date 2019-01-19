#ifndef DALVIK_H
#define DALVIK_H

// http://pallergabor.uw.hu/androidblog/dalvik_opcodes.html
#include "../../plugins/plugins.h"
#include "../../support/dispatcher.h"

#define DEX_DECLARE_DECODE(opcode) static bool decode##opcode(BufferRef& buffer, const InstructionPtr& instruction)

#define DEX_DECLARE_DECODES(op) DEX_DECLARE_DECODE(op##0); DEX_DECLARE_DECODE(op##1); DEX_DECLARE_DECODE(op##2); DEX_DECLARE_DECODE(op##3); \
                                DEX_DECLARE_DECODE(op##4); DEX_DECLARE_DECODE(op##5); DEX_DECLARE_DECODE(op##6); DEX_DECLARE_DECODE(op##7); \
                                DEX_DECLARE_DECODE(op##8); DEX_DECLARE_DECODE(op##9); DEX_DECLARE_DECODE(op##A); DEX_DECLARE_DECODE(op##B); \
                                DEX_DECLARE_DECODE(op##C); DEX_DECLARE_DECODE(op##D); DEX_DECLARE_DECODE(op##E); DEX_DECLARE_DECODE(op##F)

namespace REDasm {

class DalvikAssembler : public AssemblerPlugin
{
    public:
        DalvikAssembler();
        virtual std::string name() const;
        virtual Printer* createPrinter(DisassemblerAPI *disassembler) const;
        virtual AssemblerAlgorithm* createAlgorithm(DisassemblerAPI* disassembler);

    protected:
        virtual bool decodeInstruction(const BufferRef &buffer, const InstructionPtr &instruction);

    private:
        static bool decodeOp0(BufferRef& buffer, const InstructionPtr& instruction, const std::string& mnemonic, instruction_id_t id, u32 type = InstructionTypes::None);
        static bool decodeOp1(BufferRef& buffer, const InstructionPtr& instruction, const std::string& mnemonic, instruction_id_t id, u32 type = InstructionTypes::None);
        static bool decodeOp2(BufferRef& buffer, const InstructionPtr& instruction, const std::string& mnemonic, instruction_id_t id);
        static bool decodeOp3(BufferRef& buffer, const InstructionPtr& instruction, const std::string& mnemonic, instruction_id_t id, u32 type = InstructionTypes::None);
        static bool decodeOp2_s(BufferRef& buffer, const InstructionPtr& instruction, const std::string& mnemonic, instruction_id_t id);
        static bool decodeOp2_t(BufferRef& buffer, const InstructionPtr& instruction, const std::string& mnemonic, instruction_id_t id);
        static bool decodeOp2_f(BufferRef& buffer, const InstructionPtr& instruction, const std::string& mnemonic, instruction_id_t id, u32 type = InstructionTypes::None);
        static bool decodeOp2_16(BufferRef& buffer, const InstructionPtr& instruction, const std::string& mnemonic, instruction_id_t id);
        static bool decodeOp2_imm4(BufferRef& buffer, const InstructionPtr& instruction, const std::string& mnemonic, instruction_id_t id);
        static bool decodeOp2_imm16(BufferRef& buffer, const InstructionPtr& instruction, const std::string& mnemonic, instruction_id_t id);
        static bool decodeOp2_imm32(BufferRef& buffer, const InstructionPtr& instruction, const std::string& mnemonic, instruction_id_t id);
        static bool decodeOp3_f(BufferRef& buffer, const InstructionPtr& instruction, const std::string& mnemonic, instruction_id_t id, u32 type = InstructionTypes::None);
        static bool decodeOp3_t(BufferRef& buffer, const InstructionPtr& instruction, const std::string& mnemonic, instruction_id_t id, u32 type = InstructionTypes::None);
        static bool decodeOp3_imm8(BufferRef& buffer, const InstructionPtr& instruction, const std::string& mnemonic, instruction_id_t id);
        static bool decodeOp3_imm16(BufferRef& buffer, const InstructionPtr& instruction, const std::string& mnemonic, instruction_id_t id);
        static bool decodeIfOp2(BufferRef& buffer, const InstructionPtr& instruction, const std::string& cond, instruction_id_t id);
        static bool decodeIfOp3(BufferRef& buffer, const InstructionPtr& instruction, const std::string& cond, instruction_id_t id);
        static bool decodeInvoke(BufferRef& buffer, const InstructionPtr& instruction, const std::string& kind, instruction_id_t id);

    private:
        DEX_DECLARE_DECODES(0);
        DEX_DECLARE_DECODES(1);
        DEX_DECLARE_DECODES(2);
        DEX_DECLARE_DECODES(3);
        DEX_DECLARE_DECODES(4);
        DEX_DECLARE_DECODES(5);
        DEX_DECLARE_DECODES(6);
        DEX_DECLARE_DECODES(7);
        DEX_DECLARE_DECODES(8);
        DEX_DECLARE_DECODES(9);
        DEX_DECLARE_DECODES(A);
        DEX_DECLARE_DECODES(B);
        DEX_DECLARE_DECODES(C);
        DEX_DECLARE_DECODES(D);
        DEX_DECLARE_DECODES(E);
        DEX_DECLARE_DECODES(F);

    private:
        static ValuedDispatcher<instruction_id_t, bool, BufferRef&, const InstructionPtr&> m_opcodedispatcher;

};

DECLARE_ASSEMBLER_PLUGIN(DalvikAssembler, dalvik)

} // namespace REDasm

#endif // DALVIK_H
