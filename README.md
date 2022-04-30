# endian
Endian is a cross-platform, general-purpose c++ little endian/big endian solution that eliminates the need for users to explicitly specify the conversion mode each time they access different endian data.  Once you declare a variable using a type in Endian, you don't need to specify any explicit conversion for it, just use it as if it were a standard type supported by the CPU.

The example:

	INT32    i32=0x12345678;
	LEINT32  l32=i32;
	BEINT32  b32=i32;
	UINT32   u32=0x12345678;
	LEUINT32 lu32=u32;
	BEUINT32 bu32=u32;
	
	printf("INT32 Raw Data    : %08XH\nLEINT32 Raw Data  : %08XH, LEINT32 Output    : %08XH\nBEINT32 Raw Data  : %08XH, BEINT32 Output    : %08XH\n",i32,*((PINT32)&l32),l32.Get(),*((PINT32)&b32),(INT32)b32);
	printf("UINT32 Raw Data   : %08XH\nLEUINT32 Raw Data : %08XH, LEUINT32 Output   : %08XH\nBEUINT32 Raw Data : %08XH, BEUINT32 Output   : %08XH\n",u32,*((PUINT32)&lu32),lu32.Get(),*((PUINT32)&bu32),(UINT32)bu32);
	
  Here we can get the result:
  
  INT32 Raw Data    : 12345678H
  
  LEINT32 Raw Data  : 12345678H, LEINT32 Output    : 12345678H
  
  BEINT32 Raw Data  : 78563412H, BEINT32 Output    : 12345678H
  
  UINT32 Raw Data   : 12345678H
  
  LEUINT32 Raw Data : 12345678H, LEUINT32 Output   : 12345678H
  
  BEUINT32 Raw Data : 78563412H, BEUINT32 Output   : 12345678H
