#include <stdio.h>
#include <stdlib.h>

struct ArtPiece{
  char uid[32];
  char name_of_artist[20];
  char art_name[20];
  double price;
};

struct MyList{
    struct ArtPiece art_piece;
    struct MyList *next;
};
typedef MyList *picture;

void createList(int num){

}

int main(){
  printf("How many art pieces: ");
  int num = scanf("%d\n");
  printf("%d\n", num);
  return 0;
}
