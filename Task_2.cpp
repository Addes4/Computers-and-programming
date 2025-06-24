#include <iostream>
using namespace std;

int main() {
    int startNumber;
    int startHour, startMinute, startSecond;
    int endHour, endMinute, endSecond;

    int winnerNumber = 0;
    int bestTimeInSeconds = -1;
    int numberOfCompetitors = 0;

    while (true) {
        cout << "Start number? ";
        cin >> startNumber;

        if (startNumber < 1) {
            if (numberOfCompetitors == 0) {
                cout << "No competitors" << endl;
            } else {
                // Konvertera bästa tiden till h, m, s
                int hours = bestTimeInSeconds / 3600;
                int minutes = (bestTimeInSeconds % 3600) / 60;
                int seconds = bestTimeInSeconds % 60;

                cout << "Winner is starting number: " << winnerNumber << endl;
                cout << "Hour: " << hours << " Min: " << minutes << " Sec: " << seconds << endl;
                cout << "Number of competitors: " << numberOfCompetitors << endl;
            }
            cout << "The program ends" << endl;
            return 0;
        }

        // Input av tider
        cout << "Start time? ";
        cin >> startHour >> startMinute >> startSecond;

        cout << "End time? ";
        cin >> endHour >> endMinute >> endSecond;

        numberOfCompetitors++;

        // Konvertera tider till sekunder sedan midnatt
        int startInSeconds = startHour * 3600 + startMinute * 60 + startSecond;
        int endInSeconds = endHour * 3600 + endMinute * 60 + endSecond;

        // Hantera fall där måltiden är efter midnatt
        if (endInSeconds < startInSeconds) {
            endInSeconds += 24 * 3600; // Lägg till 24h
        }

        int totalTime = endInSeconds - startInSeconds;

        // Uppdatera bästa tid om det behövs
        if (bestTimeInSeconds == -1 || totalTime < bestTimeInSeconds) {
            bestTimeInSeconds = totalTime;
            winnerNumber = startNumber;
        }
    }
}
