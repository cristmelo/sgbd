#define LENGTH_PAGE 128
#define NUMBER_PRIMARY_BUCKETS 4
#define LENGTH_BUCKETS 2

#define TYPE_DIRECTORY 7
#define TYPE_BUCKET 8
#define TYPE_RECORD 9

using namespace std;

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>

#include "record.h"
#include "rid.h"
#include "dataEntry.h"
#include "page.h"
#include "bucket.h"
#include "directory.h"
#include "database.h"
