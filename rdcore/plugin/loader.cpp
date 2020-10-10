#include "loader.h"
#include "../document/document.h"
#include "../support/utils.h"

Loader::Loader(const std::shared_ptr<MemoryBuffer>& buffer, const std::string& filepath, const RDEntryLoader* entry, Context* ctx): Entry<RDEntryLoader>(entry, ctx), m_buffer(buffer), m_filepath(filepath)
{
    m_document = SafeDocument(new Document(ctx));
}

bool Loader::load()
{
    if(!m_entry->load) return false;
    return m_entry->load(CPTR(RDContext, this->context()), CPTR(RDLoader, this));
}

bool Loader::build()
{
    if(!m_entry->build) return false;
    return m_entry->build(CPTR(RDContext, this->context()), CPTR(RDLoader, this), &m_buildparams);
}

bool Loader::view(rd_address address, RDBufferView* view) const { return this->view(address, RD_NPOS, view); }

bool Loader::view(rd_address address, size_t size, RDBufferView* view) const
{
    RDLocation loc = this->offset(address);
    if(loc.valid) return m_buffer->view(loc.value, size, view);
    return { };
}

bool Loader::view(const RDSegment& segment, RDBufferView* view) const
{
    if(HAS_FLAG(&segment, SegmentFlags_Bss)) return { };
    return m_buffer->view(segment.offset, SegmentContainer::offsetSize(segment), view);
}

Database* Loader::database(const std::string& dbname)
{
    auto it = m_database.find(dbname);
    if(it != m_database.end()) return it->second.get();

    auto* db = Database::open(dbname);
    if(!db) return nullptr;

    auto iit = m_database.emplace(dbname, db);
    return iit.first->second.get();
}

rd_flag Loader::flags() const { return m_entry->flags; }
MemoryBuffer* Loader::buffer() { return m_buffer.get(); }
SafeDocument& Loader::document() { return m_document; }

RDLocation Loader::offset(rd_address address) const
{
    RDSegment segment;
    if(!m_document->segment(address, &segment)|| HAS_FLAG(&segment, SegmentFlags_Bss)) return { {0}, false };

    address -= segment.address;
    address += segment.offset;
    return { {address}, address < segment.endoffset };
}

RDLocation Loader::address(rd_offset offset) const
{
    RDSegment segment;
    if(!m_document->segmentOffset(offset, &segment)) return { {0}, false };

    offset -= segment.offset;
    offset += segment.address;
    return { {offset}, offset < segment.endaddress };
}

RDLocation Loader::addressof(const void* ptr) const
{
    if(!m_buffer->contains(reinterpret_cast<const u8*>(ptr))) return { {0}, false };
    RDLocation loc = this->fileoffset(ptr);
    if(!loc.valid) return { {0}, false };
    return this->address(loc.offset);
}

RDLocation Loader::fileoffset(const void* ptr) const
{
    if(!m_buffer->contains(reinterpret_cast<const u8*>(ptr))) return { {0}, false };
    return { {static_cast<rd_location>(reinterpret_cast<const u8*>(ptr) - m_buffer->data())}, true };
}

u8* Loader::addrpointer(rd_address address) const
{
  RDLocation loc = this->offset(address);
  return loc.valid ? Utils::relpointer(m_buffer->data(), loc.value) : nullptr;
}

u8* Loader::pointer(rd_offset offset) const
{
    if(offset >= m_buffer->size()) return nullptr;
    return Utils::relpointer(m_buffer->data(), offset);
}

const char* Loader::test(const RDEntryLoader* entry, const RDLoaderRequest* req)
{
    if(!entry->test) return nullptr;
    return entry->test(req);
}
