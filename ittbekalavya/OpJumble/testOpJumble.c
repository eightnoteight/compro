/* Author : Avinash Awate, Contest Co-ordinator */
/*****************************************************************************
 *                 Internship Programming Contest OpJumble                   *
 *                 ---------------------------------------                   *
 * To allow contest participants to test a function which accepts an array   *
 * of integers (and the number of elements) and inserts the arithmetic       *
 * operators (+,-,*,/) bwtween them as well as brckets in appropriate places *
 * such that the expresion o generte equals the t number (RHS) in array.     *
 * Inputs : I.1) Number of elements in array                                 *
 *          I.2) Array of integers last integer being RHS                    *
 * Outputs: O.1) An expresion containing first integers, operators and       *
 *               brackets such that it equals the last element (RHS)         *
 *                                                                           *
 * Note : You can use any number of brackets                                 *
 *        Identify only one solution                                         *
 *                                                                           *
 *****************************************************************************/

/*****************************************************************************
 *                       Source Code Organisation                            *
 *                       ------------------------                            *
 * testOpJumble.c                                                            *
 * This file allows the participant to test his function for correctness     *
 * This file contains C++ code which opens the input stream, reads the file  *
 * into an array, calls the contestants solution function and writes the     *
 * solution in the output file                                               *
 * A correct entry will produce an expression which matches the last element *
 *                                                                           *
 *****************************************************************************/

/* System Includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <unistd.h>

/* Local function prototypes */
char *OpJumble(int elements, int *inArray);

/* Local #defines */
#define MAXLENGTH        (50)
#define SUCCESS          (0)
#define FAILURE          (-1)
#define TRUE             (1)
#define FALSE            (0)

/* Globals */
static int inArray[MAXLENGTH];/* The input array */
static int elements;          /* The input array */
static char *answerString;    /* The answer string */

/* Local Static Globals */
static FILE *inputfp=NULL;    /* Input file pointer */
static FILE *outputfp=NULL;   /* Output file pointer */

int main (int argc, char *argv[])
{
int  retval;                  /* Return value of function */
char *inputfile=NULL;         /* Input file name */
char *outputfile=NULL;        /* Output file name */
int  index;                   /* To traverse arrays */
char optionchar;              /* Option chracter returned by getopt */

    /* Set return value to SUCCESS */
    retval = SUCCESS;

    /* Process command line options */
    while ((optionchar = getopt (argc, argv, "i:o:")) != -1)
    {
        switch (optionchar)
        {
            case 'i':
                inputfile = optarg;
                break;
            case 'o':
                outputfile = optarg;
                break;
            case '?':
                if ( (optopt == 'i') || (optopt == 'o') )
                {
                    fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                }
                else
                {
                    fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
                }
                retval = FAILURE;
            default:
                fprintf (stderr, "Usage : OpJumble [-i inputfile] [-o outputfile]\n");
                retval = FAILURE;
                break;
        }
    }

    /* Ignore all non option arguments */
    if (retval == SUCCESS)
    {
        for (index = optind; index < argc; index++)
        {
            fprintf(stderr, "Non-option argument %s\n", argv[index]);
        }
    }

    /* If everything OK so far, open input and output files */
    if (retval == SUCCESS)
    {   /* Correct Options specified */
        /* Open input file */
        inputfp = stdin;      /* Default is standard input */
        if (inputfile != NULL)
        {
            inputfp = fopen(inputfile,"r");
            if (inputfp == NULL)
            {
                fprintf (stderr, "Unable to open input file %s.\n", inputfile);
                retval = FAILURE;
            }
        }
        /* Open output file */
        if (outputfile != NULL)
        {
            outputfp = fopen(outputfile,"w");
            if (outputfp == NULL)
            {
                fprintf (stderr, "Unable to open output file %s.\n", outputfile);
                retval = FAILURE;
            }
            else { stdout = outputfp; }
        }
    }

    /* If everything OK so far, read input file into input array */
    if (retval == SUCCESS)
    {
        elements = 0;
        while (fscanf(inputfp, "%d", &(inArray[elements])) == 1) { elements++; }
        answerString =  OpJumble(elements, inArray);
        fprintf(outputfp, "%s", answerString);
    }

    /* Clean up */
    if (inputfp != NULL) { fclose(inputfp); }
    if (outputfp != NULL) { fclose(outputfp); }

    /* Return from main */
    return(retval);
}
/*****************************************
 *********** End of Test Code ************
 *****************************************/

/************************************************
 *********** Beginning of submission ************
 ************************************************/

/* Define local variables (if any) here */

/* Define your support function ptototypes here */

/* Define your actual support functions code here */

/********************************************
 *********** Submission function ************
 *******************************************/
/*
 * The function OpJumble accepts two parameters
 * Inputs
 *     The first parameter contains the number of elements in input array
 *     The second parameter has the actual array (last element is RHS)
 * Outputs
 *     The function returns a string which has array elements,
 *         intersperced with oerators and brackets such that
 *         The expresion evaluates to RHS (last element of array)
 *
 * Algorithm
 *
 */
char *OpJumble(int nElems, int *inArray)
{
}
