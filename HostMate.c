#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Hotel {
    char name[50];
    char city[50];
    int rooms;
    float price;
    float rating;
    int review;
};

struct Visitor {
    char name[50];
    int room_number;
};

void printHotel(struct Hotel hotel) {
    printf("Hotel name: %s\n", hotel.name);
    printf("City: %s\n", hotel.city);
    printf("Total rooms: %d\n", hotel.rooms);
    printf("Price of each room: %.2f\n", hotel.price);
    printf("Rating: %.1f\n", hotel.rating);
    printf("Review: %d\n\n", hotel.review);
}

void sortbyPrice(struct Hotel hotels[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (hotels[j].price > hotels[j + 1].price) {
                struct Hotel temp = hotels[j];
                hotels[j] = hotels[j + 1];
                hotels[j + 1] = temp;
            }
        }
    }
}

void sortByName(struct Hotel hotels[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(hotels[j].name, hotels[j + 1].name) > 0) {
                struct Hotel temp = hotels[j];
                hotels[j] = hotels[j + 1];
                hotels[j + 1] = temp;
            }
        }
    }
}

void sortbyrooms(struct Hotel hotels[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (hotels[j].rooms < hotels[j + 1].rooms) {
                struct Hotel temp = hotels[j];
                hotels[j] = hotels[j + 1];
                hotels[j + 1] = temp;
            }
        }
    }
}

void sortbyrating(struct Hotel hotels[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (hotels[j].rating < hotels[j + 1].rating) {
                struct Hotel temp = hotels[j];
                hotels[j] = hotels[j + 1];
                hotels[j + 1] = temp;
            }
        }
    }
}

void printHotelsInCity(struct Hotel hotels[], int n) {
    char city[50];
    int hotelsFound = 0;
    printf("Enter city name (Mumbai or Bangalore): ");
    scanf("%s", city);

    printf("\nHotels in %s:\n", city);
    for (int i = 0; i < n; i++) {
        if (strcasecmp(hotels[i].city, city) == 0) {
            printHotel(hotels[i]);
            hotelsFound++;
        }
    }

    if (hotelsFound == 0) {
        printf("No hotels found in %s\n", city);
    }
}

int main() {
    struct Hotel hotels[5] = {
        {"Mumbai Diwaney", "Mumbai", 200, 3180, 4.2, 120},
        {"Bombay Bornour", "Mumbai", 105, 4048, 4.8, 243},
        {"Bangalore Bonquet", "Bangalore", 100, 3200, 4.5, 340},
        {"Olvien", "Bangalore", 120, 2800, 4.6, 122},
        {"Mangolia's", "Mumbai", 64, 3880, 4.9, 180}
    };

    struct Visitor visitors[5][3] = {
        {{"Amar", 101}, {"Manish", 102}, {"Atul", 103}},
        {{"Elvish", 101}, {"Debolina", 102}, {"Shruti", 103}},
        {{"Zafar", 101}, {"Rahul", 102}, {"Priya", 103}},
        {{"Amir", 101}, {"Asif", 102}, {"Prince", 103}},
        {{"Aditya", 101}, {"Aman", 102}, {"Sahil", 103}}
    };

    int n = 5;
    int choice;

    do {
        printf("\n\n*************** HOTEL MANAGEMENT ***************\n");
        printf("1. PRINTING HOTEL DATA\n");
        printf("2. PRINTING VISITORS DATA\n");
        printf("3. SORTING HOTELS BY ROOM PRICES\n");
        printf("4. SORTING BASED ON THE AVAILABILITY OF VACANT ROOMS\n");
        printf("5. SORTING BY HOTEL NAME\n");
        printf("6. RATING AND REVIEWS\n");
        printf("7. PRINT THE HOTELS IN A SPECIFIC CITY\n");
        printf("8. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nPRINTING HOTEL DATA\n");
                for (int i = 0; i < n; i++) {
                    printHotel(hotels[i]);
                }
                break;

            case 2:
                printf("\nPRINTING VISITOR DATA\n");
                for (int i = 0; i < n; i++) {
                    printf("Hotel: %s\n", hotels[i].name);
                    for (int j = 0; j < 3; j++) {
                        printf("Visitor: %s, Room Number: %d\n", visitors[i][j].name, visitors[i][j].room_number);
                    }
                    printf("\n");
                }
                break;

            case 3:
                printf("\nSORTING HOTELS BY ROOM PRICE (ASC):\n");
                sortbyPrice(hotels, n);
                for (int i = 0; i < n; i++) {
                    printHotel(hotels[i]);
                }
                break;

            case 4:
                printf("\nSORTING BASED ON THE AVAILABILITY OF VACANT ROOMS (DESC):\n");
                sortbyrooms(hotels, n);
                for (int i = 0; i < n; i++) {
                    printHotel(hotels[i]);
                }
                break;

            case 5:
                printf("\nSORTING BY HOTEL NAMES (ASC):\n");
                sortByName(hotels, n);
                for (int i = 0; i < n; i++) {
                    printHotel(hotels[i]);
                }
                break;

            case 6:
                printf("\nSORTING BY RATINGS (DESC):\n");
                sortbyrating(hotels, n);
                for (int i = 0; i < n; i++) {
                    printHotel(hotels[i]);
                }
                break;

            case 7:
                printHotelsInCity(hotels, n);
                break;

            case 8:
                printf("EXITING THE PROGRAM\n");
                break;

            default:
                printf("INVALID CHOICE. PLEASE ENTER A VALID OPTION\n");
        }

    } while (choice != 8);

    return 0;
}
