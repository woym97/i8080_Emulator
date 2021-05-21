/**
 * [FILE] i8080_Component.h
 * [AUTHOR] Madison Woy 
 * [DESCRIPTION] File containing an object that all other i8080
 *               components are derived from
 * [DATE] 2021-05-21
*/

#pragma once
#include "i8080.h"

/**
 * [DESCRIPTION] Deriviation class for all i8080 components
 *      - Allows each component to be defined individually 
 *          but still have a pointer back to the parent cpu
 *          so that the componenst can access the others
*/
class i8080_Component {
public:
    /**
     * [DESCRIPTION] Set the Parent pointer
     * 
     * [PARAM] parent_cpu 
    */
    i8080 *p_cpu;     // pointer to the parent CPU
    void setParent(i8080 *parent_cpu) {
        p_cpu = parent_cpu;
    };
};