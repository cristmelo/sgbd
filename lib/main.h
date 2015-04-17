// #define LENGTH_PAGE 128
 #define LENGTH_PAGE 128
#define LENGTH_BUCKETS 2
#define LENGTH_DATA_ENTRY 8
#define LENGTH_DEPTH 4
#define LENGTH_ID_BUCKET 4

using namespace std;

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <bitset>
#include <set>

// #include <vector>

#include "dataEntry.h"
#include "bucket.h"
#include "directory.h"
#include "database.h"

string stringNBytes(int num, int bytes);

