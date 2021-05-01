# include <stdio.h>
# include <stdlib.h>

//do one way list of structs (cars)
//struct car has a brand, model, color and price.

//func -> generate n(unkown) number of car(s)
//func -> print_all
//func -> delete car below given price

struct Mycar
{
     char brand[20];
     char model[20];
     char color[20];
     double price;
};

struct Mylist
{
    struct Mycar myCar;
    struct Mylist *next;
};

typedef struct Mylist *car;

car createCar(){
    car temp;
    temp = (car)malloc(sizeof(struct Mylist));
    temp->next = NULL;
    return temp;
}

car addCar(car root){
    car temp, p;
    temp = createCar();
    printf("Brand :");
    scanf("%s", temp->myCar.brand);
    printf("Model :");
    scanf("%s", temp->myCar.model);
    printf("Color :");
    scanf("%s", temp->myCar.color);
    printf("Price :");
    scanf("%lf", &temp->myCar.price);

    if(root == NULL){
        root = temp;
    }
    else{
        p = root;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
    return root;
}

void print_cars(car root){
    car current;
    current = root->next;
    while(current != NULL){
        printf("brand %s, model %s, color %s, price %lf", current->myCar.brand, current->myCar.model, current->myCar.color, current->myCar.price);
        printf("\n");
        current = current->next;
    }
    free(current);
}

car deleteByPrice(car root, double price)
{
	if(root->next->myCar.price < price){
		root->next = root->next->next;
	}else{
    root = root->next;
  }
    while(root->next)
    {
    	car current = root;
    	if(current->next){
	    	if(current->next->myCar.price < price){
	    		// printf("%s %lf \n", current->next->myCar.model, current->next->myCar.price);
	    		current->next = current->next->next;
	    		// free(current);
          root = root->next;
	    	}
	    }
    }

   return root;
}

int main()
{
    int num = 0;
    printf("How many cars: ");
    scanf("%d",&num);
    printf("\n");
    car root = createCar();
    for (int i=0;i<num;i++){
        addCar(root);
    }
    print_cars(root);
    printf("Price to delete by: ");
    double deletePrice;
    scanf("%lf", &deletePrice);
    deleteByPrice(root, deletePrice);
    print_cars(root);
    return 0;
}
