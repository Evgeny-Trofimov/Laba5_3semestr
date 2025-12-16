#include "galaxy.h"
#include <iostream>

using namespace std;

void createSampleGalaxy(Galaxy& galaxy) {
    galaxy.addBody(new Planet("Земля", 0.0, 0.0, 100.0, 50.0, "Металлы"));
    galaxy.addBody(new Planet("Марс", 10.0, 5.0, 80.0, 30.0, "Минералы"));
    galaxy.addBody(new Asteroid("Пояс-1", 15.0, 2.0, 200.0));
    
    galaxy.addCorporation(new LogisticsCompany("Космическая Логистика Инк."));
    galaxy.addCorporation(new TechTrader("Квантовые Трейдеры"));
    galaxy.addCorporation(new MinerCompany("Добывающая Компания Астероидов"));
    
    galaxy.addRoute(TradeRoute("Земля", "Марс", 500.0, 8));
    galaxy.addRoute(TradeRoute("Марс", "Пояс-1", 800.0, 5));
}

int main() {
    Galaxy galaxy;
    
    createSampleGalaxy(galaxy);
    
    galaxy.displayAll();
    
    for (int i = 1; i <= 3; ++i) {
        cout << "\n\n=== ХОД " << i << " ===" << endl;
        galaxy.simulateTurn();
    }
    
    return 0;
}
