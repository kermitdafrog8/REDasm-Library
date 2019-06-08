#pragma once

#include "../../support/safe_ptr.h"
#include "../../support/event.h"
#include "../types/symboltable.h"
#include "listingfunctions.h"
#include "listingcursor.h"
#include "listingitem.h"

namespace REDasm {

class ListingDocumentChangedImpl;
class ListingDocumentTypeImpl;

enum class ListingDocumentAction { Changed = 0, Inserted, Removed };

class LIBREDASM_API ListingDocumentChanged
{
    PIMPL_DECLARE_PRIVATE(ListingDocumentChanged)

    public:
        ListingDocumentChanged(const ListingItem* item, size_t index, ListingDocumentAction action = ListingDocumentAction::Changed);
        const ListingItem* item() const;
        ListingDocumentAction action() const;
        bool isInserted() const;
        bool isRemoved() const;
        size_t index() const;
};

class LIBREDASM_API ListingDocumentType
{
    PIMPL_DECLARE_PRIVATE(ListingDocumentType)

    public:
        Event<const ListingDocumentChanged*> changed;

    public:
        ListingDocumentType();
        ~ListingDocumentType() = default;
        size_t size() const;
        bool advance(InstructionPtr& instruction);
        bool goTo(const ListingItem* item);
        bool goTo(address_t address);
        void moveToEP();

    public: // ListingItemData functions
        std::string comment(const ListingItem *item, bool skipauto = false) const;
        void comment(const ListingItem* item, const std::string& s);
        void autoComment(address_t address, const std::string& s);

    public: // ListingItem getter functions
        std::string type(const ListingItem *item) const;
        void type(address_t address, const std::string& s);
        const ListingMetaItem &meta(const ListingItem *item) const;

    public: // ListingItem inserter functions
        void empty(address_t address);
        void meta(address_t address, const std::string& s, const std::string& name = std::string());
        void entry(address_t address, tag_t tag = 0);
        void function(address_t address, const std::string& name, tag_t tag = 0);
        void function(address_t address, tag_t tag = 0);
        void pointer(address_t address, SymbolType type, tag_t tag = 0);
        void table(address_t address, u64 count, tag_t tag = 0);
        void tableItem(address_t address, address_t startaddress, u64 idx, tag_t tag = 0);
        void branch(address_t address, s64 direction, tag_t tag = 0);
        void symbol(address_t address, const std::string& name, SymbolType type, tag_t tag = 0);
        void symbol(address_t address, SymbolType type, tag_t tag = 0);
        void lock(address_t address, const std::string& name);
        void lock(address_t address, SymbolType type, tag_t tag = 0);
        void lock(address_t address, const std::string& name, SymbolType type, tag_t tag = 0);
        void segment(const std::string& name, offset_t offset, address_t address, u64 size, SegmentType type);
        void segment(const std::string& name, offset_t offset, address_t address, u64 psize, u64 vsize, SegmentType type);

    public:
        size_t segmentsCount() const;
        size_t lastLine() const;
        size_t itemIndex(const ListingItem* item) const;
        size_t functionIndex(address_t address) const;
        size_t instructionIndex(address_t address) const;
        size_t symbolIndex(address_t address) const;
        const ListingFunctions *functions() const;
        const ListingCursor* cursor() const;
        const Segment *segmentByName(const std::string& name) const;
        const Segment *segment(address_t address) const;
        const Symbol *documentEntry() const;
        const SegmentList& segments() const;
        const SymbolTable* symbols() const;
        const ListingItem* functionStart(const ListingItem* item) const;
        const ListingItem* functionStart(address_t address) const;
        const ListingItem* currentFunction() const;
        const ListingItem* currentItem() const;
        Segment* segment(address_t address);
        Symbol *functionStartSymbol(address_t address);
        Symbol *symbol(address_t address) const;
        Symbol *symbol(const std::string& name) const;
        ListingCursor* cursor();
        ListingItem* itemAt(size_t i) const;
        ListingFunctions* functions();
        InstructionPtr instruction(address_t address);
        InstructionPtr entryInstruction();
        void rename(address_t address, const std::string& name);
        void lockFunction(address_t address, const std::string& name, u32 tag = 0);
        void eraseSymbol(address_t address);
        void setDocumentEntry(address_t address);
        void instruction(const InstructionPtr& instruction);
        void update(const InstructionPtr& instruction);

    friend class Serializer< safe_ptr<ListingDocumentType> >;
    friend class ListingDocumentIteratorImpl;
};

typedef safe_ptr<ListingDocumentType> ListingDocument;
using document_s_lock = s_locked_safe_ptr<ListingDocument>;
using document_x_lock = x_locked_safe_ptr<ListingDocument>;

template<> struct Serializer<ListingDocument> {
    static void write(std::fstream& fs, const ListingDocument& d);
    static void read(std::fstream& fs, ListingDocument& d, const std::function<InstructionPtr(address_t address)> cb);
};

} // namespace REDasm
