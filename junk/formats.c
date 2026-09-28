/**************************************************
 * Author:      Bill Westrick
 * Lab:         Lecture 2 example
 * Description: printf examples using several different
 *              modifiers for ints, floats, and strings
 * ***********************************************/
 
 #include <stdio.h>
 
 int main(void)
 {
    // vars
    long i = 123;
    double f = 123.456789;
    char s[] = "Purdue";
    
    // int examples...
    printf("\n\ninteger examples...\n");
    printf("0 [%d][%d]\n",i,-i);
    printf("1 [%+d][%+d]\n",i,-i);
    printf("2 [%5d][%5d]\n",i,-i);
    printf("3 [%-5d][%-5d]\n",i,-i);
    printf("4 [% d][% d]\n",i,-i);
    
    // float examples...
    printf("\n\nfloating point examples...\n");
    printf("0 [%f][%f]\n",f,-f);
    printf("1 [%e][%e]\n",f,-f);
    printf("2 [%g][%g]\n",f,-f);
    printf("3 [%.3f][%.3f]\n",f,-f);
    printf("4 [%10.2f][%10.2f]\n",f,-f);
    printf("5 [%-10.2f][%-10.2f]\n",f,-f);
    printf("6 [% -10.2f][% -10.2f]\n",f,-f);
    printf("7 [%+-10.2f][%-+10.2f]\n",f,-f);
    printf("8 [%+10.2f][%+10.2f]\n",f,-f);
    printf("9 [%10.2e][%10.2e]\n",f,-f);
    
    // string examples...
    printf("\n\nstring examples...\n");
    printf("0 [%s]\n",s);
    printf("1 [%10s]\n",s);
    printf("2 [%-10s]\n",s);

    printf("\n\n");
     
    return 0;
 }