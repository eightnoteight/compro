/* Author : Avinash Awate, Contest Co-ordinator */
/*****************************************************************************
 *                 Programming Contest IITBombayX OddManOut                  *
 *                 ----------------------------------------                  *
 * To allow contest participants to test a function which accepts an array   *
 * of integers (and the number of elements) and detect the odd number of     *
 * potentiallly longest sequence where every term = sum of previous 2 terms  *
 * Eachh identified sequence will have exactly one number incorrect          *
 * Inputs : I.1) Number of elements in array                                 *
 *          I.2) Array of integers containing possible sequences             *
 * Outputs: O.1) Total Number of odd man out sequences found                 *
 *          O.2) Array of integers storing start and stop of sequences       *
 *                                                                           *
 * Note : Longest sequences to be found                                      *
 *        No sequence should be subset of another                            *
 *                                                                           *
 *****************************************************************************/

/*****************************************************************************
 *                       Source Code Organisation                            *
 *                       ------------------------                            *
 * testOddManOut.cpp                                                         *
 * This file allows the participant to test his function for correctness     *
 * This file contains C++ code which opens the input stream, reads the file  *
 * into an array, calls the contestants encoding function and writes the     *
 * data in the output file                                                   *
 * A correct entry will produce an exactly equivalent file                   *
 *                                                                           *
 *****************************************************************************/

/* System Includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <unistd.h>

/* Local function prototypes */
int OddManOut(int nElems, int *iA, int *oA);

/* Local #defines */
#define MAXLENGTH   (100)
#define SUCCESS     (0)
#define FAILURE     (-1)
#define TRUE        (1)
#define FALSE       (0)

/* Globals */
static int   inMax=0;         /* The size of input array */
static int   inNumber=0;      /* The number of elements in input array */
static int  *input=NULL;      /* The input array */
static int   outMax=0;        /* The size of output array */
static int   outNumber=0;     /* The number of elements in output array */
static int  *output=NULL;     /* The output array */

/* Local Static Globals */
static FILE *inputfp=NULL;    /* Input file pointer */
static FILE *outputfp=NULL;   /* Output file pointer */
static FILE *logfp=NULL;   /* Output file pointer */

int main (int argc, char *argv[])
{
int  retval;                  /* Return value of function */
char *inputfile=NULL;         /* Input file name */
char *outputfile=NULL;        /* Output file name */
char *logfile=NULL;           /* Log file name */
int  index;                   /* To traverse arrays */
int  index2;                   /* To traverse arrays */
char optionchar;              /* Option chracter returned by getopt */

    /* Set return value to SUCCESS */
    retval = SUCCESS;

    /* Initialise Array */
    inMax     = MAXLENGTH;
    inNumber  = 0;
    input     = (int *) malloc (inMax * sizeof(int));
    outMax    = MAXLENGTH;
    outNumber = 0;
    output    = (int *) malloc (outMax * sizeof(int));

    /* Process command line options */
    while ((optionchar = getopt (argc, argv, "i:o:l:")) != -1)
    {
        switch (optionchar)
        {
            case 'i':
                inputfile = optarg;
                break;
            case 'o':
                outputfile = optarg;
                break;
            case 'l':
                logfile = optarg;
                break;
            case '?':
                if ( (optopt == 'i') || (optopt == 'o') || (optopt == 'l') )
                {
                    fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                }
                else
                {
                    fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
                }
                retval = FAILURE;
            default:
                fprintf (stderr, "Usage : OddManOut [-i inputfile] [-o outputfile] [-l logfile]\n");
                break;
        }
    }
    /* Check Mandatory Options */
    if (retval == SUCCESS)
    {
        if (inputfile == NULL)
        {
            fprintf (stderr, "Usage : OddManOut [-i inputfile] [-o outputfile] [-l logfile]\n");
            retval = FAILURE;
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

    /* If everything OK so far, open input, output and log files */
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
        outputfp = stdout;    /* Default is standard output */
        if (outputfile != NULL)
        {
            outputfp = fopen(outputfile,"w");
            if (outputfp == NULL)
            {
                fprintf (stderr, "Unable to open output file %s.\n", outputfile);
                retval = FAILURE;
            }
        }
        /* Open log file */
        logfp = stdout;    /* Default is standard output */
        if (logfile != NULL)
        {
            logfp = fopen(logfile,"w");
            if (logfp == NULL)
            {
                fprintf (stderr, "Unable to open log file %s.\n", logfile);
                retval = FAILURE;
            }
        }
    }

    /* If everything OK so far, read input file into input array */
    if (retval == SUCCESS)
    {
        inNumber = 0;
        while (fscanf(inputfp, "%d", &(input[inNumber])) == 1)
        {
            /* Increment */
            inNumber++;
            outNumber++;
            if (inNumber == inMax)
            {
                inMax  += MAXLENGTH;
                outMax += MAXLENGTH;
                input  = (int *) realloc (input, (inMax * sizeof(int)));
                output = (int *) realloc (input, (outMax * sizeof(int)));
            }
        }
    }

    /* If everything OK so far, call participant's function to implement Huffman encoding */
    if (retval == SUCCESS)
    {
        /* Call Participant's function */
        outNumber = OddManOut(inNumber, input, output);
        /* Generate Output File and Log File */
        for (index = 0; (index < outNumber); index++)
        {
            /* Print output file */
            fprintf(outputfp, "Sequence %d from %d to %d\n", (index + 1), output[2*index], output[2*index+1]);
            /* Print log file */
            fprintf(logfp, "Sequence %d from index %d to index %d\n", (index + 1), output[2*index], output[2*index+1]);
        }
    }

    /* Clean up */
    if (inputfp != NULL) { fclose(inputfp); }
    if (outputfp != NULL) { fclose(outputfp); }
    if (logfp != NULL) { fclose(logfp); }

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

struct seq_points
{
    int ei;
    int wi;
};

/* Define your support function ptototypes here */
int eastProbe(int idx, int nElems, int* iA);
int westProbe(int idx, int nElems, int* iA);


/* Define your actual support functions code here */
int cmp_seq_points_p (const void* p1, const void* p2)
{
    struct seq_points *sp1 = (struct seq_points *)p1;
    struct seq_points *sp2 = (struct seq_points *)p2;
    if (sp1->ei != sp2->ei)
        return (sp1->ei < sp2->ei)?-1:1;
    if (sp1->wi == sp2->wi)
        return 0;
    return (sp2->wi < sp2->wi)?-1:1;
}

int eastProbe(int idx, int nElems, int* iA)
{
    while (idx >= 2 && \
        iA[idx - 2] + iA[idx - 1] == iA[idx])
    {
        idx--;
    }
    idx--;
    return idx;
}

int westProbe(int idx, int nElems, int* iA)
{
    while (idx < nElems && \
        iA[idx - 2] + iA[idx - 1] == iA[idx])
    {
        idx++;
    }
    return idx;
}


/********************************************
 *********** Submission function ************
 *******************************************/
/*
 * The function OddManOut accepts three parameters
 * Inputs
 *     The first parameter nElem is the number of elements in inpt array
 *     The second parameter iA is the actual array of numbers
 *     The third parameter oA is an array where pair of indexes (start, end)
 *         for  every identified OddManOut sequence is stored
 * Outputs
 *     The function returns the number of sequences discovered
 *
 * Algorithm
 *     Describe the algorith here
 *
 */

int unique(struct seq_points *start, struct seq_points *end)
{
    if (start == end)
        return 0;
    struct seq_points *res = start;
    struct seq_points *tmp = start;
    while(++start != end)
    {
        if (start->ei != res->ei || start->wi != res->wi)
        {
            ++res;
            res->ei = start->ei;
            res->wi = start->wi;
        }
    }
    return((++res) - tmp);
}

int OddManOut(int nElems, int *iA, int *oA)
{
int nSeq;                     /* The number of sequences */
int idx, i, tmp, ei, wi;
struct seq_points *sps;

    /* Initialise */
    sps = (struct seq_points *)malloc(nElems*sizeof(struct seq_points));
    nSeq   = 0;
    for (idx = 0; idx < nElems; ++idx)
    {
        if (idx - 2 >= 0 && \
            iA[idx - 2] + iA[idx - 1] != iA[idx])
        {
            tmp = iA[idx];
            iA[idx] = iA[idx - 2] + iA[idx - 1];
            ei = eastProbe(idx, nElems, iA);
            wi = westProbe(idx, nElems, iA);
            if (wi - ei > 4)
            {
                sps[nSeq].ei = ei;
                sps[nSeq].wi = wi - 1;
                ++nSeq;
            }
            iA[idx] = tmp;
        }
        if (idx - 1 >= 0 && idx + 1 < nElems &&
            iA[idx - 1] + iA[idx] != iA[idx + 1])
        {
            tmp = iA[idx];
            iA[idx] = iA[idx + 1] - iA[idx - 1];
            ei = eastProbe(idx + 1, nElems, iA);
            wi = westProbe(idx + 1, nElems, iA);
            if (wi - ei > 4)
            {
                sps[nSeq].ei = ei;
                sps[nSeq].wi = wi - 1;
                ++nSeq;
            }
            iA[idx] = tmp;
        }
        if (idx + 2 < nElems && \
            iA[idx] + iA[idx + 1] != iA[idx + 2])
        {
            tmp = iA[idx];
            iA[idx] = iA[idx + 2] - iA[idx + 1];
            ei = eastProbe(idx + 2, nElems, iA);
            wi = westProbe(idx + 2, nElems, iA);
            if (wi - ei > 4)
            {
                sps[nSeq].ei = ei;
                sps[nSeq].wi = wi - 1;
                ++nSeq;
            }
            iA[idx] = tmp;
        }
    }
    qsort(sps, nSeq, sizeof(struct seq_points), cmp_seq_points_p);
    nSeq = unique(sps, sps + nSeq);
    for (i = 0; i < nSeq; ++i) {
        oA[2*i] = sps[i].ei;
        oA[2*i + 1] = sps[i].wi;
    }
    /* Return number of sequences */
    return(nSeq);
}
