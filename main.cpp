#include "header.h"

// This program is made to create a music list for the user were it does not have to be organized

int main() {
  char artist [MAX]; //Statically allocated arrays to pass it to the functions
  char title_s [MAX];
  char title_a [MAX];
  char key1 [MAX];
  char key2 [MAX];
  char key3 [MAX];
  char des [MAX];
  int value = 0; //To get the value of the arrays of character
  int index;
  int choice; //Choice from the option
  int s; //Return value

  table my_table; //Class object

  s = my_table.load_songs();
  if(s == 1){
    cout<<'\n'<<"SONGS LOADED!"<<'\n';
  }
  else
    cout<<'\n'<<"NO SONGS ARE LOADED!"<<'\n';
  

  cout<<"Welcome to the program! This program will help you organize your music list."<<'\n';

  while(choice != 5){
    cout<<"!MENU!"<<'\n'<<"(1) Add a new song. "<<'\n'<<"(2) Remove by artist name. "<<'\n'<<"(3) Display all the songs. "<<'\n'<<"(4) Display the songs with a matching name. "<<'\n'<<"(5) Quit the program. "<<'\n'<<"By entering the number of the option. What do you want to do: ";
    cin>>choice;
    cin.ignore(100,'\n');
    if(choice == 1){
      cout<<'\n'<<'\n'<<"Please enter the name of the artist: ";
      cin.get(artist,MAX,'\n');
      cin.ignore(100,'\n');

      cout<<'\n'<<"Please enter the name of the song: ";
      cin.get(title_s,MAX,'\n');
      cin.ignore(100,'\n');

      cout<<'\n'<<"Please enter the name of the album: ";
      cin.get(title_a,MAX,'\n');
      cin.ignore(100,'\n');

      cout<<'\n'<<"Please enter 3 keywords for this song: ";
      cout<<'\n'<<"1: ";
      cin.get(key1,MAX,'\n');
      cin.ignore(100,'\n');

      cout<<'\n'<<"2: ";
      cin.get(key2,MAX,'\n');
      cin.ignore(100,'\n');

      cout<<'\n'<<"3: ";
      cin.get(key3,MAX,'\n');
      cin.ignore(100,'\n');

      cout<<'\n'<<"Please enter a brief description of this song: ";
      cin.get(des,MAX,'\n');
      cin.ignore(100,'\n');

      int size = strlen(title_s)+1;
      for(int i = 0; i < size; ++i){
        value = value + title_s[i];
      }
      index = value % 11;
      s = my_table.add_song(artist,title_s,title_a,key1,key2,key3,des,index);

    }

    if(choice == 2){
      cout<<"What is the name of the artist: ";
      cin.get(artist,MAX,'\n');
      cin.ignore(100,'\n');

      s= my_table.remove_by_artist(artist);
      if(s ==1)
        cout<<'\n'<<"SUCCESS!"<<'\n';
      else
        cout<<'\n'<<"FAILURE!"<<'\n';
      
    }

    if(choice == 3){
      s = my_table.display_all();
      if(s == 1)
        cout<<'\n'<<"SUCCESS!"<<'\n';
      else
        cout<<'\n'<<"FAILURE!"<<'\n';
      
    }

    if(choice == 4){
      cout<<'\n'<<"Please enter the name of the song: ";
      cin.get(title_s,MAX,'\n');
      cin.ignore(100,'\n');
      s = my_table.display_key(title_s);
      if(s == 1)
        cout<<'\n'<<"SUCCESS!"<<'\n';
      else
        cout<<'\n'<<"FAILURE!"<<'\n';
    }
  }

   
  
  return 0;
}
