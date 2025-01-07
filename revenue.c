#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int noOfCompanies, noOfCountries;
    scanf("%d", &noOfCompanies);
    scanf("%d", &noOfCountries);
    
    char companyName[noOfCompanies][101];
    long long totalRevenue[noOfCompanies];

     for (int companyIndex = 0; companyIndex < noOfCompanies; companyIndex++) 
     {
        totalRevenue[companyIndex] = 0;
        scanf("%s", companyName[companyIndex]);
        for (int countryIndex = 0; countryIndex < noOfCountries; countryIndex++) 
        {
            int revenue;
            scanf("%d", &revenue);
            totalRevenue[companyIndex] += revenue;
        }
    }

    long long maxRevenue = 0;
    int max_index[noOfCompanies];
    for (int companyIndex = 0; companyIndex < noOfCompanies; companyIndex++) 
    {
        if (totalRevenue[companyIndex] > maxRevenue) 
        {
            maxRevenue = totalRevenue[companyIndex];
        }
        
    }

    for (int companyIndex = 0; companyIndex < noOfCompanies; companyIndex++) 
    {
        if (totalRevenue[companyIndex] == maxRevenue) 
        {
            printf("%s\n", companyName[companyIndex]);
        }
    }

    return 0;
}