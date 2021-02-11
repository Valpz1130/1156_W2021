index$1 = 32
total$ = 36
myArray$ = 40
main	PROC						; COMDAT

; 6    : {

$LN6:
  00000	48 83 ec 48	 sub	 rsp, 72			; 00000048H

; 7    : 	int myArray[] = { 1, 2, 3, 4, 5 };

  00004	c7 44 24 28 01
	00 00 00	 mov	 DWORD PTR myArray$[rsp], 1
  0000c	c7 44 24 2c 02
	00 00 00	 mov	 DWORD PTR myArray$[rsp+4], 2
  00014	c7 44 24 30 03
	00 00 00	 mov	 DWORD PTR myArray$[rsp+8], 3
  0001c	c7 44 24 34 04
	00 00 00	 mov	 DWORD PTR myArray$[rsp+12], 4
  00024	c7 44 24 38 05
	00 00 00	 mov	 DWORD PTR myArray$[rsp+16], 5

; 8    : 	int total = 0;

  0002c	c7 44 24 24 00
	00 00 00	 mov	 DWORD PTR total$[rsp], 0

; 9    : 	for ( unsigned int index = 0; index != 5; index++ )

  00034	c7 44 24 20 00
	00 00 00	 mov	 DWORD PTR index$1[rsp], 0
  0003c	eb 0a		 jmp	 SHORT $LN4@main
$LN2@main:
  0003e	8b 44 24 20	 mov	 eax, DWORD PTR index$1[rsp]
  00042	ff c0		 inc	 eax
  00044	89 44 24 20	 mov	 DWORD PTR index$1[rsp], eax
$LN4@main:
  00048	83 7c 24 20 05	 cmp	 DWORD PTR index$1[rsp], 5
  0004d	74 16		 je	 SHORT $LN3@main

; 10   : 	{
; 11   : 		total += myArray[index];

  0004f	8b 44 24 20	 mov	 eax, DWORD PTR index$1[rsp]
  00053	8b 44 84 28	 mov	 eax, DWORD PTR myArray$[rsp+rax*4]
  00057	8b 4c 24 24	 mov	 ecx, DWORD PTR total$[rsp]
  0005b	03 c8		 add	 ecx, eax
  0005d	8b c1		 mov	 eax, ecx
  0005f	89 44 24 24	 mov	 DWORD PTR total$[rsp], eax

; 12   : 	}

  00063	eb d9		 jmp	 SHORT $LN2@main
$LN3@main:

; 13   : 
; 14   : 	std::cout << "Total = " << total << std::endl;

  00065	48 8d 15 00 00
	00 00		 lea	 rdx, OFFSET FLAT:$SG34325
  0006c	48 8b 0d 00 00
	00 00		 mov	 rcx, QWORD PTR __imp_?cout@std@@3V?$basic_ostream@DU?$char_traits@D@std@@@1@A
  00073	e8 00 00 00 00	 call	 ??$?6U?$char_traits@D@std@@@std@@YAAEAV?$basic_ostream@DU?$char_traits@D@std@@@0@AEAV10@PEBD@Z ; std::operator<<<std::char_traits<char> >
  00078	8b 54 24 24	 mov	 edx, DWORD PTR total$[rsp]
  0007c	48 8b c8	 mov	 rcx, rax
  0007f	ff 15 00 00 00
	00		 call	 QWORD PTR __imp_??6?$basic_ostream@DU?$char_traits@D@std@@@std@@QEAAAEAV01@H@Z
  00085	48 8d 15 00 00
	00 00		 lea	 rdx, OFFSET FLAT:??$endl@DU?$char_traits@D@std@@@std@@YAAEAV?$basic_ostream@DU?$char_traits@D@std@@@0@AEAV10@@Z ; std::endl<char,std::char_traits<char> >
  0008c	48 8b c8	 mov	 rcx, rax
  0008f	ff 15 00 00 00
	00		 call	 QWORD PTR __imp_??6?$basic_ostream@DU?$char_traits@D@std@@@std@@QEAAAEAV01@P6AAEAV01@AEAV01@@Z@Z

; 15   : 
; 16   : 	return 0;