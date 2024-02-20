#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINESIZE 1024
#define MAX_LISTINGS 22555

struct listing {
    int id, host_id, minimum_nights, number_of_reviews, calculated_host_listings_count, availability_365;
    char host_name[LINESIZE], neighbourhood_group[LINESIZE], neighbourhood[LINESIZE], room_type[LINESIZE];
    float latitude, longitude, price;
};

// Function to parse each line in the file and return the structure
struct listing getfields(char *line) {
    struct listing item;

    sscanf(line, "%d,%d,%[^,],%[^,],%[^,],%f,%f,%[^,],%f,%d,%d,%d,%d",
           &item.id, &item.host_id, item.host_name, item.neighbourhood_group, item.neighbourhood,
           &item.latitude, &item.longitude, item.room_type, &item.price,
           &item.minimum_nights, &item.number_of_reviews, &item.calculated_host_listings_count,
           &item.availability_365);

    return item;
}

// Function to display the structure
void displayStruct(const struct listing *item) {
    printf("ID : %d\n", item->id);
    printf("Host ID : %d\n", item->host_id);
    printf("Host Name : %s\n", item->host_name);
    printf("Neighbourhood Group : %s\n", item->neighbourhood_group);
    printf("Neighbourhood : %s\n", item->neighbourhood);
    printf("Latitude : %f\n", item->latitude);
    printf("Longitude : %f\n", item->longitude);
    printf("Room Type : %s\n", item->room_type);
    printf("Price : %f\n", item->price);
    printf("Minimum Nights : %d\n", item->minimum_nights);
    printf("Number of Reviews : %d\n", item->number_of_reviews);
    printf("Calculated Host Listings Count : %d\n", item->calculated_host_listings_count);
    printf("Availability_365 : %d\n\n", item->availability_365);
}

int main() {
    struct listing list_items[MAX_LISTINGS];
    char line[LINESIZE];
    int count = 0;

    FILE *fptr = fopen("listings.csv", "r");
    if (fptr == NULL) {
        fprintf(stderr, "Error opening input file listings.csv\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, LINESIZE, fptr) != NULL && count < MAX_LISTINGS) {
        list_items[count++] = getfields(line);
    }
    fclose(fptr);

    for (int i = 0; i < count; i++) {
        displayStruct(&list_items[i]);
    }

    return 0;
}
