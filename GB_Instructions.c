/******************GB INSTRUCTION SET *****************
 *  LD r, r' 				- LOAD REGISTER (REGISTER)
 *  LD r, n 				- LOAD REGISTER (IMMEDIATE)
 */


/** LD r, r' - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register r, data from the 8-bit register r'
 */

void LOAD_REGISTER_R(unsigned char* R_DEST, unsigned char* R_PRIME)
{
	*R_DEST = *R_PRIME;
}

/** LD r, n - LOAD REGISTER (IMMEDIATE)
 * 