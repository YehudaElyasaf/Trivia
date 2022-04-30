#pragma once

//searching for a value according to filter chosen in sql statement
//if this callback is called, it just has to change the value of the parameter to "true"
int doesExistCallback(void* data, int argc, char** argv, char** azColumnName);