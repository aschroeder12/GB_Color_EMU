#include"GB_Registers.h"
#include"GB_Buses.c"
#include"GB_Registers.c"
void RunCPU(void)
{
	unsigned short tmp;
	unsigned short tmp2;
	tmp = ReadMemory(PC_REGISTER);
	switch(tmp)
	{
	case 0x04:
		printf("INC B \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x05:
		printf("DEC B \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x06:
		printf("LD B n \n");
		PC_REGISTER = PC_REGISTER + 2;
		break;
	case 0x0d:
		printf("DEC C \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x0c:
		printf("INC C \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x0e:
		printf("LD C \n");
		PC_REGISTER = PC_REGISTER + 2;
		break;
	case 0x11:
		printf("LD DE nn \n");
		PC_REGISTER = PC_REGISTER + 3;
		break;
	case 0x13:
		printf("INC DE \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x15:
		printf("DEC D \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x16:
		printf("LD D n \n");
		PC_REGISTER = PC_REGISTER + 2;
		break;
	case 0x17:
		printf("RLA \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x18:
		printf("JR e \n");
		PC_REGISTER = PC_REGISTER + 2;
		break;
	case 0x1a:
		printf("LD A DE \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x1d:
		printf("DEC E \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x1e:
		printf("LD E n \n");
		PC_REGISTER = PC_REGISTER + 2;
		break;
	case 0x20:
		printf("JR NZ \n");
		PC_REGISTER = PC_REGISTER + 2;
		break;
	case 0x21:
		printf("LD HL n \n");
		PC_REGISTER = PC_REGISTER + 3;
		break;
	case 0x22:
		printf("LD HL+ A \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x23:
		printf("INC HL \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x24:
		printf("INC H \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x28:
		printf("JR Z e \n");
		PC_REGISTER = PC_REGISTER + 2;
		break;
	case 0x2e:
		printf("LD L n \n");
		PC_REGISTER = PC_REGISTER + 2;
		break;
	case 0x31:
		printf("LD SP \n");
		// 3 Bytes
		PC_REGISTER = PC_REGISTER + 3;
		break;
	case 0x32:
		printf("LD HL - \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x3d:
		printf("DEC A \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x3e:
		printf("LD A \n"); //0011
		PC_REGISTER = PC_REGISTER + 2;
		break;
	case 0x4f:
		printf("LD C A \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x57:
		printf("LD D A \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x67:
		printf("LD H A \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x77:
		printf("LD HL A \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x78:
		printf("LD A B \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x7b:
		printf("LD A E \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x7c:
		printf("LD A H \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x7d:
		printf("LD A L \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x86:
		printf("ADD HL \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x90:
		printf("SUB B \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0xaf:
		printf("XOR A \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0xbe:
		printf("CP HL \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0xc1:
		printf("POP BC \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0xc5:
		printf("PUSH BC \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0xc9:
		printf("RET \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0xcb:
		printf("CB PREFIXED - ");
		PC_REGISTER = PC_REGISTER + 1;
		tmp2 = ReadMemory(PC_REGISTER);
		switch(tmp2)
		{
		case 0x11:
			printf("RL C \n");
			PC_REGISTER = PC_REGISTER + 1;
			break;
		case 0x7c:
			printf("BIT 7 H \n");
			PC_REGISTER = PC_REGISTER + 1;
			break;
		default:
			break;
		}
		break;
	case 0xcd:
		printf("CALL n \n");
		PC_REGISTER = PC_REGISTER + 3;
		break;
	case 0xe0:
		printf("LDH n A \n");
		PC_REGISTER = PC_REGISTER + 2;
		break;
	case 0xe2:
		printf("LDH C A \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0xea:
		printf("LD n A \n");
		PC_REGISTER = PC_REGISTER + 3;
		break;
	case 0xf0:
		printf("LDH A n \n");
		PC_REGISTER = PC_REGISTER + 2;
		break;
	case 0xfe:
		printf("CP n \n");
		PC_REGISTER = PC_REGISTER + 2;
		break;
	default:
		break;
	}
}