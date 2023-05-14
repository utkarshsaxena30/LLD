/* 
Imagine you have an existing application that interacts with a third-party weather service to retrieve weather
information. The weather service provides data in a format that is incompatible with your application's existing 
codebase. To solve this problem, you decide to implement an adapter that acts as a bridge between your 
application and the weather service.

Your task is to create an adapter class that adapts the data provided by the weather service into a format 
that your application can understand. The adapter should have a method called getWeatherData() that returns 
the weather data in a consistent format that your application can process.

Once you've implemented the adapter, you should integrate it into your existing application code and replace 
the direct calls to the weather service with calls to the adapter. Test the functionality to ensure that the 
adapter correctly converts the weather data into the format expected by your application.
*/

#include<iostream>
#include<string>

class WeatherService {
    public: 
        std::string getWeatherData() const {
            return "ataD rehtaeW esreveR";
        }
};

class Weather {
    public: 
        virtual std::string getWeather() const {
            return "Weather Data";
        }
};

class WeatherAdapter: public Weather, public WeatherService {
    public: 
        std::string getWeather() const override {
            std::string str = getWeatherData();
            std::reverse(str.begin(), str.end());
            return str;
        }
};

int main() {
    std::cout << "Using the WeatherService class directly" << std::endl;
    WeatherService *weatherService = new WeatherService();
    std::cout << weatherService->getWeatherData() << std::endl;

    std::cout << "Using the Weather class directly" << std:: endl;
    Weather *weather = new Weather();
    std::cout << weather->getWeather() << std::endl;

    std::cout << "Using the adapter" << std::endl;
    WeatherAdapter *adapter = new WeatherAdapter();
    std::cout << adapter->getWeather() << std::endl;
}