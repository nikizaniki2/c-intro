#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ArtPiece{
  char uid[32];
  char name_of_artist[20];
  char art_name[20];
  double price;
};

struct MyList{
    struct ArtPiece ArtPiece;
    struct MyList *next;
};
typedef struct MyList MyList;
typedef struct MyList *pointer;

MyList *create_art(){
  MyList *pointer = NULL;
  pointer = (MyList *)malloc(sizeof(MyList));

  printf("Value for UID: ");
  scanf(" %s", pointer->ArtPiece.uid);
  printf("Name of artist: ");
  scanf(" %s", pointer->ArtPiece.name_of_artist);
  printf("Name of art: ");
  scanf(" %s", pointer->ArtPiece.art_name);
  printf("Price of art: ");
  scanf("%lf", &pointer->ArtPiece.price);

  pointer->next = NULL;

  return pointer;
}

// generate queue(опашъчен) list
MyList *create_queue_list(){
  int num = 0;
  printf("How many elements: ");
  scanf("%d", &num);
  MyList *root = NULL;
  MyList *last = NULL;
  for(int i = 0; i < num; i++){
    printf("Art Piece Number: %d\n", i+1);
    if (root == NULL)
    {
      root = create_art();
      last = root;
    }
    else
    {
      last->next = create_art();
      last = last->next;
    }
  }
  return root;
}

//void (we don't change root so why return it??)
void *add_art_queue(MyList *root)
{
  MyList *current = root;
  while(current->next != NULL)
  {
    current = current->next;
  }
  current->next = create_art();
}

void print_all_art(MyList *root)
{
  MyList *current = root;
  while(current != NULL)
  {
    printf("%s, %s, %s, %lf\n", current->ArtPiece.uid,
     current->ArtPiece.name_of_artist,
     current->ArtPiece.art_name, current->ArtPiece.price);
     current = current->next;
  }
}

//we don't use void here because
//if we want to delete the first element we need to change root
//I (personal opinion) disagree with the way removing an item is
//described in Lab 9 (overcomplicated af)
//We can just check the next item instead of tracking the previous one.
MyList *delete_by_name(MyList *root)
{
  printf("Name to delete by: ");
  char name[20];
  scanf("%s", name);
  MyList *current = root;
  //if the first item is to be deleted just change root to root -> next item
  if (!strcmp(current->ArtPiece.name_of_artist, name))
  {
    root = root->next;
    return root;
  }
  while (current->next)
  {
    if (!strcmp(current->next->ArtPiece.name_of_artist, name))
    {
      if (current->next->next){
        current->next = current->next->next;
      }
      else
      {
        current->next = NULL;
        break;
      }
    }
    current = current->next;
  }
  return root;
}

void print_by_price(MyList *root)
{
  double price;
  printf("Price to search by: ");
  scanf("%lf", &price);
  MyList *temp = root;
  while(temp){
    if(temp->ArtPiece.price == price)
    {
      printf("%s, %s, %s, %lf\n", temp->ArtPiece.uid,
       temp->ArtPiece.name_of_artist,
       temp->ArtPiece.art_name, temp->ArtPiece.price);
       temp = temp->next;
       return;
    }
    temp = temp->next;
  }
  printf("No matches found.\n");
  return;
}

void print_highest_price(MyList *root)
{
  MyList *max = root;
  MyList *temp = root;
  while(temp){
    if(temp->ArtPiece.price > max->ArtPiece.price)
    {
      max = temp;
    }
    temp = temp->next;
  }

  printf("%s, %s, %s, %lf\n", max->ArtPiece.uid,
   max->ArtPiece.name_of_artist,
   max->ArtPiece.art_name, max->ArtPiece.price);
   max = max->next;
}

void clean_up(MyList *root)
{
  MyList* curr_item = root;
  while(root != NULL)
  {
    root = root->next;
    free(curr_item);
    curr_item = root;
  }
}
int main(){
  MyList *root = NULL;
  int navigator = -1;
  int list_exists = 0;
  while(navigator != 0){
    printf("0 - EXIT\n");
    printf("1 - Create List\n"); //queue list
    printf("2 - Add new art\n");
    printf("3 - Delete art by name\n");
    printf("4 - Search art by price\n");
    printf("5 - Search art by highest price\n");
    printf("6 - Print info for all art\n");
    printf("===================================\n");
    printf("Your choice: ");
    scanf("%d", &navigator);
    if (!root)
    {
      list_exists = 0;
    }
    switch (navigator) {
      case 0:
      if (list_exists){
        clean_up(root);
      }
      break;
      case 1:
      if (list_exists){
        printf("\n\nList already created!!!\n\n");
      }
      else
      {
        root = create_queue_list();
      }
      list_exists = 1;
      break;
      case 2:
      if (list_exists){
        add_art_queue(root);
      }
      else printf("\n\nNo list to add to!!!\n\n");
      break;
      case 3:
      if (list_exists){
        root = delete_by_name(root);
      }
      else printf("\n\nNo list to remove from!!!\n\n");
      break;
      case 4:
      if (list_exists)
      {
        print_by_price(root);
      }
      else printf("\n\nNo list to search from!!!\n\n");
      break;
      case 5:
      if (list_exists){
        print_highest_price(root);
      }
      else printf("\n\nNo list to search from!!!\n\n");
      break;
      case 6:
      if (list_exists){
        print_all_art(root);
      }
      else printf("\n\nNo list to print from!!!\n\n");
      break;
      default:
      printf("\n\nWrong selection!!!\n\n");
      break;
    }
  }

return 0;
}
