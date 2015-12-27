#pragma once

#include <stdlib.h>
#include <string.h>

#include "reverse_string.h"

// Problem: Given a string, perform basic compression (aaabbcccc -> a3b2c4)
// Edge cases: If the string is the same, you should return the same string

// Implementation

int compress_str(char* in, char** out);