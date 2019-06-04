/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: root
 *
 * Created on 16 de mayo de 2019, 20:12
 */
#include <stdio.h>
#include <cstdlib>
#include <xlsxio_write.h>
#include <xlsxio_read.h>
#include <fstream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

//open .xlsx file for writing (will overwrite if it already exists)

xlsxiowriter handle;
if ((handle = xlsxiowrite_open("./filename.xlsx", "Hoja1")) == NULL) {
  fprintf(stderr, "Error creating .xlsx file\n");
  return 1;
}

//write column names
xlsxiowrite_add_column(handle, "Col1", 16);
xlsxiowrite_add_column(handle, "Col2", 0);
xlsxiowrite_next_row(handle);

//write data
int i;
for (i = 0; i < 1000; i++) {
  xlsxiowrite_add_cell_string(handle, "Test");
  xlsxiowrite_add_cell_int(handle, i);
  xlsxiowrite_next_row(handle);
}

//close .xlsx file
xlsxiowrite_close(handle);

}
