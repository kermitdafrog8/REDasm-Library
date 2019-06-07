#pragma once

#include <redasm/disassembler/types/symboltable.h>
#include <redasm/pimpl.h>

namespace REDasm {

typedef std::unique_ptr<Symbol> SymbolPtr;

class SymbolTableImpl
{
    PIMPL_DECLARE_PUBLIC(SymbolTable)

    public:
        typedef std::unordered_map<address_t, SymbolPtr> SymbolsByAddress;
        typedef std::unordered_map<std::string, address_t> SymbolsByName;

    public:
        SymbolTableImpl() = default;
        static std::string prefix(SymbolType type);

    private:
        SymbolsByAddress m_byaddress;
        SymbolsByName m_byname;

    friend struct Serializer<SymbolTable>;
};

} // namespace REDasm