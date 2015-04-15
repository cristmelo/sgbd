#define LENGTH_PAGE 128
#define NUMBER_PRIMARY_BUCKETS 4
#define LENGTH_BUCKETS 2
#define LENGTH_DATA_ENTRY 8


using namespace std;

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdlib.h>
#include <time.h>

// #include <vector>

#include "rid.h"
#include "dataEntry.h"
#include "bucket.h"
#include "directory.h"
#include "database.h"
