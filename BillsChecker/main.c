/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: johan
 *
 * Created on February 25, 2016, 9:44 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bill.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    const char *fileDir = "resources/transactionlist.xls";
    const char *outFileDir = "resources/transactionlist.csv";
    
    
    
    FILE *excelFile = fopen(fileDir, "r");
    FILE *csvFile = fopen(outFileDir, "w");
    
    if(!(excelFile = fopen(fileDir, "r"))) {
        fprintf(stderr, "Can't open the file.\n");
        return EXIT_FAILURE;
    } else {
        printf("All good boss\n");
    }
    
    
    char test[] = "LNDALS STAD";  // U+00D6	// 214	
    
    char currentLine[238];
    while(fscanf(excelFile, "%238[^\n]\n", currentLine) == 1) {
        if(strstr(currentLine, test)) {
            printf("Found %s on current line!\n", test);
        }
        
    }
    
    return (EXIT_SUCCESS);
    
    
}

