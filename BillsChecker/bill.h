/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bill.h
 * Author: johan
 *
 * Created on February 25, 2016, 10:29 PM
 */

#ifndef BILL_H
#define BILL_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct {
    
        char *name;
        struct Bill *next;
    
    } Bill;

    void addBill(Bill*);

#ifdef __cplusplus
}
#endif

#endif /* BILL_H */

