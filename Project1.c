// ============================================================================
// File: dumpmem.c (Fall 2016)
// ============================================================================
// This program is a quick exercise dealing with void pointers and dynamic
// memory management. The main routine allocates blocks from the heap and has
// their contents written to stdout via the DumpMem function, which writes out
// data in a canonical hexadecimal dump.
// ============================================================================

#include    <stdio.h>
#include    <ctype.h>
#include    <stdlib.h>
#include    <time.h>


// function prototypes
void    DumpMem(void  *baseAddress, long  numBytes);
void    FillMem(void  *baseAddress, long  numBytes);


// type definitions
typedef unsigned char   Byte;



// ==== main ==================================================================
//
// ============================================================================

int     main(void)
{
    auto    char            *cPtr = NULL;
    auto    int             *iPtr = NULL;
    auto    double          *dPtr = NULL;
    auto    int             numElems;

    // seed the random number generator for the 'rand' function
    srand(time(NULL));

    // allocate a block of doubles from the stack
    /*printf("How many doubles? ");
    scanf("%d", &numElems);
    dPtr = (double*)malloc(numElems * sizeof(double));
    puts("Here's a dynamic array of doubles...");
    FillMem(dPtr, numElems);
    DumpMem(dPtr, numElems);*/

    // allocate a block of chars from the stack
    printf("How many chars? ");
    scanf("%d", &numElems);
    cPtr = malloc(numElems * sizeof(char));
	printf("%d", sizeof(*cPtr));
	puts("Here's a dynamic array of chars...");
	FillMem(cPtr, numElems * sizeof(char));
    DumpMem(cPtr, numElems * sizeof(char));

    // allocate a block of ints from the stack
    printf("How many ints? ");
    scanf("%d", &numElems);
    iPtr = malloc(numElems * sizeof(int));
	printf("%d", sizeof(*iPtr));
    puts("Here's a dynamic array of ints...");
    FillMem(iPtr, numElems * sizeof(int));
    DumpMem(iPtr, numElems * sizeof(int));

    // release all allocated memory
    free(dPtr);
	free(cPtr);
	free(iPtr);

    return 0;

}  // end of "main"



// ==== DumpMem ===============================================================
//
// This function displays the contents of a block of memory in canonical
// hexadecimal format (e.g., like using 'hexdump -vC' at the command line).
//
// Input:
//      baseAddress [IN]        -- the base address of the memory block to
//                                 display
//
//      numBytes [IN]           -- the number of bytes to display
//
// Output:
//      Nothing.
//
// ============================================================================

void    DumpMem(void  *baseAddress, long  numBytes)
{
	auto Byte* inputArray = baseAddress;
	auto Byte* endarray = baseAddress + numBytes;
	
	while(inputArray < endarray)
	{
		printf("%p  ", (void*)inputArray);
		for(int i = 0; i < 16; i++)
		{
			if(inputArray < endarray)
			{
				printf(" %02X", *inputArray);
				inputArray++;
				if((i+1)%8 == 0)
				{
					printf(" ");
				}
			}
			
			else if(i < 16 || inputArray > endarray)
			{ 
				printf("   ");
				*inputArray = 20;
				if((i+1)%8 == 0)
				{
					printf(" ");
				}
				inputArray++;
			}
		}

		inputArray -= 16;
		printf(" |");
		for(int charNum = 0; charNum < 16; charNum++)
		{
			if(isalpha(*inputArray) || isdigit(*inputArray) || ispunct(*inputArray))
			{
				printf("%c ", *inputArray);
			}
			else if(inputArray < endarray)
			{
				printf(". ");
			}
			else
			{
				printf("  ");
			}
			
			inputArray++;
		}
		printf("|\n");
	}
	puts("\n");

}  // end of "DumpMem"

// ==== FillMem ===============================================================
//
// This function fills a block of memory with random values, one byte at a
// time.
//
// Input:
//      baseAddress [IN]        -- the base address of the memory block to fill
//
//      numBytes [IN]           -- the number of bytes to fill
//
// Output:
//      Nothing.
//
// ============================================================================

void    FillMem(void  *baseAddress, long  numBytes)
{
	srand(time(NULL));
	auto Byte* inputArray = baseAddress;

	//auto Byte* endArray = baseAddress + numBytes;
    for(int index = 0; index < numBytes; index++)
	{
		*(inputArray + index) = rand();
	 }
}  // end of "FillMem"


	//printf("%d", sizeof(*cPtr));