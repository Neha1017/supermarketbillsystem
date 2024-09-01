#include <stdio.h>
#include <string.h>
#define PRODUCT_COUNT 200
#define CART_SIZE 100

struct Product {
    char name[200];
    char type[200];
    int price; // Price per unit (kg or liter)
    int stock; // Available stock

};

struct Customer {
    char name[20];
    char address[20];
    char phone[20];
};

struct CartItem {
    char name[200];
    int quantity; // Quantity in kg for Grocery or liters for Liquid
};

struct CartItem cart[CART_SIZE];
int cartItemCount = 0;

// Function prototypes
float addProduct(struct Product products[], float totalBill);
float removeProduct(struct Product products[], float totalBill);
void calculateBill(float totalBill, struct Customer customer);
void returnMoney(float totalBill);
void listProducts(struct Product products[]);
void selectPaymentMethod();
int findProduct(struct Product products[], char name[]);


int main() {

    struct Customer customer;
    struct Product products[PRODUCT_COUNT] = {
        // Initial products

        // Initial products
        {"Apple", "Grocery", 150,50},       // Price per kg
        {"Orange", "Grocery", 120,70},       // Price per kg

        {"Mango", "Grocery", 80,40},         // Price per kg
        {"Grapes", "Grocery", 280,59},       // Price per kg

        {"Strawberry", "Grocery", 280,58},   // Price per kg
        {"Blueberry", "Grocery",380,80},    // Price per kg

        {"Pineapple", "Grocery",100,89},    // Price per kg
        {"Watermelon", "Grocery",180,56},   // Price per kg

        {"Cherry", "Grocery",180,58},       // Price per kg        
        {"Lime", "Grocery",80,90},         // Price per kg

        {"Kiwi", "Grocery",580,56},         // Price per kg
        {"Pomegranate", "Grocery",380,60},  // Price per kg

        {"Papaya", "Grocery",60,56},       // Price per kg
        {"Raspberry", "Grocery",68,50},    // Price per kg

        {"Pear", "Grocery",280,56},         // Price per kg
        {"Guava", "Grocery",25,56},        // Price per kg

        {"Dragonfruit", "Grocery", 180,60},  // Price per kg
        {"Passionfruit", "Grocery", 180,60}, // Price per kg

        {"Lychee", "Grocery", 180,56},       // Price per kg
        {"Honeydew", "Grocery", 280,50},     // Price per kg

        {"Lemon", "Grocery", 20,58},      // Price per kg
        {"Mulberry", "Grocery",180,56},   // Price per kg

        {"Olive", "Grocery", 180,58},      // Price per kg
        {"Elderberry", "Grocery", 380,56}, // Price per kg

        {"Limequat", "Grocery", 1800,50},   // Price per kg
        {"Pomelo", "Grocery", 80,56},     // Price per kg

        {"Kumquat", "Grocery", 180,56},    // Price per kg
        {"Quince", "Grocery", 180,56},     // Price per kg

        {"Jackfruit", "Grocery", 80,56},  // Price per kg
         {"Date", "Grocery", 180,56},       // Price per kg

        {"Durian", "Grocery", 180,40},     // Price per kg
        {"Avacado", "Grocery", 480,40},  // Price per kg
        {"Coconate", "Grocery", 180,40}, // Price per kg

        //Flour

        {"Rice", "Grocery", 60,40},// Price per kg
        {"Pasta", "Grocery", 120,40},// Price per kg

        {"Flour", "Grocery", 110,40},// Price per kg
        {"Bread Flour", "Grocery", 110,40},// Price per kg

        {"Cake Flour", "Grocery", 110,40},// Price per kg
        {"Pastry Flour", "Grocery", 110,40},// Price per kg

        {"Corn ", "Grocery", 110,40},// Price per kg
        {"Coconut Milk Powder", "Grocery", 210,40}, // Price per kg

        {"Lentil Flour", "Grocery", 110,40},// Price per kg
        {"Sugar", "Grocery", 120,40},// Price per kg

        {"Salt", "Grocery", 80,40},// Price per kg
        {"Red Rice", "Grocery", 180,40},// Price per kg

        {"Sushi Rice", "Grocery", 80,50},// Price per kg
        {"Parboiled Rice", "Grocery", 80},// Price per kg

        {"Black  Rice", "Grocery", 90,50},// Price per kg
        {"Calrose   Rice", "Grocery", 80,50},  // Price per kg

        {"Arborio Rice", "Grocery", 990,50},    // Price per kg
        {"Chili Powder", "Grocery", 80,50},    // Price per kg

        {"Ginger Powder", "Grocery", 80,50},   // Price per kg
        {"Cumin Powder", "Grocery", 40,50},    // Price per kg

        {"Paprika Powder", "Grocery", 80,50},  // Price per kg
        {"Cinnamon Powder", "Grocery", 80,50}, // Price per kg

         {"Samyang", "Grocery", 80,50}, // Price per kg  
        {"Ottogi", "Grocery", 80,50}, // Price per kg  

        {"Patanjali", "Grocery", 80,50}, // Price per kg  
        {"Myojo", "Grocery", 80,50}, // Price per kg  

        //Chicken

        {"Chicken Breast", "Grocery", 180,80},    // Price per kg
        {"Chicken Thigh", "Grocery", 280,60},     // Price per kg

        {"Chicken Drumstick", "Grocery",180,60}, // Price per kg
        {"Chicken Leg", "Grocery", 280,60},// Price per kg


        {"Chicken Wing", "Grocery", 80,60},      // Price per kg
        {"Whole Chicken", "Grocery", 380,60},     // Price per kg

        {"Turkey Breast", "Grocery",280,60},     // Price per kg
        {"Turkey Leg", "Grocery",180,60},// Price per kg


        {"Turkey Thigh", "Grocery",380,60},      // Price per kg
        {"Ground Turkey", "Grocery",480,60},     // Price per kg
         {"Whole Turkey", "Grocery",680,60},     // Price per kg
       
        //Fish

        {"Salmon", "Grocery", 280,60},            // Price per kg
        {"Tuna ", "Grocery", 380,60},             // Price per kg

        {"Halibut", "Grocery", 480,60},           // Price per kg
        {"Tilapia", "Grocery", 380,60},           // Price per kg

        {"Sardine", "Grocery", 280,60},           // Price per kg
        {"Katla ", "Grocery", 780,60},      // Price per kg

        {"Pabda ", "Grocery", 80,60},      // Price per kg
        {"Boal ", "Grocery", 80,60},       // Price per kg

        {"Mrigel ", "Grocery", 80,60},     // Price per Kg
        {"Hilsa ", "Grocery", 480,60},      // Price per kg

        {"Taki  ", "Grocery", 280,60},      // Price per kg
        {"Mola  ", "Grocery", 180,60},      // Price per kg

        {"Puti  ", "Grocery", 80,60},      // Price per kg
        {"Chitol  ", "Grocery", 80,60},    // Price per kg

        {"Aair  ", "Grocery", 80,60},      // Price per kg
        {"Khalisha  ", "Grocery", 80,60},  // Price per kg

        {"Guraicha   ", "Grocery", 80,60}, // Price per kg
        {"Pangash   ", "Grocery", 80,60},  // Price per kg

        {"Loitta   ", "Grocery", 80,60},   // Price per kg
        {"Foli    ", "Grocery", 80,60},    // Price per kg
        {"Prawn", "Grocery", 80,60},    // Price per kg

        //Beef

        {"Beef Tenderloin", "Grocery", 180,60}, // Price per kg
        {"Beef Brisket", "Grocery", 120,60}, // Price per kg

        {"Beef Ribs", "Grocery", 180,60}, // Price per kg
        {"Lamb Chops", "Grocery", 280,60}, // Price per kg

        {"Lamb Leg", "Grocery", 380,60},      // Price per kg
        {"Lamb Shoulder", "Grocery", 480,60}, // Price per kg

        {"Goat Meat", "Grocery", 180,60},     // Price per kg
        {"Duck Breast", "Grocery", 280,60},   // Price per kg

        {"Duck Leg", "Grocery", 380,60},      // Price per kg
        {"Rabbit", "Grocery", 480,60},        // Price per kg

        {"Venison", "Grocery", 180,60},       // Price per kg
        {"Cucumber", "Grocery",80,60},      // Price per kg

        {"Tomato", "Grocery",50,60},        // Price per kg
        {"Onion", "Grocery",60,60},         // Price per kg

        {"Carrot", "Grocery",20,60},        // Price per kg
        {"Zucchini", "Grocery", 80,60},      // Price per kg

        {"Spinach", "Grocery", 50,60},       // Price per kg
        {"Broccoli", "Grocery", 80,60},      // Price per kg

        //Vegetable

        {"Radish", "Grocery", 60,80},   // Price per kg
        {"Corn", "Grocery", 50,80},     // Price per kg

        {"Mushroom", "Grocery", 180,80}, // Price per kg
        {"Beetroot", "Grocery", 280,80}, // Price per kg

        {"Eggplant", "Grocery",80,80}, // Price per kg
        {"Peas", "Grocery", 180,80},     // Price per kg

        {"Endive", "Grocery", 80,80},   // Price per kg
        {"Celery", "Grocery", 280,80},   // Price per kg

        {"Leek", "Grocery", 380,80},     // Price per kg
        {"Acorn Squash", "Grocery", 280,80},     // Price per kg

        {"Fennel", "Grocery", 180,80},           // Price per kg
        {"Swiss Chard", "Grocery", 810,80},      // Price per kg

        {"Butternut Squash", "Grocery",80,80}, // Price per kg
        {"Artichoke", "Grocery", 280,80},        // Price per kg

        {"Bell Pepper", "Grocery", 20,80},      // Price per kg
        {"Okra", "Grocery", 80,80},             // Price per kg

        {"Sweet Potato", "Grocery", 70,60},     // Price per kg
        {"Collard Greens", "Grocery", 60,60},   // Price per kg

        {"Green Chili", "Grocery", 80,60},      // Price per kg
        {"Garlic", "Grocery", 80,60},           // Price per kg

        //Liquid

        {"Oil", "Liquid", 150,60},           // Price per liter
        {"Milk", "Liquid", 50,60},          // Price per liter

        {"Orange Juice", "Liquid", 50,60},  // Price per liter
        {"Apple Juice", "Liquid", 50,60},   // Price per liter

        {"Grape Juice", "Liquid", 50,60},   // Price per liter
        {"Lemonade", "Liquid", 40,60},      // Price per liter

        {"Tomato Juice", "Liquid", 50,60},  // Price per liter
        {"Almond Milk", "Liquid", 50,60},   // Price per liter

        {"Coconut Water", "Liquid", 50,60}, // Price per liter
        {"Guava Juice", "Liquid", 500,60},   // Price per liter

        {"Honey", "Liquid", 200,60},         // Price per liter
        {"Buttermilk", "Liquid", 500,60},    // Price per liter

        {"Fruit Punch", "Liquid", 50,60},   // Price per liter
        {"Mango Juice", "Liquid", 50,60},   // Price per liter

        {"Sunflower Oil", "Liquid", 500,60}, // Price per liter
        {"Peanut Oil", "Liquid", 500,60},    // Price per liter

        {"Coconut Oil", "Liquid", 60,60},   // Price per liter
        {"Vegetable Oil", "Liquid", 50,60}, // Price per liter

        {"Ice Cream", "Liquid", 50,60},     // Price per liter
        {"Olive Oil Juice", "Liquid", 50,60}, // Price per liter

        {"Pineapple Juice", "Liquid", 50,60}, // Price per liter
        {"Chocolate Juice", "Liquid", 50,60}, // Price per liter


        // Skin cake

        {"Lotion", "Liquid", 200,50},          // Price per liter
        {"Cream", "Liquid", 100,50},           // Price per liter

        {"Sunscreen", "Liquid", 560,50},       // Price per liter
        {"Moisturizer", "Liquid", 800,50},     // Price per liter

        {"Cleanser", "Liquid", 200,50},        // Price per liter
        {"Serum", "Liquid", 400,50},           // Price per liter

        {"Toner", "Liquid", 50,50},           // Price per liter
        {"Scrub", "Liquid", 500,50},           // Price per liter 

           };
      

    float totalBill = 0.0;
    int choice;
    char moreProducts;


    do {

        printf("\n****Welcome****\n");
        printf("Menu:\n");
        printf("1. Enter Customer Details\n");
        printf("2. List Products\n");
        printf("3. Add Product\n");
        printf("4. Remove Product\n");
        printf("5. Calculate Bill\n");
        printf("6. Select Payment Method\n");
        printf("7. Payback\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:

                printf("Enter name: ");
                scanf("%s", customer.name);
                printf("Enter address: ");
                scanf("%s", customer.address);
                printf("Enter phone: ");
                scanf("%s", customer.phone);
                break;

            case 2:
                listProducts(products);
                break;

            case 3:
                do {
                    totalBill = addProduct(products, totalBill);
                    printf("Do you want to add more products? (y/n): ");
                    scanf(" %c", &moreProducts);
                } while (moreProducts == 'y' || moreProducts == 'Y');

                break;

            case 4:
                do {
                    totalBill = removeProduct(products, totalBill);
                    printf("Do you want to remove more products? (y/n): ");
                    scanf(" %c", &moreProducts);
                } while (moreProducts == 'y' || moreProducts == 'Y');

                break;
            case 5:
                calculateBill(totalBill, customer);
                break;
            case 6:
                selectPaymentMethod();
                break;
            case 7:
                returnMoney(totalBill);
                break;
            case 8:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;

        }

    } while (choice != 8);

    return 0;
}

float addProduct(struct Product products[], float totalBill) {
    char input[200];
    int quantity;
    int found = 0;
    printf("Enter product name: ");

    scanf("%s", input);

    for (int i = 0; i < PRODUCT_COUNT; i++) {

        if (strcmp(products[i].name, input) == 0) {

            if (products[i].stock <= 0) {

                printf("Sorry, %s is out of stock.\n", products[i].name);
                return totalBill;

            }

            if (strcmp(products[i].type, "Grocery") == 0) {

                printf("Enter quantity (in kg): ");
                scanf("%d", &quantity);

                if (products[i].stock < quantity) {

                    printf("Not enough stock available for %s.\n", products[i].name);
                    return totalBill;
                }

                products[i].stock -= quantity;
            } else if (strcmp(products[i].type, "Liquid") == 0){
                printf("Enter quantity (in liters): ");

                scanf("%d", &quantity);

                if (products[i].stock < quantity) {
                    printf("Not enough stock available for %s.\n", products[i].name);
                    return totalBill;
                }
                products[i].stock -= quantity;

            }

            float cost = products[i].price * quantity;
            totalBill += cost;
            strcpy(cart[cartItemCount].name, products[i].name);
            cart[cartItemCount].quantity = quantity;
            cartItemCount++;
            printf("Cost for %d %s of %s: $%.2f\n", quantity, products[i].type, products[i].name, cost);
            found = 1;

            break;
        }
    }

    if (!found) {
        printf("Product not found.\n");
    }
    return totalBill;
}

float removeProduct(struct Product products[], float totalBill) {
    char input[200];
    float quantity;
    int found = 0;
    printf("Enter product name to remove: ");
    scanf("%s", input);
    for (int i = 0; i < PRODUCT_COUNT; i++) {
        if (strcmp(products[i].name, input) == 0) {
            if (strcmp(products[i].type, "Grocery") == 0) {
                printf("Enter quantity to remove (in kg): ");
                scanf("%f", &quantity);
                if (quantity <= 0) {
                    printf("Invalid quantity.\n");
                    return totalBill;
                }
                float cost = products[i].price * quantity;
                totalBill -= cost;
                for (int j = 0; j < cartItemCount; j++) {
                    if (strcmp(cart[j].name, products[i].name) == 0) {
                        cart[j].quantity -= quantity;
                        if (cart[j].quantity <= 0) {
                            for (int k = j; k < cartItemCount - 1; k++) {
                                cart[k] = cart[k + 1];
                            }
                            cartItemCount--;
                        }
                        break;
                    }
                }
                printf("Removed cost for %.2f kg of %s: $%.2f\n", quantity, products[i].name, cost);
            } else if (strcmp(products[i].type, "Liquid") == 0) {
                printf("Enter quantity to remove (in liters): ");
                scanf("%f", &quantity);
                if (quantity <= 0) {
                    printf("Invalid quantity.\n");
                    return totalBill;
                }
                float cost = products[i].price * quantity;
                totalBill -= cost;
                for (int j = 0; j < cartItemCount; j++) {
                    if (strcmp(cart[j].name, products[i].name) == 0) {
                        cart[j].quantity -= quantity;
                        if (cart[j].quantity <= 0) {
                            for (int k = j; k < cartItemCount - 1; k++) {
                                cart[k] = cart[k + 1];
                            }
                            cartItemCount--;
                        }
                        break;
                    }
                }
                printf("Removed cost for %.2f liters of %s: $%.2f\n", quantity, products[i].name, cost);
            }
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
    return totalBill;
}

void calculateBill(float totalBill, struct Customer customer) {
    float discount = 0.0;

    // Apply discount based on totalBill
    if (totalBill > 10000) {
        discount = totalBill * 0.10; // 10% discount
    } else if (totalBill > 5000) {
        discount = totalBill * 0.05; // 5% discount
    } else if (totalBill > 3000) {
        discount = totalBill * 0.03; // 3% discount
    }

    float discountedBill = totalBill - discount;
    float tax = discountedBill * 0.05; // 5% tax
    float grandTotal = discountedBill + tax;

    printf("\nInvoice:\n");
    printf("Customer Name: %s\n", customer.name);
    printf("Address: %s\n", customer.address);
    printf("Phone: %s\n", customer.phone);
    printf("Total Bill (after discount): $%.2f\n", discountedBill);
    printf("Discount: $%.2f\n", discount);
    printf("Tax (5%%): $%.2f\n", tax);
    printf("Grand Total: $%.2f\n", grandTotal);
}

void returnMoney(float totalBill) {
    float money;
    float tax = totalBill * 0.05; // 5% tax
    float grandTotal = totalBill + tax;
    printf("Enter amount given by customer: $");
    scanf("%f", &money);
    float payback = money - grandTotal;
    printf("Payback: $%.2f\n", payback);
}

void listProducts(struct Product products[]) {
    printf("\nAvailable Products:\n");
    for (int i = 0; i < PRODUCT_COUNT; i++) {
        printf("Name: %s, Type: %s, Price: $%d per unit, Stock: %d\n",
               products[i].name, products[i].type, products[i].price, products[i].stock);
    }
}

void selectPaymentMethod() {
    int paymentOption;
    printf("\nSelect Payment Method:\n");
    printf("1. Cash\n");
    printf("2. Card\n");
    printf("3. Bkash/Nogod\n");
    printf("Enter your choice: ");
    scanf("%d", &paymentOption);
    switch (paymentOption) {
        case 1:
            printf("You selected Cash.\n");
            break;
        case 2:
            printf("You selected Card.\n");
            break;
        case 3:
            printf("You selected Bkash/Nogod.\n");
            break;
        default:
            printf("Invalid payment method.\n");
            break;
    }
}

int findProduct(struct Product products[], char name[]) {
    for (int i = 0; i < PRODUCT_COUNT; i++) {
        if (strcmp(products[i].name, name) == 0) {
            return i;
        }
    }
    return -1; // Product not found
}
