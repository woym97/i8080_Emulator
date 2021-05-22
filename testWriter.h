/*
    Test function to write a certain amount of opcodes to a file
    To run:
        - set up call with parameters from opcodes
        - set the variables below
        - run the program
        - when the file is done testing it will output to console
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int OPCODES_TO_WRITE_START = 40000;        // Defines which opcode call to start writing on (can bve changed)
int OPCODES_TO_WRITE_END = 50000;    // Defines which opcode call to stop writing on  (can be changed)
int NUM_OPCODE_DIGITS = 5;        // Make this value match the number of digits in the variable above it
ofstream TEST_OUT_FILE;                 // File handler for output

void writeOpcode(uint8_t opcode, uint16_t pc, uint64_t cycles, uint16_t sp,
    uint8_t reg_A, uint8_t reg_B, uint8_t reg_C, uint8_t reg_D, uint8_t reg_E, uint8_t reg_H, uint8_t reg_L,
    uint8_t flag_Z, uint8_t flag_S, uint8_t flag_P, uint8_t flag_C, uint8_t flag_AC) {
    // keep track of how many times the test has been written
    static double times_ran = 0;

    // if we have already finished writing then return 
    if (times_ran > OPCODES_TO_WRITE_END || (opcode == 0xd3)) {
        return;
    }

    // on the first call open the file and print header
    if (times_ran == 0) {
        TEST_OUT_FILE.open("Opcode_Log_i8080.txt", ios::out | ios::trunc);
        TEST_OUT_FILE << "Call  | Code | PC    | Cyc   | SP    |";
        TEST_OUT_FILE << " regA | regB | regC | regD | regE | regH | regL |";
        TEST_OUT_FILE << "flgZ|flgS|flgP|flgC|flgAC|";
        TEST_OUT_FILE << endl << "------------------------------------------------";
        TEST_OUT_FILE << "-----------------------------------------------------------------" << endl;
    }

    // if past the Opcode start then write to the file
    if (times_ran >= OPCODES_TO_WRITE_START) {
        // number of calls
        TEST_OUT_FILE << setfill(' ') << setw(NUM_OPCODE_DIGITS) << right << times_ran << " | ";
        // opcode
        TEST_OUT_FILE << "0x" << setfill('0') << setw(2) << right << hex << static_cast<unsigned>(opcode) << " | ";
        // PC & cycles & sp
        TEST_OUT_FILE << dec << setfill(' ') << setw(5) << right << pc << " | ";
        TEST_OUT_FILE << dec << setfill(' ') << setw(5) << right << static_cast<unsigned>(cycles) << " | ";
        TEST_OUT_FILE << dec << setfill(' ') << setw(5) << right << sp << " | ";
        // Registers
        TEST_OUT_FILE << "0x" << setfill('0') << setw(2) << right << hex << static_cast<unsigned>(reg_A) << " | ";
        TEST_OUT_FILE << "0x" << setfill('0') << setw(2) << right << hex << static_cast<unsigned>(reg_B) << " | ";
        TEST_OUT_FILE << "0x" << setfill('0') << setw(2) << right << hex << static_cast<unsigned>(reg_C) << " | ";
        TEST_OUT_FILE << "0x" << setfill('0') << setw(2) << right << hex << static_cast<unsigned>(reg_D) << " | ";
        TEST_OUT_FILE << "0x" << setfill('0') << setw(2) << right << hex << static_cast<unsigned>(reg_E) << " | ";
        TEST_OUT_FILE << "0x" << setfill('0') << setw(2) << right << hex << static_cast<unsigned>(reg_H) << " | ";
        TEST_OUT_FILE << "0x" << setfill('0') << setw(2) << right << hex << static_cast<unsigned>(reg_L) << " | ";
        // flags
        TEST_OUT_FILE << dec << setfill(' ') << setw(2) << right << static_cast<unsigned>(flag_Z) << " | ";
        TEST_OUT_FILE << dec << setfill(' ') << setw(2) << right << static_cast<unsigned>(flag_S) << " | ";
        TEST_OUT_FILE << dec << setfill(' ') << setw(2) << right << static_cast<unsigned>(flag_P) << " | ";
        TEST_OUT_FILE << dec << setfill(' ') << setw(2) << right << static_cast<unsigned>(flag_C) << " | ";
        TEST_OUT_FILE << dec << setfill(' ') << setw(3) << right << static_cast<unsigned>(flag_AC) << " | ";
        TEST_OUT_FILE << "\n";
    }

    // inc the call counter
    ++times_ran;

    // if we have written all we need to then close the file
    // also print done to the console
    if (times_ran == OPCODES_TO_WRITE_END) {
        TEST_OUT_FILE.close();
        printf("TEST COMPLETE\n");
    }

}