#include "header.h"

//This program is made to create a music list for the user were it does not have to be organized

//Constructor
table::table(){
  hash_size = 11;

  ht = new node * [hash_size];
  for(int i=0; i < hash_size; ++i)
    ht [i] = NULL;
}

//Destructor
table::~table(){
  node * current;
  for(int i=0; i < hash_size; ++i){
    current = ht[i];
    while(current){
      delete []  current -> data -> artist;
      delete []  current -> data -> title_s;
      delete []  current -> data -> title_a;
      delete []  current -> data -> key1;
      delete []  current -> data -> key2;
      delete []  current -> data -> key3;
      delete []  current -> data -> des;
      delete current;
      current = current -> next;
    }
    
    delete  ht[i];
    ht[i] = NULL;
    
  }
}



//Loading the saved songs
int table::load_songs(){
  char artist [MAX];
  char title_s [MAX];
  char title_a [MAX];
  char key1 [MAX];
  char key2 [MAX];
  char key3 [MAX];
  char des [MAX];
  int value;
  ifstream in_file;
  in_file.open("data.txt");
  
  if(!in_file){
    return 0;
  }
  if(in_file){
    in_file.get(artist,MAX,'|');
    in_file.ignore(100,'|');

    while (in_file && !in_file.eof()){
      in_file.get(title_s,MAX,'|');
      in_file.ignore(100,'|');

      in_file.get(title_a,MAX,'|');
      in_file.ignore(100,'|');

      in_file.get(key1,MAX,'|');
      in_file.ignore(100,'|');

      in_file.get(key2,MAX,'|');
      in_file.ignore(100,'|');

      in_file.get(key3,MAX,'|');
      in_file.ignore(100,'|');

      in_file.get(des,MAX,'|');
      in_file.ignore(100,'|');

      int size = strlen(title_s)+1;
      for(int i = 0; i < size; ++i){
        value = value + title_s[i];
      }
      int i = value % 11;
      
//Placing the data in the hash table
      if(!ht[i]  ){
        ht[i]    = new node;
        ht[i]   -> data = new info;
        ht[i]   -> data -> artist = new char[strlen(artist)+1];
        strcpy(ht[i]   -> data -> artist, artist);   

        ht[i]   -> data -> title_s = new char[strlen(title_s)+1];
        strcpy(ht[i]   -> data -> title_s, title_s);  

        ht[i]   -> data -> title_a = new char[strlen(title_a)+1];
        strcpy(ht[i]   -> data -> title_a, title_a);  

        ht[i]   -> data -> key1 = new char[strlen(key1)+1];
        strcpy(ht[i]   -> data -> key1, key1);  

        ht[i]   -> data -> key2 = new char[strlen(key2)+1];
        strcpy(ht[i]   -> data -> key2, key2);

        ht[i]   -> data -> key3 = new char[strlen(key3)+1];
        strcpy(ht[i]   -> data -> key3, key3);

        ht[i]   -> data -> des = new char[strlen(des)+1];
        strcpy(ht[i]   -> data -> des, des);

        ht[i]   -> next = NULL;
        
      }

      else{
        node * temp = new node;
        temp -> data = new info;
        temp -> data -> artist = new char[strlen(artist)+1];
        strcpy(temp -> data -> artist, artist);   

        temp -> data -> title_s = new char[strlen(title_s)+1];
        strcpy(temp -> data -> title_s, title_s);  

        temp -> data -> title_a = new char[strlen(title_a)+1];
        strcpy(temp -> data -> title_a, title_a);  

        temp -> data -> key1 = new char[strlen(key1)+1];
        strcpy(temp -> data -> key1, key1);  

        temp -> data -> key2 = new char[strlen(key2)+1];
        strcpy(temp -> data -> key2, key2);

        temp -> data -> key3 = new char[strlen(key3)+1];
        strcpy(temp -> data -> key3, key3);

        temp -> data -> des = new char[strlen(des)+1];
        strcpy(temp -> data -> des, des);

        temp -> next = ht[i]  ;
        ht[i]   = temp;
      }

      in_file.get(artist,MAX,'|');
      in_file.ignore(100,'|');
    }
    in_file.close();
  }
  return 1;
}
//Adding a new song
int table::add_song(char * artist, char * title_s, char* title_a,char* key1, char* key2, char* key3, char * des, int index){
  //Saving the data entered to the file
  ofstream file_out;
  file_out.open("data.txt", ios::app);
  if(file_out){
    file_out<<artist<<'|'<<title_s<<'|'<<title_a<<'|'<<key1<<'|'<<key2<<'|'<<key3<<'|'<<des<<'|';

    file_out.close();
  }

  int i = index;
//Base case
  if(!ht[i]  ){
    ht[i]    = new node;
    ht[i]   -> data = new info;
    ht[i]   -> data -> artist = new char[strlen(artist)+1];
    strcpy(ht[i]   -> data -> artist, artist);   

    ht[i]   -> data -> title_s = new char[strlen(title_s)+1];
    strcpy(ht[i]   -> data -> title_s, title_s);  

    ht[i]   -> data -> title_a = new char[strlen(title_a)+1];
    strcpy(ht[i]   -> data -> title_a, title_a);  

    ht[i]   -> data -> key1 = new char[strlen(key1)+1];
    strcpy(ht[i]   -> data -> key1, key1);  

    ht[i]   -> data -> key2 = new char[strlen(key2)+1];
    strcpy(ht[i]   -> data -> key2, key2);

    ht[i]   -> data -> key3 = new char[strlen(key3)+1];
    strcpy(ht[i]   -> data -> key3, key3);

    ht[i]   -> data -> des = new char[strlen(des)+1];
    strcpy(ht[i]   -> data -> des, des);

    ht[i]   -> next = NULL;
    return 1;
  }
  //If wasn't empty
  node * temp = new node;
  temp -> data = new info;
  temp -> data -> artist = new char[strlen(artist)+1];
  strcpy(temp -> data -> artist, artist);   

  temp -> data -> title_s = new char[strlen(title_s)+1];
  strcpy(temp -> data -> title_s, title_s);  

  temp -> data -> title_a = new char[strlen(title_a)+1];
  strcpy(temp -> data -> title_a, title_a);  

  temp -> data -> key1 = new char[strlen(key1)+1];
  strcpy(temp -> data -> key1, key1);  

  temp -> data -> key2 = new char[strlen(key2)+1];
  strcpy(temp -> data -> key2, key2);

  temp -> data -> key3 = new char[strlen(key3)+1];
  strcpy(temp -> data -> key3, key3);

  temp -> data -> des = new char[strlen(des)+1];
  strcpy(temp -> data -> des, des);

  temp -> next = ht[i]  ;
  ht[i]   = temp;
  return 1;
}

//remove by artist 
int table::remove_by_artist(char * artist)
{
  int i = 0;
  if(!ht[i]) //If the array is empty
    i = i + 1;
  
  node *  current = ht[i];
  node * prev = ht[i]  ; //Previous pointer
  while(i < hash_size){
    current = ht[i];
    while(current){
      if(strcmp( current -> data -> artist,artist) == 0){
        if( current == ht[i]  ){//If the data were at the beggining
          delete [] ht[i]   -> data -> artist;
          delete [] ht[i]   -> data -> title_s;
          delete [] ht[i]   -> data -> title_a;
          delete [] ht[i]   -> data -> key1;
          delete [] ht[i]   -> data -> key2;
          delete [] ht[i]   -> data -> key3;
          delete [] ht[i]   -> data -> des;
          if(ht[i]   -> next)
            ht[i]   = ht[i]   -> next;
          else{
            
            current = NULL;
          }
          current = ht[i]  ;
        }
        else if(current  -> next){//If the data was in the middle
          prev -> next =  current -> next;
          delete []  current -> data -> artist;
          delete []  current -> data -> title_s;
          delete []  current -> data -> title_a;
          delete []  current -> data -> key1;
          delete []  current -> data -> key2;
          delete []  current -> data -> key3;
          delete []  current -> data -> des;
          delete  current;
          current = prev;
        }
        else if(! current -> next){
          delete []  current -> data -> artist;
          delete []  current -> data -> title_s;
          delete []  current -> data -> title_a;
          delete []  current -> data -> key1;
          delete []  current -> data -> key2;
          delete []  current -> data -> key3;
          delete []  current -> data -> des;
          delete  current;
          current = NULL;
          prev -> next = NULL;
          current = prev;
        }
      }
      prev =  current;
      current =  current -> next;
    }
    i = i + 1; //Moving to the next array
  }
  return 1;
}

//Display key
int table::display_key(char * title_s)
{
  node * current;
  int i = search(title_s); //Getting the index value
  
  if(!ht[i])
    return 0;
  
  current = ht[i]  ;
  while( current){
    cout<<'\n'<<"Artist: "<<current -> data -> artist<<'\n';
    cout<<"Song: "<< current -> data -> title_s<<'\n';
    cout<<"Album: "<< current -> data -> title_a<<'\n';
    cout<<"Keywords: "<<'\n'<< current -> data -> key1<<", ";
    cout<< current -> data -> key2<<", and ";
    cout<< current -> data -> key3<<'\n';
    cout<<"Description: "<< current -> data -> des<<'\n'<<'\n';
    current =  current -> next;
  }
  
  
  return 1;
}

//Search key
int table::search(char * title_s)
{
  int value;
  int size = strlen(title_s)+1;
  for(int i = 0; i < size; ++i){
    value = value + title_s[i];
  }
  int index = value % 11;

  return index;
}

int table::display_all()
{
  
  node * current;
  for(int i = 0; i < hash_size; ++i){
    current = ht[i];
    if(ht[i]){
      while(current){
        cout<<'\n'<<"Artist: "<<current -> data -> artist<<'\n';
        cout<<"Song: "<< current -> data -> title_s<<'\n';
        cout<<"Album: "<< current -> data -> title_a<<'\n';
        cout<<"Keywords: "<<'\n'<< current -> data -> key1<<", ";
        cout<< current -> data -> key2<<", and ";
        cout<< current -> data -> key3<<'\n';
        cout<<"Description: "<< current -> data -> des<<'\n'<<'\n';

        current = current -> next;
      }
    }
  }
  return 1;
}
