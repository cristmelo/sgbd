#define LENGTH_PAGE 128
#define NUMBER_PRIMARY_BUCKETS 4
#define LENGTH_BUCKETS 2


#include <iostream>
#include <string>
#include <istream>
#include <math>

#include "record.h"
#include "rid.h"
#include "page.h"
#include "bucket.h"
#include "directory.h"
#include "database.h"

using namespace std;