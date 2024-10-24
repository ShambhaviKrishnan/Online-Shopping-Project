//Online Shopping Application
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ProductNode {
    int product_id;
    char name[50];
    float price;
    int stock;
    struct ProductNode* next;
};
struct CartNode {
    struct ProductNode* product;
    struct CartNode* next;
};
struct UserNode {
    char username[10];
    char password[6];
    char address[100];
    struct CartNode* cart;
    struct UserNode* next;
};
void add_product(struct ProductNode** product_list) {
    struct ProductNode* new_product = (struct ProductNode*)malloc(sizeof(struct ProductNode));

    printf("Enter product ID: ");
    scanf("%d", &new_product->product_id);
    getchar();
    printf("Enter product name: ");
    fgets(new_product->name, sizeof(new_product->name), stdin);
    new_product->name[strcspn(new_product->name, "\n")] = 0;
    printf("Enter product price: ");
    scanf("%f", &new_product->price);
    printf("Enter product stock: ");
    scanf("%d", &new_product->stock);

    new_product->next = *product_list;
    *product_list = new_product;

    printf("Product added successfully!\n");
}
void register_user(struct UserNode** users) {
    struct UserNode* new_user = (struct UserNode*)malloc(sizeof(struct UserNode));

    printf("Enter username: ");
    fgets(new_user->username, sizeof(new_user->username), stdin);
    new_user->username[strcspn(new_user->username, "\n")] = 0;
    printf("Enter password: ");
    fgets(new_user->password, sizeof(new_user->password), stdin);
    new_user->password[strcspn(new_user->password, "\n")] = 0;
    printf("Enter address: ");
    fgets(new_user->address, sizeof(new_user->address), stdin);
    new_user->address[strcspn(new_user->address, "\n")] = 0;

    new_user->cart = NULL;
    new_user->next = *users;
    *users = new_user;

    printf("User registered successfully!\n");
}
void view_products(struct ProductNode* product_list) {
    struct ProductNode* current = product_list;
    printf("\n--- Product List ---\n");
    while (current != NULL) {
        printf("ID: %d, Name: %s, Price: %.2f, Stock: %d\n", current->product_id, current->name, current->price, current->stock);
        current = current->next;
    }
}
void add_to_cart(struct UserNode* user, struct ProductNode* product_list) {
    int product_id;
    printf("Enter the product ID to add to your cart: ");
    scanf("%d", &product_id);

    struct ProductNode* current_product = product_list;
    while (current_product != NULL) {
        if (current_product->product_id == product_id) {
            break;
        }
        current_product = current_product->next;
    }

    if (current_product == NULL) {
        printf("Product not found!\n");
        return;
    }

    struct CartNode* new_cart_item = (struct CartNode*)malloc(sizeof(struct CartNode));
    new_cart_item->product = current_product;
    new_cart_item->next = user->cart;
    user->cart = new_cart_item;

    printf("Product added to cart!\n");
}
void place_order(struct UserNode* user) {
    struct CartNode* current_cart_item = user->cart;
    if (current_cart_item == NULL) {
        printf("Your cart is empty!\n");
        return;
    }

    printf("\n--- Order Summary ---\n");
    while (current_cart_item != NULL) {
        struct ProductNode* product = current_cart_item->product;
        if (product->stock > 0) {
            printf("Product: %s, Price: %.2f\n", product->name, product->price);
            product->stock--;
        } else {
            printf("Product: %s is out of stock!\n", product->name);
        }
        current_cart_item = current_cart_item->next;
    }

    user->cart = NULL;
}
int main() {
    struct ProductNode* product_list = NULL;
    struct UserNode* users = NULL;
    int choice;

    while (1) {

printf(" W   W  EEEEE  L      CCCCC  OOOOO  M   M  EEEEE \n");
printf(" W   W  E      L      C      O   O  MM MM  E     \n");
printf(" W W W  EEEEE  L      C      O   O  M M M  EEEEE \n");
printf(" W W W  E      L      C      O   O  M   M  E     \n");
printf("  W W   EEEEE  LLLLL  CCCCC  OOOOO  M   M  EEEEE \n");


printf("\n================================\n");
printf("          SK ONLINE SHOPPING   \n");
printf("================================\n");
        printf("1. Register User\n");
        printf("2. Add Product\n");
        printf("3. View Products\n");
        printf("4. Add to Cart\n");
        printf("5. Place Order\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                register_user(&users);
                break;
            case 2:
                add_product(&product_list);
                break;
            case 3:
                view_products(product_list);
                break;
            case 4:
                if (users != NULL) {
                    add_to_cart(users, product_list);
                } else {
                    printf("No users registered!\n");
                }
                break;
            case 5:
                if (users != NULL) {
                    place_order(users);
                } else {
                    printf("No users registered!\n");
                }
                break;
            case 6:
                printf("Exiting the application. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
