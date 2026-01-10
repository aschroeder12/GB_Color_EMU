#include"GB_Registers.h"
#include"GB_Buses.c"
#include"GB_Registers.c"

void PrintLog(char *);
void PrintHexLog(unsigned char);

void RunCPU(void)
{
	unsigned short tmp;
	unsigned short tmp2;
	tmp = ReadMemory(PC_REGISTER);
	PrintHexLog(tmp);
	switch(tmp)
	{
	case 0x04:
		PrintLog("INC B \n");
		INSTR_INC_R(&B_REGISTER);
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x05:
		PrintLog("DEC B \n");
		INSTR_DEC_R(&B_REGISTER);
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x06:
		PrintLog("LD B n \n");
		INSTR_LOAD_REGISTER_R_N(&B_REGISTER);
		PC_REGISTER = PC_REGISTER + 2;
		break;
	case 0x0d:
		PrintLog("DEC C \n");
		INSTR_DEC_R(&C_REGISTER);
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x0c:
		PrintLog("INC C \n");
		INSTR_INC_R(&C_REGISTER);
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x0e:
		PrintLog("LD C n \n");
		INSTR_LOAD_REGISTER_R_N(&C_REGISTER);
		PC_REGISTER = PC_REGISTER + 2;
		break;
	case 0x11:
		PrintLog("LD DE nn Debug this \n");
		INSTR_LOAD_REGISTER_RR_NN(&D_REGISTER, &E_REGISTER);
		PC_REGISTER = PC_REGISTER + 3;
		break;
	case 0x13:
		PrintLog("INC DE debug this\n");
		INSTR_INC_RR(&D_REGISTER, &E_REGISTER);
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x15:
		PrintLog("DEC D \n");
		INSTR_DEC_R(&D_REGISTER);
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x16:
		PrintLog("LD D n \n");
		INSTR_LOAD_REGISTER_R_N(&D_REGISTER);
		PC_REGISTER = PC_REGISTER + 2;
		break;
	case 0x17:
		PrintLog("RLA \n");
		INSTR_RLA(&A_REGISTER);
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x18:
		PrintLog("JR e \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_JUMPR(void);
		break;
	case 0x1a:
		PrintLog("LD A DE \n");
		INSTR_LOAD_REGISTER_A_DE(void);
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x1d:
		PrintLog("DEC E \n");
		INSTR_DEC_R(&E_REGISTER);
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x1e:
		PrintLog("LD E n \n");
		INSTR_LOAD_REGISTER_R_N(&E_REGISTER);
		PC_REGISTER = PC_REGISTER + 2;
		break;
	case 0x20:
		PrintLog("JR NZ \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_JUMPR_NZ(void);
		break;
	case 0x21:
		PrintLog("LD HL n \n");
		INSTR_LOAD_REGISTER_RR_NN(&H_REGISTER, &L_REGISTER);
		PC_REGISTER = PC_REGISTER + 3;
		break;
	case 0x22:
		PrintLog("LD HL+ A \n");
		INSTR_LOAD_REGISTER_HLI_A(void);
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x23:
		PrintLog("INC HL \n");
		INSTR_INC_RR(&H_REGISTER, &L_REGISTER);
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x24:
		PrintLog("INC H \n");
		INSTR_INC_R(&H_REGISTER);
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x28:
		PrintLog("JR Z e \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_JUMPR_Z(void);
		break;
	case 0x2e:
		PrintLog("LD L n \n");
		INSTR_LOAD_REGISTER_R_N(&L_REGISTER);
		PC_REGISTER = PC_REGISTER + 2;
		break;
	case 0x31:
		PrintLog("LD SP \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_SP_NN(void);
		break;
	case 0x32:
		PrintLog("LD HL - \n");
		INSTR_LOAD_REGISTER_HLD_A(void);
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x3d:
		PrintLog("DEC A \n");
		INSTR_DEC_R(&A_REGISTER);
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x3e:
		PrintLog("LD A n \n"); //0011
		INSTR_LOAD_REGISTER_R_N(&A_REGISTER);
		PC_REGISTER = PC_REGISTER + 2;
		break;
	case 0x4f:
		PrintLog("LD C A \n");
		INSTR_LOAD_REGISTER_R_r(&C_REGISTER, &A_REGISTER);
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x57:
		PrintLog("LD D A \n");
		INSTR_LOAD_REGISTER_R_r(&D_REGISTER, &A_REGISTER);
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x67:
		PrintLog("LD H A \n");
		INSTR_LOAD_REGISTER_R_r(&H_REGISTER, &A_REGISTER);
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x77:
		PrintLog("LD HL A \n");
		INSTR_LOAD_REGISTER_HL_R(&A_REGISTER);
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x78:
		PrintLog("LD A B \n");
		INSTR_LOAD_REGISTER_R_r(&A_REGISTER, &B_REGISTER);
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x7b:
		PrintLog("LD A E \n");
		INSTR_LOAD_REGISTER_R_r(&A_REGISTER, &E_REGISTER);
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x7c:
		PrintLog("LD A H \n");
		INSTR_LOAD_REGISTER_R_r(&A_REGISTER, &H_REGISTER);
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x7d:
		PrintLog("LD A L \n");
		INSTR_LOAD_REGISTER_R_r(&A_REGISTER, &L_REGISTER);
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x86:
		PrintLog("ADD HL \n");
		INSTR_ADD_REGISTER_HL(void);
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0x90:
		PrintLog("SUB B \n");
		INSTR_SUB_REGISTER_R(&B_REGISTER);
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0xaf:
		PrintLog("XOR A \n");
		INSTR_XOR_REGISTER_R(&A_REGISTER);
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0xbe:
		PrintLog("CP HL \n");
		INSTR_CP_REGISTER_HL(void);
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0xc1:
		PrintLog("POP BC \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_POP_RR(&B_REGISTER, &C_REGISTER);
		break;
	case 0xc5:
		PrintLog("PUSH BC \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_PUSH_RR(&B_REGISTER, &C_REGISTER);
		break;
	case 0xc9:
		PrintLog("RET \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_RETURN(void);
		break;
	case 0xcb:
		PrintLog("CB PREFIXED - ");
		PC_REGISTER = PC_REGISTER + 1;
		tmp2 = ReadMemory(PC_REGISTER);
		switch(tmp2)
		{
		case 0x11:
			PrintLog("RL C \n");
			INSTR_RL_REGISTER_R(&C_REGISTER);
			PC_REGISTER = PC_REGISTER + 1;
			break;
		case 0x7c:
			PrintLog("BIT 7 H \n");
			INSTR_BIT_REGISTER_R((unsigned char)7, &H_REGISTER);
			PC_REGISTER = PC_REGISTER + 1;
			break;
		default:
			break;
		}
		break;
	case 0xcd:
		PrintLog("CALL n \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_CALL(void);
		break;
	case 0xe0:
		PrintLog("LDH n A \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_HW_N_A(void);
		break;
	case 0xe2:
		PrintLog("LDH C A \n");
		INSTR_LOAD_HW_C_A(void);
		PC_REGISTER = PC_REGISTER + 1;
		break;
	case 0xea:
		PrintLog("LDH nn A \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_HW_NN_A(void);
		break;
	case 0xf0:
		PrintLog("LDH A n \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_HW_A_N(void);
		break;
	case 0xfe:
		PrintLog("CP n \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_CP_N(void);
		break;
	default:
		PrintLog("Undefined instruction \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	}
}

void PrintLog(char * logStr)
{
	FILE *fptr = fopen("LOGS/TestLog.txt","a");
	if (fptr == NULL)
	{
		printf("Could not open file \n");
	}
	else
	{
		fprintf(fptr, logStr);
	}
	fclose(fptr);
}

void PrintHexLog(unsigned char val)
{
	FILE *fptr = fopen("LOGS/TestLog.txt","a");
	if (fptr == NULL)
	{
		printf("Could not open file \n");
	}
	else
	{
		fprintf(fptr, "%02x \n", val);
	}
	fclose(fptr);
}