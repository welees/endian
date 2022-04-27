/*
  Version 1.0  2021-09-20
  Endian.h implement common endian data accessing.
  To use it, user should define all INT8,INT16,INT32,INT64,UINT8,UINT16,UINT32,UINT64 types before use this header
  and define _LITTLE_ENDIAN or _BIG_ENDIAN

  Example:
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

*/

#ifndef _WELEES_ENDIAN_IMPLEMENT_
#define _WELEES_ENDIAN_IMPLEMENT_

#pragma pack(push)
#pragma pack(1)


#if defined(WIN32) || defined(_WIN32)
#define __attribute__(x)
#endif

/*
#if defined(_WIN32)||defined(WIN32)
typedef char               INT8,*PINT8;
typedef short              INT16,*PINT16;
typedef int                INT32,*PINT32;
typedef __int64            INT64,*PINT64;
typedef unsigned char      UINT8,*PUINT8;
typedef unsigned short     UINT16,*PUINT16;
typedef unsigned int       UINT32,*PUINT32;
typedef unsigned __int64   UINT64,*PUINT64;

#else

typedef char               INT8,*PINT8;
typedef short              INT16,*PINT16;
typedef int                INT32,*PINT32;
typedef long long          INT64,*PINT64;
typedef unsigned char      UINT8,*PUINT8;
typedef unsigned short     UINT16,*PUINT16;
typedef unsigned int       UINT32,*PUINT32;
typedef unsigned long long UINT64,*PUINT64;
#endif

*/

// User need to define all INT8,INT16,INT32,INT64,UINT8,UINT16,UINT32,UINT64 types before include this header


typedef struct ___bothendian8
{
public:
	___bothendian8(INT8 Source)
	{
		operator=(Source);
	}
	___bothendian8(void)
	{
	}
	void operator=(INT8 Source)
	{
		m_Data=Source;
	}
	
	operator INT8(void)
	{
		return Get();
	}
	
	INT8 Get(void)
	{
		return m_Data;
	}
private:
	INT8 m_Data;
}__attribute__((__packed__)) ___bothendian8;


typedef struct ___bothendianu8
{
public:
	___bothendianu8(UINT8 Source)
	{
		operator=(Source);
	}
	___bothendianu8(void)
	{
	}
	void operator=(UINT8 Source)
	{
		m_Data=Source;
	}
	
	operator UINT8(void)
	{
		return Get();
	}
	
	UINT8 Get(void)
	{
		return m_Data;
	}
private:
	UINT8 m_Data;
}__attribute__((__packed__)) ___bothendianu8;


#define __THIS_ENDIAN_DEFINE(__type) \
typedef struct ___thisendian##__type \
{ \
public: \
	___thisendian##__type(__type Source) \
	{ \
		m_Data=Source; \
	} \
	___thisendian##__type(void) \
	{ \
	} \
	void operator=(__type Source) \
	{ \
		m_Data=Source; \
	} \
	operator __type(void) \
	{ \
		return Get(); \
	} \
	\
	__type Get(void) \
	{ \
		return m_Data; \
	} \
private: \
	__type m_Data; \
}__attribute__((__packed__)) __thisendian##__type;


__THIS_ENDIAN_DEFINE(INT16)
__THIS_ENDIAN_DEFINE(INT32)
__THIS_ENDIAN_DEFINE(INT64)
__THIS_ENDIAN_DEFINE(UINT16)
__THIS_ENDIAN_DEFINE(UINT32)
__THIS_ENDIAN_DEFINE(UINT64)


typedef struct ___thatendianINT16
{
public:
	___thatendianINT16(INT16 Source)
	{
		operator=(Source);
	}
	___thatendianINT16(void)
	{
	}
	void operator=(INT16 Source)
	{
		*((PUINT8)&m_Data)=*(((PUINT8)&Source)+1);
		*(((PUINT8)&m_Data)+1)=*((PUINT8)&Source);
	}
	
	operator INT16(void)
	{
		return Get();
	}
	
	INT16 Get(void)
	{
		INT16 r;
		*(((PUINT8)&r)+1)=*((PUINT8)&m_Data);
		*((PUINT8)&r)=*(((PUINT8)&m_Data)+1);
		return r;
	}
private:
	INT16 m_Data;
}__attribute__((__packed__)) __thatendianINT16;


typedef struct ___thatendianINT32
{
public:
	___thatendianINT32(INT32 Source)
	{
		operator=(Source);
	}
	___thatendianINT32(void)
	{
	}
	void operator=(INT32 Source)
	{
		*((PUINT8)&m_Data)=*(((PUINT8)&Source)+3);
		*(((PUINT8)&m_Data)+1)=*(((PUINT8)&Source)+2);
		*(((PUINT8)&m_Data)+2)=*(((PUINT8)&Source)+1);
		*(((PUINT8)&m_Data)+3)=*((PUINT8)&Source);
	}
	
	operator INT32(void)
	{
		return Get();
	}
	
	INT32 Get(void)
	{
		INT32 r;
		*(((PUINT8)&r)+3)=*((PUINT8)&m_Data);
		*(((PUINT8)&r)+2)=*(((PUINT8)&m_Data)+1);
		*(((PUINT8)&r)+1)=*(((PUINT8)&m_Data)+2);
		*((PUINT8)&r)=*(((PUINT8)&m_Data)+3);
		return r;
	}
private:
	INT32 m_Data;
}__attribute__((__packed__)) __thatendianINT32;


typedef struct ___thatendianINT64
{
public:
	___thatendianINT64(INT64 Source)
	{
		operator=(Source);
	}
	___thatendianINT64(void)
	{
	}
	void operator=(INT64 Source)
	{
		*((PUINT8)&m_Data)=*(((PUINT8)&Source)+7);
		*(((PUINT8)&m_Data)+1)=*(((PUINT8)&Source)+6);
		*(((PUINT8)&m_Data)+2)=*(((PUINT8)&Source)+5);
		*(((PUINT8)&m_Data)+3)=*(((PUINT8)&Source)+4);
		*(((PUINT8)&m_Data)+4)=*(((PUINT8)&Source)+3);
		*(((PUINT8)&m_Data)+5)=*(((PUINT8)&Source)+2);
		*(((PUINT8)&m_Data)+6)=*(((PUINT8)&Source)+1);
		*(((PUINT8)&m_Data)+7)=*((PUINT8)&Source);
	}
	
	operator INT64(void)
	{
		return Get();
	}
	
	INT64 Get(void)
	{
		INT64 r;
		*(((PUINT8)&r)+7)=*((PUINT8)&m_Data);
		*(((PUINT8)&r)+6)=*(((PUINT8)&m_Data)+1);
		*(((PUINT8)&r)+5)=*(((PUINT8)&m_Data)+2);
		*(((PUINT8)&r)+4)=*(((PUINT8)&m_Data)+3);
		*(((PUINT8)&r)+3)=*(((PUINT8)&m_Data)+4);
		*(((PUINT8)&r)+2)=*(((PUINT8)&m_Data)+5);
		*(((PUINT8)&r)+1)=*(((PUINT8)&m_Data)+6);
		*((PUINT8)&r)=*(((PUINT8)&m_Data)+7);
		return r;
	}
private:
	INT64 m_Data;
}__attribute__((__packed__)) __thatendianINT64;


typedef struct ___thatendianUINT16
{
public:
	___thatendianUINT16(UINT16 Source)
	{
		operator=(Source);
	}
	___thatendianUINT16(void)
	{
	}
	void operator=(UINT16 Source)
	{
		*((PUINT8)&m_Data)=*(((PUINT8)&Source)+1);
		*(((PUINT8)&m_Data)+1)=*((PUINT8)&Source);
	}
	
	operator UINT16(void)
	{
		return Get();
	}
	
	UINT16 Get(void)
	{
		UINT16 r;
		*(((PUINT8)&r)+1)=*((PUINT8)&m_Data);
		*((PUINT8)&r)=*(((PUINT8)&m_Data)+1);
		return r;
	}
private:
	UINT16 m_Data;
}__attribute__((__packed__)) __thatendianUINT16;


typedef struct ___thatendianUINT32
{
public:
	___thatendianUINT32(UINT32 Source)
	{
		operator=(Source);
	}
	___thatendianUINT32(void)
	{
	}
	void operator=(UINT32 Source)
	{
		*((PUINT8)&m_Data)=*(((PUINT8)&Source)+3);
		*(((PUINT8)&m_Data)+1)=*(((PUINT8)&Source)+2);
		*(((PUINT8)&m_Data)+2)=*(((PUINT8)&Source)+1);
		*(((PUINT8)&m_Data)+3)=*((PUINT8)&Source);
	}
	
	operator UINT32(void)
	{
		return Get();
	}
	
	UINT32 Get(void)
	{
		UINT32 r;
		*(((PUINT8)&r)+3)=*((PUINT8)&m_Data);
		*(((PUINT8)&r)+2)=*(((PUINT8)&m_Data)+1);
		*(((PUINT8)&r)+1)=*(((PUINT8)&m_Data)+2);
		*((PUINT8)&r)=*(((PUINT8)&m_Data)+3);
		return r;
	}
private:
	UINT32 m_Data;
}__attribute__((__packed__)) __thatendianUINT32;


typedef struct ___thatendianUINT64
{
public:
	___thatendianUINT64(UINT64 Source)
	{
		operator=(Source);
	}
	___thatendianUINT64(void)
	{
	}
	void operator=(UINT64 Source)
	{
		*((PUINT8)&m_Data)=*(((PUINT8)&Source)+7);
		*(((PUINT8)&m_Data)+1)=*(((PUINT8)&Source)+6);
		*(((PUINT8)&m_Data)+2)=*(((PUINT8)&Source)+5);
		*(((PUINT8)&m_Data)+3)=*(((PUINT8)&Source)+4);
		*(((PUINT8)&m_Data)+4)=*(((PUINT8)&Source)+3);
		*(((PUINT8)&m_Data)+5)=*(((PUINT8)&Source)+2);
		*(((PUINT8)&m_Data)+6)=*(((PUINT8)&Source)+1);
		*(((PUINT8)&m_Data)+7)=*((PUINT8)&Source);
	}
	
	operator UINT64(void)
	{
		return Get();
	}
	
	UINT64 Get(void)
	{
		UINT64 r;
		*(((PUINT8)&r)+7)=*((PUINT8)&m_Data);
		*(((PUINT8)&r)+6)=*(((PUINT8)&m_Data)+1);
		*(((PUINT8)&r)+5)=*(((PUINT8)&m_Data)+2);
		*(((PUINT8)&r)+4)=*(((PUINT8)&m_Data)+3);
		*(((PUINT8)&r)+3)=*(((PUINT8)&m_Data)+4);
		*(((PUINT8)&r)+2)=*(((PUINT8)&m_Data)+5);
		*(((PUINT8)&r)+1)=*(((PUINT8)&m_Data)+6);
		*((PUINT8)&r)=*(((PUINT8)&m_Data)+7);
		return r;
	}
private:
	UINT64 m_Data;
}__attribute__((__packed__)) __thatendianUINT64;


#if defined(_LITTLE_ENDIAN)
typedef ___bothendian8     LEINT8,*PLEINT8;
typedef __thisendianINT16  LEINT16,*PLEINT16;
typedef __thisendianINT32  LEINT32,*PLEINT32;
typedef __thisendianINT64  LEINT64,*PLEINT64;

typedef ___bothendianu8    LEUINT8,*PLEUINT8;
typedef __thisendianUINT16 LEUINT16,*PLEUINT16;
typedef __thisendianUINT32 LEUINT32,*PLEUINT32;
typedef __thisendianUINT64 LEUINT64,*PLEUINT64;


typedef ___bothendian8     BEINT8,*PBEINT8;
typedef __thatendianINT16  BEINT16,*PBEINT16;
typedef __thatendianINT32  BEINT32,*PBEINT32;
typedef __thatendianINT64  BEINT64,*PBEINT64;

typedef ___bothendianu8    BEUINT8,*PBEUINT8;
typedef __thatendianUINT16 BEUINT16,*PBEUINT16;
typedef __thatendianUINT32 BEUINT32,*PBEUINT32;
typedef __thatendianUINT64 BEUINT64,*PBEUINT64;
#endif

#if defined(_BIG_ENDIAN)
typedef ___bothendian8     LEINT8,*PLEINT8;
typedef __thatendianINT16  LEINT16,*PLEINT16;
typedef __thatendianINT32  LEINT32,*PLEINT32;
typedef __thatendianINT64  LEINT64,*PLEINT64;

typedef ___bothendianu8    LEUINT8,*PLEUINT8;
typedef __thatendianUINT16 LEUINT16,*PLEUINT16;
typedef __thatendianUINT32 LEUINT32,*PLEUINT32;
typedef __thatendianUINT64 LEUINT64,*PLEUINT64;


typedef ___bothendian8     BEINT8,*PBEINT8;
typedef __thisendianINT16  BEINT16,*PBEINT16;
typedef __thisendianINT32  BEINT32,*PBEINT32;
typedef __thisendianINT64  BEINT64,*PBEINT64;

typedef ___bothendianu8    BEUINT8,*PBEUINT8;
typedef __thisendianUINT16 BEUINT16,*PBEUINT16;
typedef __thisendianUINT32 BEUINT32,*PBEUINT32;
typedef __thisendianUINT64 BEUINT64,*PBEUINT64;
#endif


#if (!defined(_LITTLE_ENDIAN)) && (!defined(_BIG_ENDIAN))
#error You should define _LITTLE_ENDIAN or _BIG_ENDIAN to enable match endian type
#endif


#pragma pack(pop)

#endif //_WELEES_ENDIAN_IMPLEMENT_
