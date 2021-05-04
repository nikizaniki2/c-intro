# include <stdio.h>
# include <stdlib.h>

struct MyCar
{
     char brand[20];
     char model[20];
     char color[20];
     double price;
};

struct Mylist
{
    struct MyCar MyCar;
    struct Mylist *next;
};

typedef struct Mylist Car;

Car *add_car(Car *root){
  Car *pointer = NULL;
  pointer = (Car *)malloc(sizeof(Car));

  printf("Brand of car: ");
  scanf(" %s", pointer->MyCar.brand);
  printf("Name of car: ");
  scanf(" %s", pointer->MyCar.model);
  printf("Color of car: ");
  scanf(" %s", pointer->MyCar.color);
  printf("Price of car: ");
  scanf("%lf", &pointer->MyCar.price);

  pointer->next = NULL;

  return pointer;
}

//returns root of list
Car *generate_cars(){
  int num_of_cars = 0;
  printf("How many cars to generate: ");
  scanf("%d", &num_of_cars);

  Car *root = NULL;
  Car *current = NULL;
  for(int i = 0; i < num_of_cars; i++)
  {
    current = add_car(root);
    current->next = root;
    root = current;
  }
  return root;
}

void print_cars(Car *root)
{
  Car *current = root;
  while(current)
  {
    printf("%s, %s, %s, %lf\n", current->MyCar.brand,
     current->MyCar.model,
     current->MyCar.color, current->MyCar.price);
     current = current->next;
  }
}

Car *delete_cars(Car *root)
{
  int price = 0;
  printf("Price to delete by: ");
  scanf("%d", &price);

//if the first element is lower then price
  if (root->MyCar.price < price)
  {
    root = root->next;
  }

  Car *current = root;

  while(current->next)
  {
    if(current->next->MyCar.price < price)
    {
      if(current->next->next)
      {
        current->next = current->next->next;
      }
      else
      {
        current->next = NULL;
      }
    }
  }
  return root;
}

int main()
{
  Car *root = generate_cars();
  print_cars(root);
  root = delete_cars(root);
  printf("\nPrice filter applied.\n\n");
  print_cars(root);
  return 0;
}
