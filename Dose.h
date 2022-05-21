#include <utility>

//
// Created by Mirza on 7/11/2021.
//

#ifndef DSA_PROJECT_Dose_H
#define DSA_PROJECT_Dose_H

using namespace std;
class Dose {
    string bp, pulse, temperature;
public:
    [[maybe_unused]] [[nodiscard]] string getBp() const{
        return bp;
    }

    [[maybe_unused]] [[nodiscard]] string getPulse() const{
        return pulse;
    }

    [[maybe_unused]] [[nodiscard]] string getTemperature() const{
        return temperature;
    }
    void setDetails(string bloodp, string apulse, string temp) {
        this->bp = std::move(bloodp);
        this->pulse=  std::move(apulse);
        this->temperature= std::move(temp);
    }
};


#endif //DSA_PROJECT_Dose_H
