#include <stdio.h>

int refills(unsigned int full_tank_car_range, unsigned int stops[], int stops_len){
    unsigned int current_location = 0, current_car_range = full_tank_car_range;
    unsigned int distance = stops[stops_len - 1], last_stop = 0;
    int stop_num = 0, i; 

    if (current_location + current_car_range > distance)
        return 0;
    
    for (i = 0; i < stops_len - 1; ++i){
        current_location = stops[i];
        if (stops[i+1] - stops[i] > full_tank_car_range){
            return -1;
        }
        current_car_range = current_car_range - (current_location - last_stop);
        if (stops[i + 1] - current_location > current_car_range){
            current_car_range = full_tank_car_range;
            stop_num += 1;
        }
        last_stop = stops[i];
    }
    return stop_num;
}

int main(void){
    /**
     * d: distance between the cities.
     * m: maximum distance the car can travel with full tank.
     * n: is the number of stops.
     * stops: the locations of stops.
     */
    unsigned int d;
    scanf("%u", &d);
    int m, n;
    scanf("%d %d", &m, &n);

    unsigned int stops[n + 1];
    for (int i = 0; i < n; ++i){
        scanf("%u", &stops[i]);
    } 
    stops[n] = d;

    int refill_num  =  refills(m, stops, n+1);
    printf("%d\n", refill_num);
    return 0;
}
