#include <iostream>
#include <cassert>
#include <string>
#include <cstdlib>
#include "pebblesdb/db.h"
#include "pebblesdb/filter_policy.h"
using namespace std;
int main(int argc,char *argv[])
{
    //printf("MARK1\n");
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing=true;
    options.error_if_exists=false;
    options.filter_policy=leveldb::NewBloomFilterPolicy(10);
    leveldb::Status status=leveldb::DB::Open(options,"./testdb",&db);

    assert(status.ok());    
    for(int i=1;i<=100000;i++)
    {
        string value=to_string(i);
        string key=to_string(i);
        if(RW==0)
            status=db->Get(leveldb::ReadOptions(),key,&value);
        else
            status=db->Put(leveldb::WriteOptions(),key,value);
        //assert(status.ok());
    }
    
        /*string value;
        string deepestlevel("");
        string key(to_string(100));
        db->Get(leveldb::ReadOptions(),key,&value,&deepestlevel);*/
    
    delete db;
}


