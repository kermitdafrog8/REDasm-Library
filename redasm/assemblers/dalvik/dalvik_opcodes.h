#pragma once

// https://android.googlesource.com/platform/libcore-snapshot/+/ics-mr1/dalvik/src/main/java/dalvik/bytecode/Opcodes.java

#include "../../redasm.h"

namespace REDasm {
namespace DalvikOpcodes {

enum: u16 {
    Nop                  = 0x0000,
    Move                 = 0x0001,
    MoveFrom16           = 0x0002,
    Move_16              = 0x0003,
    MoveWide             = 0x0004,
    MoveWideFrom16       = 0x0005,
    MoveWide_16          = 0x0006,
    MoveObject           = 0x0007,
    MoveObjectFrom16     = 0x0008,
    MoveObject_16        = 0x0009,
    MoveResult           = 0x000a,
    MoveResultWide       = 0x000b,
    MoveResultObject     = 0x000c,
    MoveException        = 0x000d,
    ReturnVoid           = 0x000e,
    Return               = 0x000f,
    ReturnWide           = 0x0010,
    ReturnObject         = 0x0011,
    Const_4              = 0x0012,
    Const_16             = 0x0013,
    Const                = 0x0014,
    ConstHigh16          = 0x0015,
    ConstWide_16         = 0x0016,
    ConstWide_32         = 0x0017,
    ConstWide            = 0x0018,
    ConstWideHigh16      = 0x0019,
    ConstString          = 0x001a,
    ConstStringJumbo     = 0x001b,
    ConstClass           = 0x001c,
    MonitorEnter         = 0x001d,
    MonitorExit          = 0x001e,
    CheckCast            = 0x001f,
    InstanceOf           = 0x0020,
    ArrayLength          = 0x0021,
    NewInstance          = 0x0022,
    NewArray             = 0x0023,
    FilledNewArray       = 0x0024,
    FilledNewArrayRange  = 0x0025,
    FillArrayData        = 0x0026,
    Throw                = 0x0027,
    Goto                 = 0x0028,
    Goto_16              = 0x0029,
    Goto_32              = 0x002a,
    PackedSwitch         = 0x002b,
    SparseSwitch         = 0x002c,
    CmplFloat            = 0x002d,
    CmpgFloat            = 0x002e,
    CmplDouble           = 0x002f,
    CmpgDouble           = 0x0030,
    CmpLong              = 0x0031,
    IfEq                 = 0x0032,
    IfNe                 = 0x0033,
    IfLt                 = 0x0034,
    IfGe                 = 0x0035,
    IfGt                 = 0x0036,
    IfLe                 = 0x0037,
    IfEqz                = 0x0038,
    IfNez                = 0x0039,
    IfLtz                = 0x003a,
    IfGez                = 0x003b,
    IfGtz                = 0x003c,
    IfLez                = 0x003d,
    Aget                 = 0x0044,
    AgetWide             = 0x0045,
    AgetObject           = 0x0046,
    AgetBoolean          = 0x0047,
    AgetByte             = 0x0048,
    AgetChar             = 0x0049,
    AgetShort            = 0x004a,
    Aput                 = 0x004b,
    AputWide             = 0x004c,
    AputObject           = 0x004d,
    AputBoolean          = 0x004e,
    AputByte             = 0x004f,
    AputChar             = 0x0050,
    AputShort            = 0x0051,
    Iget                 = 0x0052,
    IgetWide             = 0x0053,
    IgetObject           = 0x0054,
    IgetBoolean          = 0x0055,
    IgetByte             = 0x0056,
    IgetChar             = 0x0057,
    IgetShort            = 0x0058,
    Iput                 = 0x0059,
    IputWide             = 0x005a,
    IputObject           = 0x005b,
    IputBoolean          = 0x005c,
    IputByte             = 0x005d,
    IputChar             = 0x005e,
    IputShort            = 0x005f,
    Sget                 = 0x0060,
    SgetWide             = 0x0061,
    SgetObject           = 0x0062,
    SgetBoolean          = 0x0063,
    SgetByte             = 0x0064,
    SgetChar             = 0x0065,
    SgetShort            = 0x0066,
    Sput                 = 0x0067,
    SputWide             = 0x0068,
    SputObject           = 0x0069,
    SputBoolean          = 0x006a,
    SputByte             = 0x006b,
    SputChar             = 0x006c,
    SputShort            = 0x006d,
    InvokeVirtual        = 0x006e,
    InvokeSuper          = 0x006f,
    InvokeDirect         = 0x0070,
    InvokeStatic         = 0x0071,
    InvokeInterface      = 0x0072,
    InvokeVirtualRange   = 0x0074,
    InvokeSuperRange     = 0x0075,
    InvokeDirectRange    = 0x0076,
    InvokeStaticRange    = 0x0077,
    InvokeInterfaceRange = 0x0078,
    NegInt               = 0x007b,
    Not                  = 0x007c,
    NegLong              = 0x007d,
    NotLong              = 0x007e,
    NegFloat             = 0x007f,
    NegDouble            = 0x0080,
    IntToLong            = 0x0081,
    IntToFloat           = 0x0082,
    IntToDouble          = 0x0083,
    LongToInt            = 0x0084,
    LongToFloat          = 0x0085,
    LongToDouble         = 0x0086,
    FloatToInt           = 0x0087,
    FloatToLong          = 0x0088,
    FloatToDouble        = 0x0089,
    DoubleToInt          = 0x008a,
    DoubleToLong         = 0x008b,
    DoubleToFloat        = 0x008c,
    IntToByte            = 0x008d,
    IntToChar            = 0x008e,
    IntToShort           = 0x008f,
    AddInt               = 0x0090,
    SubInt               = 0x0091,
    MulInt               = 0x0092,
    DivInt               = 0x0093,
    RemInt               = 0x0094,
    AndInt               = 0x0095,
    OrInt                = 0x0096,
    XorInt               = 0x0097,
    ShlInt               = 0x0098,
    ShrInt               = 0x0099,
    UshrInt              = 0x009a,
    AddLong              = 0x009b,
    SubLong              = 0x009c,
    MulLong              = 0x009d,
    DivLong              = 0x009e,
    RemLong              = 0x009f,
    AndLong              = 0x00a0,
    OrLong               = 0x00a1,
    XorLong              = 0x00a2,
    ShlLong              = 0x00a3,
    ShrLong              = 0x00a4,
    UshrLong             = 0x00a5,
    AddFloat             = 0x00a6,
    SubFloat             = 0x00a7,
    MulFloat             = 0x00a8,
    DivFloat             = 0x00a9,
    RemFloat             = 0x00aa,
    AddDouble            = 0x00ab,
    SubDouble            = 0x00ac,
    MulDouble            = 0x00ad,
    DivDouble            = 0x00ae,
    RemDouble            = 0x00af,
    AddInt_2Addr         = 0x00b0,
    SubInt_2Addr         = 0x00b1,
    MulInt_2Addr         = 0x00b2,
    DivInt_2Addr         = 0x00b3,
    RemInt_2Addr         = 0x00b4,
    AndInt_2Addr         = 0x00b5,
    OrInt_2Addr          = 0x00b6,
    XorInt_2Addr         = 0x00b7,
    ShlInt_2Addr         = 0x00b8,
    ShrInt_2Addr         = 0x00b9,
    UshrInt_2Addr        = 0x00ba,
    AddLong_2Addr        = 0x00bb,
    SubLong_2Addr        = 0x00bc,
    MulLong_2Addr        = 0x00bd,
    DivLong_2Addr        = 0x00be,
    RemLong_2Addr        = 0x00bf,
    AndLong_2Addr        = 0x00c0,
    OrLong_2Addr         = 0x00c1,
    XorLong_2Addr        = 0x00c2,
    ShlLong_2Addr        = 0x00c3,
    ShrLong_2Addr        = 0x00c4,
    UshrLong_2Addr       = 0x00c5,
    AddFloat_2Addr       = 0x00c6,
    SubFloat_2Addr       = 0x00c7,
    MulFloat_2Addr       = 0x00c8,
    DivFloat_2Addr       = 0x00c9,
    RemFloat_2Addr       = 0x00ca,
    AddDouble_2Addr      = 0x00cb,
    SubDouble_2Addr      = 0x00cc,
    MulDouble_2Addr      = 0x00cd,
    DivDouble_2Addr      = 0x00ce,
    RemDouble_2Addr      = 0x00cf,
    AddIntLit16          = 0x00d0,
    SubIntLit16          = 0x00d1,
    MulIntLit16          = 0x00d2,
    DivIntLit16          = 0x00d3,
    RemIntLit16          = 0x00d4,
    AndIntLit16          = 0x00d5,
    OrIntLit16           = 0x00d6,
    XorIntLit16          = 0x00d7,
    AddIntLit8           = 0x00d8,
    SubIntLit8           = 0x00d9,
    MulIntLit8           = 0x00da,
    DivIntLit8           = 0x00db,
    RemIntLit8           = 0x00dc,
    AndIntLit8           = 0x00dd,
    OrIntLit8            = 0x00de,
    XorIntLit8           = 0x00df,
    ShlIntLit8           = 0x00e0,
    ShrIntLit8           = 0x00e1,
    UshrIntLit8          = 0x00e2,
    ConstClassJumbo      = 0x00ff,
    CheckCastJumbo       = 0x01ff,
    InstanceOfJumbo      = 0x02ff,
    NewInstanceJumbo     = 0x03ff,
    NewArrayJumbo        = 0x04ff,
    FilledNewArrayJumbo  = 0x05ff,
    IgetJumbo            = 0x06ff,
    IgetWideJumbo        = 0x07ff,
    IgetObjectJumbo      = 0x08ff,
    IgetBooleanJumbo     = 0x09ff,
    IgetByteJumbo        = 0x0aff,
    IgetCharJumbo        = 0x0bff,
    IgetShortJumbo       = 0x0cff,
    IputJumbo            = 0x0dff,
    IputWideJumbo        = 0x0eff,
    IputObjectJumbo      = 0x0fff,
    IputBooleanJumbo     = 0x10ff,
    IputByteJumbo        = 0x11ff,
    IputCharJumbo        = 0x12ff,
    IputShortJumbo       = 0x13ff,
    SgetJumbo            = 0x14ff,
    SgetWideJumbo        = 0x15ff,
    SgetObjectJumbo      = 0x16ff,
    SgetBooleanJumbo     = 0x17ff,
    SgetByteJumbo        = 0x18ff,
    SgetCharJumbo        = 0x19ff,
    SgetShortJumbo       = 0x1aff,
    SputJumbo            = 0x1bff,
    SputWideJumbo        = 0x1cff,
    SputObjectJumbo      = 0x1dff,
    SputBooleanJumbo     = 0x1eff,
    SputByteJumbo        = 0x1fff,
    SputCharJumbo        = 0x20ff,
    SputShortJumbo       = 0x21ff,
    InvokeVirtualJumbo   = 0x22ff,
    InvokeSuperJumbo     = 0x23ff,
    InvokeDirectJumbo    = 0x24ff,
    InvokeStaticJumbo    = 0x25ff,
    InvokeInterfaceJumbo = 0x26ff,
};

} // namespace DalvikOpcodes
} // namespace REDasm
