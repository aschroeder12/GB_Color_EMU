#include"GB_Registers.h"
#include"GB_Buses.c"
#include"GB_Registers.c"

FILE* LOGFILE;

void PrintStatus();
void PrintLog(char *);
void Print4HexLog(unsigned short);
void Print2HexLog(unsigned char);

void SetLogFile(void)
{
	LOGFILE = fopen("LOGS/TestLog.txt","a");
}
void CloseLogFile(void)
{
	fclose(LOGFILE);
}

void RunCPU(unsigned short *beginDotCnt, unsigned short endDotCnt)
{
	unsigned short tmp;
	unsigned short tmp2;
	tmp = ReadMemory(PC_REGISTER);
	PrintLog("Current INSTR (see line below for name) = ");
	Print4HexLog(tmp);
	/* TEMP FOR TESTING, NEED TO FIX */
	*beginDotCnt = *beginDotCnt + 1;

	switch(tmp)
	{
	case 0x04:
		PrintLog("INC B \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_INC_R(&B_REGISTER);
		break;
	case 0x05:
		PrintLog("DEC B \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_DEC_R(&B_REGISTER);
		break;
	case 0x06:
		PrintLog("LD B n \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_R_N(&B_REGISTER);
		break;
	case 0x0d:
		PrintLog("DEC C \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_DEC_R(&C_REGISTER);
		break;
	case 0x0c:
		PrintLog("INC C \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_INC_R(&C_REGISTER);
		break;
	case 0x0e:
		PrintLog("LD C n \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_R_N(&C_REGISTER);
		break;
	case 0x11:
		PrintLog("LD DE nn Debug this \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_RR_NN(&D_REGISTER, &E_REGISTER);
		break;
	case 0x13:
		PrintLog("INC DE debug this\n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_INC_RR(&D_REGISTER, &E_REGISTER);
		break;
	case 0x15:
		PrintLog("DEC D \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_DEC_R(&D_REGISTER);
		break;
	case 0x16:
		PrintLog("LD D n \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_R_N(&D_REGISTER);
		break;
	case 0x17:
		PrintLog("RLA \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_RLA(&A_REGISTER);
		break;
	case 0x18:
		PrintLog("JR e \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_JUMPR();
		break;
	case 0x1a:
		PrintLog("LD A DE \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_A_DE();
		break;
	case 0x1d:
		PrintLog("DEC E \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_DEC_R(&E_REGISTER);
		break;
	case 0x1e:
		PrintLog("LD E n \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_R_N(&E_REGISTER);
		break;
	case 0x20:
		PrintLog("JR NZ \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_JUMPR_NZ();
		break;
	case 0x21:
		PrintLog("LD HL nn \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_RR_NN(&H_REGISTER, &L_REGISTER);
		break;
	case 0x22:
		PrintLog("LD HL+ A \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_HLI_A();
		break;
	case 0x23:
		PrintLog("INC HL \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_INC_RR(&H_REGISTER, &L_REGISTER);
		break;
	case 0x24:
		PrintLog("INC H \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_INC_R(&H_REGISTER);
		break;
	case 0x28:
		PrintLog("JR Z e \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_JUMPR_Z();
		break;
	case 0x2e:
		PrintLog("LD L n \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_R_N(&L_REGISTER);
		break;
	case 0x31:
		PrintLog("LD SP \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_SP_NN();
		break;
	case 0x32:
		PrintLog("LD HL - A \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_HLD_A();
		break;
	case 0x3d:
		PrintLog("DEC A \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_DEC_R(&A_REGISTER);
		break;
	case 0x3e:
		PrintLog("LD A n \n"); //0011
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_R_N(&A_REGISTER);
		break;
	case 0x4f:
		PrintLog("LD C A \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_R_r(&C_REGISTER, &A_REGISTER);
		break;
	case 0x57:
		PrintLog("LD D A \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_R_r(&D_REGISTER, &A_REGISTER);
		break;
	case 0x67:
		PrintLog("LD H A \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_R_r(&H_REGISTER, &A_REGISTER);
		break;
	case 0x77:
		PrintLog("LD HL A \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_HL_R(&A_REGISTER);
		break;
	case 0x78:
		PrintLog("LD A B \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_R_r(&A_REGISTER, &B_REGISTER);
		break;
	case 0x7b:
		PrintLog("LD A E \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_R_r(&A_REGISTER, &E_REGISTER);
		break;
	case 0x7c:
		PrintLog("LD A H \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_R_r(&A_REGISTER, &H_REGISTER);
		break;
	case 0x7d:
		PrintLog("LD A L \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_R_r(&A_REGISTER, &L_REGISTER);
		break;
	case 0x86:
		PrintLog("ADD HL \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_ADD_REGISTER_HL();
		break;
	case 0x90:
		PrintLog("SUB B \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_SUB_REGISTER_R(&B_REGISTER);
		break;
	case 0xaf:
		PrintLog("XOR A \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_XOR_REGISTER_R(&A_REGISTER);
		break;
	case 0xbe:
		PrintLog("CP HL \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_CP_REGISTER_HL();
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
		INSTR_RETURN();
		break;
	case 0xcb:
		PrintLog("CB PREFIXED - ");
		PC_REGISTER = PC_REGISTER + 1;
		tmp2 = ReadMemory(PC_REGISTER);
		switch(tmp2)
		{
		case 0x11:
			PrintLog("RL C \n");
			PC_REGISTER = PC_REGISTER + 1;
			INSTR_RL_REGISTER_R(&C_REGISTER);
			break;
		case 0x7c:
			PrintLog("BIT 7 H \n");
			PC_REGISTER = PC_REGISTER + 1;
			INSTR_BIT_REGISTER_R((unsigned char)7, &H_REGISTER);
			break;
		default:
			break;
		}
		break;
	case 0xcd:
		PrintLog("CALL n \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_CALL();
		break;
	case 0xe0:
		PrintLog("LDH n A \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_HW_N_A();
		break;
	case 0xe2:
		PrintLog("LDH C A \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_HW_C_A();
		break;
	case 0xea:
		PrintLog("LDH nn A \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_HW_NN_A();
		break;
	case 0xf0:
		PrintLog("LDH A n \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_HW_A_N();
		break;
	case 0xfe:
		PrintLog("CP n \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_CP_N();
		break;
	default:
		PrintLog("Undefined instruction \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	}
	PrintStatus();
}

void PrintLog(char * logStr)
{
	//FILE *fptr = fopen("LOGS/TestLog.txt","a");
	if (LOGFILE == NULL)
	{
		printf("Could not open file \n");
	}
	else
	{
		fprintf(LOGFILE, logStr);
	}
	//fclose(fptr);
}

void Print4HexLog(unsigned short val)
{
	//FILE *fptr = fopen("LOGS/TestLog.txt","a");
	if (LOGFILE == NULL)
	{
		printf("Could not open file \n");
	}
	else
	{
		fprintf(LOGFILE, "%04x \n", val);
	}
	//fclose(fptr);
}
void Print2HexLog(unsigned char val)
{
	//FILE *fptr = fopen("LOGS/TestLog.txt","a");
	if (LOGFILE == NULL)
	{
		printf("Could not open file \n");
	}
	else
	{
		fprintf(LOGFILE, "%02x \n", val);
	}
	//fclose(fptr);
}