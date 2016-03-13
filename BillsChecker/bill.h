/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bill.h
 * Author: johan
 *
 * Created on March 6, 2016, 10:35 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BILL_H
#define BILL_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Bill {
    
   char *name;
   short index;
   unsigned int isChecked:1;
   struct Bill* next;
   
} Bill;



Bill* createBill(char*, short*);

Bill* getLinkedBillsFromFile(FILE*);

short checkBill(Bill*, char*);

void removeBills(Bill*);

void displayBills(Bill*);

void displayMissingBills(Bill*);


#ifdef __cplusplus
}
#endif

#endif /* BILL_H */

