
/**********************************************
Written By: Itai Arnon						  *
						                      *
Description: and takes expressions from input *
tries to figure if they represent legal       *
 commands of the COMPLEX Library.             *
A complex struct is defined                   *
Only A limited amount of variables is allowed *
											   *
***********************************************/

/* Created by Anakin on 02/06/2017. */



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "complex.h"

#define SIZE_ARR 100
#define NO_FUNCTIONS 9
#define NO_VARS 6




char *errorMsgs[] = {
        "\n**** ERROR command does not exist\n",
        "\n**** ERROR: invalid COMPLEX VARIABLE\n",
        "\n*ERROR:  No valid  command found!!\n",
        "\n *ERROR: variable  does not exist or missing!\n",
        "\n *ERROR:  the  first parmeter is invalid or  does not exist!\n",
        "\n **ERROR Missing comma or commas to allow further checking\n ",
        "\n **ERROR:Execssive  commas disabling further check\n",
        "\n ERROR Excessive text!!\n",
        "\n ERROR: Wrong Parameter , second Param must be a real number \n",
        "\n Error Detected irrelevant characters\n",
        "\n ERROR  Consecutive Commas!!\n",
        "\n ERROR: Wrong Parameter , second Param must be an imaginary number \n",
        "\nERROR - End Of File reached  - EOF \n" ,
		 "\nERROR - Invalid Arguments \n"
};




enum ERROR_ID  {COMMAND_NOT_EXIST, INVALID_COMPLEX, INVALID_COMMAND, VARIABLE_NON_EXIST, PARAM_NON_EXIST, SECOND_PARAM_INVALID ,MISSING_COMMA,
    MULTIPLE_COMMAS, EXCESSIVE_TEXT, WRONG_PARAM_REAL, IRRELEVANT_CHARACTER, CONSECUTIVE_COMMAS,
	WRONG_PARAM_IMG, EOF_REACHED,INVALID_ARGS , SUCCESS, FINISH};

enum FUNCTION_CODE {READ_COMP , PRINT_COMP , ADD_COMP , SUB_COMP ,
    MULT_COMP_REAL , MULT_COMP_IMG , MULT_COMP_COMP , ABS_COMP,  NOT_VALID };

struct  {
    char *name;
    void (*func)();
    /*param number */
    int complex_no;
    int scalar_no;
}cmd[] = {
        {"read_comp", read_comp , 1, 2},
        {"print_comp", print_comp , 1 , 0},
        {"add_comp", add_comp, 2 ,0 },
        {"sub_comp", sub_comp, 2,0},
        {"mult_comp_real", mult_comp_real , 1 ,1},
        {"mult_comp_img", mult_comp_img , 1 , 1},
        {"mult_comp_comp", mult_comp_comp , 2 , 0},
        {"abs_comp", abs_comp , 1 , 0},
        {"not_valid", NULL}
};


/* defining complex number*/
complex A,B,C,D,E,F;

/* array of pointer to complex adresses */
complex *arr_cmp[] = {&A,&B,&C,&D,&E,&F};
/*consider removing and changing header*/
order com;

void init_complex();

void print_error(int error);

void resetArr(char *input);

//int countCommas(  char *input  );
//
//
//char *findAfter(char *input);
//
//int validateCommand(char* com);
//
//int validateComplex(char complex);
//
//complex* char2comp(char comp);
//
//char *countCommas2 (char  *input );

/*int testArr(char input[]);*/

int main()
{
    int pos; /*function number,-1 error */
    int x = 0 ,is_changed = 0;/* used for flag*/
    int i = 0, j= 0, c = 0, f = 0 ;
    char c_ch1, c_ch2;
    char *ptrtod = 0;/*&endPtr - strtod */
    char command[SIZE_ARR] = ""; /*entire string*/
    char args[SIZE_ARR] = "";  /* string past function */
    char str[100] = "";  /*sscanf*/
    char number[SIZE_ARR] = ""; /*all the numbers*/
    int flag = SUCCESS;
    double d1=-1, d2=-1; /* params*/


    init_complex(*arr_cmp);

    /* START main block*/


    while (1) {
        resetArr(command);
        resetArr(str);
        resetArr(args);
        resetArr(number);

        flag = SUCCESS;
        /*saved pointer for ptr tod*/
        ptrtod = 0;
        /*  i is the index of command array*/
        i = 0;


        printf("Please enter input: ");
        /*reading input but removes spaces , new line  and EOF symbols
         * casting to char because c is an int*/
        // guessing that the extra parenthesis is to tell the compiler to watch out.

        while ((c = getchar()) != '\n' && c != EOF && i < SIZE_ARR && c != ' ') {
            command[i] = (char) c;
            i++;
        }
        if (command != 0) {
            command[i] = '\0';
        }
            /*if command array is null repeats process. Mistakes are are allowed*/
        else {
            continue;
        }
        /*halt has to  appear by itself*/
        if (strcmp(command, "halt") == 0) {
            return 1;
        }
        if (c == EOF) {
            print_error(EOF_REACHED);
            return (0);
        }
        printf("\n\n");
/*********************************************************************************************************************************/
        if ((pos = validateCommand(command)) == -1) {
            print_error(INVALID_COMMAND);
            flag = INVALID_COMMAND;
            //return(0);
        }
    }
        /*The rest of the text will have to be chekced*/
//
//
//        j = 0;
//        i = 0;

        /* this branch handles rhe rest of the string without the  command. The command has been identified and is legal */
//            while (( c = getchar()) != '\n' && c != EOF && i < SIZE_ARR  && j<SIZE_ARR) {
//                args[i] = (char) c ;
//
//
//                if (c == EOF) {
//                    print_error(EOF_REACHED);
//                    return (0);
//                }
//                if (c != ' ' && c != '.' && (c < '0' || c > '9')) {
//                     is_changed = (args[i - 1] >= '0' && args[i - 1] <= '9')  ? 1 : 0;
//                    if (is_changed) {
//                        args[i] = ' ';
//                        args[i + 1] = (char) c;
//                    } else args[i] = (char) c;
//                    ++i;
//                }
//
//            }
//
//            args[i] = (args!=NULL) ? (char)'\0':args[i];
//
//
//            printf("args:%s\n", args);
//
//            if (validateComplex(args[0]) == 0)
//            {
//                print_error(INVALID_COMPLEX);
//                flag = INVALID_COMPLEX;
//
//            }
//            if (flag == SUCCESS && cmd[pos].complex_no == 1 && cmd[pos].scalar_no == 0 && args[1] == ' ')
//            {
//
//                cmd[pos].func(char2comp(args[0]));
//                flag = FINISH;
//
//            }
//
///***************************************************************************************************************************/
//            if (flag == SUCCESS && cmd[pos].complex_no == 1 && cmd[pos].scalar_no == 1)
//            {
//
//                f = sscanf(args, "%c,%lf%s", &c_ch1, &d1, str);
//                d1 = strtod(number, &ptrtod);
//                printf("char: %c\n",c_ch1);
//                printf("double: %0.2f\n",d1);
//                printf("string: %s\n",str);
//                printf("f:%d\n",f);
//
//
//                x = (args[1] == ',') ? 1 : 0;
//                if ((f == 1)&& x)
//                {
//                    cmd[pos].func(char2comp(args[0]),d1);
//                    flag = FINISH;
//                } else
//                {
//                    print_error(INVALID_ARGS);
//                    flag = INVALID_ARGS;
//                }
//
//            }
//            /**********************************************************************************************************/
//            if (flag == SUCCESS && cmd[pos].complex_no == 2 && cmd[pos].scalar_no == 0)
//            {
//                f = sscanf(args, "%c,%c %s", &c_ch1, &c_ch2, str);
//                /*printf("ch1:%c ch2:%c\n",c_ch1,c_ch2);
//                printf("f:%d",f);
//                printf("str:%s\n",str);*/
//                if ((f == 2)&&(args[1]==','))
//                {
//                    cmd[pos].func(char2comp(args[0]), char2comp(c_ch2));
//                    flag = FINISH;
//                }
//                else
//                {
//                    print_error(INVALID_COMPLEX);
//                    flag = INVALID_COMPLEX;
//                }
//            }
///**************************************************************************************************************/
//          /*  if(flag == SUCCESS && cmd[pos].complex_no == 1 && cmd[pos].scalar_no == 0)
//            {
//                f = sscanf(args, "%c %s", &c_ch1, str);
//
//                if (f == 1)
//                {
//                    cmd[pos].func(char2comp(args[0]));
//                    flag = FINISH;
//                }
//                else
//                {
//                    print_error(INVALID_COMPLEX);
//                    flag = INVALID_COMPLEX;
//                }
//            } */
///****************************************************************************************************************/
//            if (flag == SUCCESS && cmd[pos].complex_no == 1 && cmd[pos].scalar_no == 2)
//            {
//
//                f = sscanf(args,"%c,%lf,%lf,%s",&c_ch1,&d1,&d1,str);
//                d1 = strtod(number, &ptrtod);
//                strcpy(number,ptrtod);
//                d2 = strtod(number,NULL);
//                printf("f:%d\n",f);
//
//                if (f == 1 )
//                {
//                    cmd[pos].func(char2comp(args[0]),d1,d2);
//                    flag = FINISH;
//
//                }
//                else
//                {
//                    x = ( d1 == -1 ) ? PARAM_NON_EXIST : SECOND_PARAM_INVALID;
//
//                    print_error(x);
//                    flag = x;
//                }
//            }
///****end of else***/
//        }
//
//    }
///**********************************end of  MAIN loop****************************/
//
//         exit(1);
//
///*end of main*/
//
//}
    }
//complex  *char2comp(char comp)
//{
//	int i;
//	for(i = 0; i < 6; i++)
//	{
//		if(arr_cmp[i]->name == comp)
//		{
//			return arr_cmp[i];
//		}
//	}
//    return(0);
//}
///*search if complex valid*/
///*complex - complex number A..F*/
//int validateComplex(char complex)
//{
//	if(complex >= 'A' && complex <= 'F')
//	{
//		return 1;
//	}
//	return 0;
//}
///*search for command number*/
int validateCommand(char* com)
{
	int i;
	for(i = 0; i < 9; i++)
	{
		if(strcmp(com, cmd[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}
//
//
    void print_error(int error)
    {
        printf("%s", errorMsgs[error]);
    }
//
    void resetArr(char *input)
    {

        memset(&input[0], ' ', SIZE_ARR);
    }
//
//
///***********************END OF countCOMMAS ***********************/
//
//
//
    void init_complex(complex **arr_cmp) {
        int k;
        for (k = 0; k < NO_VARS; ++k) {
            arr_cmp[k]->real = 0;
            arr_cmp[k]->name = (char) ('A' + k);
        }
    }

/****************************** END ********************** */








    

