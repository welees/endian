#include <stdio.h>


#if defined(WIN32)||defined(_WIN32)
typedef char            INT8,*PINT8;
typedef short           INT16,*PINT16;
typedef int             INT32,*PINT32;
typedef __int64         INT64,*PINT64;

typedef unsigned char   UINT8,*PUINT8;
typedef unsigned short  UINT16,*PUINT16;
typedef unsigned int  UINT32,*PUINT32;
typedef unsigned __int64  UINT64,*PUINT64;

#define LLF "I64"
#else

typedef char               INT8,*PINT8;
typedef short              INT16,*PINT16;
typedef int                INT32,*PINT32;
typedef long long          INT64,*PINT64;
typedef unsigned char      UINT8,*PUINT8;
typedef unsigned short     UINT16,*PUINT16;
typedef unsigned int       UINT32,*PUINT32;
typedef unsigned long long UINT64,*PUINT64;

#define LLF "ll"

#endif

#define _CPLUSPLUS
#define _LITTLE_ENDIAN

#include "Endian.h"


int main()
{
	char  sz[256];
	
	INT8     i8=0x12;
	LEINT8   l8=i8;
	BEINT8   b8=i8;
	
	UINT8    u8=0x12;
	LEUINT8  lu8=u8;
	BEUINT8  bu8=u8;
	
	INT16    i16=0x1234;
	LEINT16  l16=i16;
	BEINT16  b16=i16;
	UINT16   u16=0x1234;
	LEUINT16 lu16=u16;
	BEUINT16 bu16=u16;
	
	INT32    i32=0x12345678;
	LEINT32  l32=i32;
	BEINT32  b32=i32;
	UINT32   u32=0x12345678;
	LEUINT32 lu32=u32;
	BEUINT32 bu32=u32;
	
	INT64    i64=(UINT64)0x123456789AbCdEf0;
	LEINT64  l64=i64;
	BEINT64  b64=i64;
	UINT64   u64=(UINT64)0x123456789AbCdEf0;
	LEUINT64 lu64=u64;
	BEUINT64 bu64=u64;
	
	printf("INT8 Raw Data     : %02XH\nLEINT8 Raw Data   : %02XH, LEINT8 Output     : %02XH\nBEINT8 Raw Data   : %02XH, BEINT8 Output     : %02XH\n",i8,*((PINT8)&l8),l8.Get(),*((PINT8)&b8),b8.Get());
	printf("UINT8 Raw Data    : %02XH\nLEUINT8 Raw Data  : %02XH, LEUINT8 Output    : %02XH\nBEUINT8 Raw Data  : %02XH, BEUINT8 Output    : %02XH\n",u8,*((PUINT8)&lu8),lu8.Get(),*((PUINT8)&bu8),(UINT8)bu8);
	
	printf("INT16 Raw Data    : %04XH\nLEINT16 Raw Data  : %04XH, LEINT16 Output    : %04XH\nBEINT16 Raw Data  : %04XH, BEINT16 Output    : %04XH\n",i16,*((PINT16)&l16),l16.Get(),*((PINT16)&b16),(INT16)b16);
	printf("UINT16 Raw Data   : %04XH\nLEUINT16 Raw Data : %04XH, LEUINT16 Output   : %04XH\nBEUINT16 Raw Data : %04XH, BEUINT16 Output   : %04XH\n",u16,*((PUINT16)&lu16),lu16.Get(),*((PUINT16)&bu16),(UINT16)bu16);
	
	printf("INT32 Raw Data    : %08XH\nLEINT32 Raw Data  : %08XH, LEINT32 Output    : %08XH\nBEINT32 Raw Data  : %08XH, BEINT32 Output    : %08XH\n",i32,*((PINT32)&l32),l32.Get(),*((PINT32)&b32),(INT32)b32);
	printf("UINT32 Raw Data   : %08XH\nLEUINT32 Raw Data : %08XH, LEUINT32 Output   : %08XH\nBEUINT32 Raw Data : %08XH, BEUINT32 Output   : %08XH\n",u32,*((PUINT32)&lu32),lu32.Get(),*((PUINT32)&bu32),(UINT32)bu32);
	
	printf("UINT64 Raw Data   : %016" LLF "XH\nLEUINT64 Raw Data : %016" LLF "XH, LEINT64 Output    : %016" LLF "XH\nBEINT64 Raw Data  : %016" LLF "XH, BEINT64 Output    : %016" LLF "XH\n",i64,*((PINT64)&l64),l64.Get(),*((PINT64)&b64),(INT64)b64);
	printf("UINT64 Raw Data   : %016" LLF "XH\nLEUINT64 Raw Data : %016" LLF "XH, LEUINT64 Output   : %016" LLF "XH\nBEUINT64 Raw Data : %016" LLF "XH, BEUINT64 Output   : %016" LLF "XH\n",u64,*((PUINT64)&lu64),lu64.Get(),*((PUINT64)&bu64),(UINT64)bu64);
	
	return 0;
}
