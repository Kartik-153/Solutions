#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

const int MAX_AUCTIONS = 100; // Maximum number of auctions
const int MAX_COMPANY_NAME_LENGTH = 50; // Maximum length of company name
const int MAX_SPECTRUM_RANGE_LENGTH = 20; // Maximum length of spectrum range

// Define a structure to store auction data
struct Auction {
    std::string date;
    std::string state;
    char company[MAX_COMPANY_NAME_LENGTH];
    char spectrum_range[MAX_SPECTRUM_RANGE_LENGTH];
    double amount;
};

// Define a structure to store TRAI auction records
struct TRAIAuctionData {
    Auction auctions[MAX_AUCTIONS];
    int numAuctions;
};

// Function to add auction data to the TRAI auction records
void addAuctionData(TRAIAuctionData& traiData, const std::string& date, 
                                const std::string& state, const std::string& company, 
                                const std::string& spectrum_range, double amount) {
    if (traiData.numAuctions < MAX_AUCTIONS) {
        Auction auction;
        auction.date = date;
        auction.state = state;
        strncpy(auction.company, company.c_str(), MAX_COMPANY_NAME_LENGTH);
        strncpy(auction.spectrum_range, spectrum_range.c_str(), MAX_SPECTRUM_RANGE_LENGTH);
        auction.amount = amount;
        traiData.auctions[traiData.numAuctions++] = auction;
    } else {
        std::cerr << "Maximum number of auctions reached." << std::endl;
    }
}

// Function to load auction data from a CSV file
void loadAuctionDataFromCSV(TRAIAuctionData& traiData, const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filePath << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::string date, state, company, spectrum_range, amount_str;
        double amount;
        if (sscanf(line.c_str(), "%s,%s,%[^,],%[^,],%lf", &date, &state, &company, &spectrum_range, &amount) == 5) {
        //if (sscanf(line.c_str(), "%s,%s,%[^,],%[^,],%lf", &date, &state, auction.company, auction.spectrum_range, &amount) == 5) {

            addAuctionData(traiData, date, state, company, spectrum_range, amount);
           
        } else {
            std::cerr << "Error parsing line: " << line << std::endl;
        }
    }

    file.close();
}

int main() {
    TRAIAuctionData traiData;
    traiData.numAuctions = 0;

    // Load auction data from a CSV file
    loadAuctionDataFromCSV(traiData, "spectrumRange.csv");

    // Access and display auction data
    for (int i = 0; i < traiData.numAuctions; ++i) {
        Auction auction = traiData.auctions[i];
        std::cout << "Date: " << auction.date << std::endl;
        std::cout << "State: " << auction.state << std::endl;
        std::cout << "Company: " << auction.company << std::endl;
        std::cout << "Spectrum Range: " << auction.spectrum_range << std::endl;
        std::cout << "Amount: " << auction.amount << " INR" << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
