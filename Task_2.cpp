#include <iostream>
using namespace std;

int main() {
    int start_number;
    int start_hour, start_min, start_sec;
    int end_hour, end_min, end_sec;
    int best_start_number = 0;
    int best_time_hours = 0, best_time_min = 0, best_time_sec = 0;
    int competitor_count = 0;
    bool first_competitor = true;
    
    while (true) {
        cout << "Start number? ";
        cin >> start_number;
        
        if (start_number <= 0) {
            break;
        }
        
        cout << "Start time? ";
        cin >> start_hour >> start_min >> start_sec;
        
        cout << "End time? ";
        cin >> end_hour >> end_min >> end_sec;
        
        // Beräkna slut tid
        int total_start_seconds = start_hour * 3600 + start_min * 60 + start_sec;
        int total_end_seconds = end_hour * 3600 + end_min * 60 + end_sec;
        
        if (total_end_seconds < total_start_seconds) {
            total_end_seconds += 24 * 3600; // Lägg till 24h
        }
        
        int finish_time_seconds = total_end_seconds - total_start_seconds;
        int finish_hours = finish_time_seconds / 3600;
        int finish_min = (finish_time_seconds % 3600) / 60;
        int finish_sec = finish_time_seconds % 60;
        
        competitor_count++;
        
        // Check om det är bästa tiden
        if (first_competitor || finish_time_seconds < (best_time_hours * 3600 + best_time_min * 60 + best_time_sec)) {
            best_start_number = start_number;
            best_time_hours = finish_hours;
            best_time_min = finish_min;
            best_time_sec = finish_sec;
            first_competitor = false;
        }
    }
    
    // Skriv resultat
    if (competitor_count == 0) {
        cout << "No competitors" << endl;
    } else {
        cout << "Winner is starting number: " << best_start_number << endl;
        cout << "Hour: " << best_time_hours << " Min: " << best_time_min << " Sec: " << best_time_sec << endl;
        cout << "Number of competitors: " << competitor_count << endl;
    }
    
    cout << "The program ends" << endl;
    
    return 0;
}
