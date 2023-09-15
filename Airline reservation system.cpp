#include <iostream>
#include <unordered_map>

class Airline {
private:
    std::unordered_map<int, int> destinations; // Maps destination code to the number of available flights

public:
    Airline() {
        initialize();
    }

    void initialize() {
        destinations.clear();
    }

    void addDestination(int destination, int numFlights) {
        if (destinations.size() < 100) {
            destinations[destination] = numFlights;
        }
    }

    int checkFlights(int destination) {
        auto it = destinations.find(destination);
        if (it != destinations.end()) {
            return it->second;
        } else {
            return -1; // Destination not found
        }
    }
};

int main() {
    int n;
    std::cin >> n;

    Airline airline;

    for (int i = 0; i < n; i++) {
        int destination, numFlights;
        std::cin >> destination >> numFlights;
        airline.addDestination(destination, numFlights);
    }

    int searchDestination;
    std::cin >> searchDestination;

    int availableFlights = airline.checkFlights(searchDestination);

    if (availableFlights != -1) {
        std::cout << availableFlights << std::endl;
    } else {
        std::cout << "Destination not found" << std::endl;
    }

    return 0;
}

