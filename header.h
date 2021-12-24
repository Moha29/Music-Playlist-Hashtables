#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

const int MAX = 100; //Constant for the statically allocated arrays in main

//This program is made to create a music list for the user were it does not have to be organized


//All the information in the LLL
struct info{
  char * artist;
  char * title_s;
  char * title_a;
  char * key1;
  char * key2;
  char * key3;
  char * des;
};

struct node{
  info * data;//A pointer to a struct
  node * next;
};

//A class to manage the hash table
class table{
  public:
    table();
    ~table();
    int load_songs();
    int add_song(char *, char *, char *, char *, char *, char *, char *, int);
    int search(char * title_s);
    int remove_by_artist(char *);
    int display_key(char * title_s);
    int display_all();
  private:
    node ** ht;
    int hash_size;
};
