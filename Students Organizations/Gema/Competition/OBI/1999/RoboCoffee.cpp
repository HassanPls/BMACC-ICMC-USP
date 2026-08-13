#include <bits/stdc++.h>
using namespace std;

//função atan2 retorna o angulo da tangente
double getAngle(pair<int, int> a, pair<int, int> b) {

        int dx = b.first - a.first;
        int dy = b.second - a.second;

        double angle = atan2(dy, dx) * 180 / M_PI;
        return angle;
}

double roboin(int coordenadas) {
    double totalAngle = 0;

    vector<pair<int, int>> coordenadasVector(coordenadas);

    for (int i = 0; i < coordenadas; i++)
    {
        cin >> coordenadasVector[i].first >> coordenadasVector[i].second;
    }

    double angleIni = getAngle(coordenadasVector[0], coordenadasVector[1]);

    for (int i = 1; i <= coordenadas; i++)
    {
        pair<int,int> now = coordenadasVector[(i)%coordenadas];
        pair<int,int> after = coordenadasVector[(i+1)%coordenadas];

        double angle = angleIni - getAngle(now, after);
        if (angle < 0) angle += 360;
        totalAngle += angle;
        angleIni = getAngle(now, after);
    }
    
    return round(totalAngle);
}

int main() {

    int coordenadas = 0;
    int i = 1;
    while (cin >> coordenadas && coordenadas != 0)
    {
        int angle = roboin(coordenadas);
        int rotation = angle/360;
        cout << "Teste " << i << "\n";
        cout << "rotacoes: " << rotation << "\n\n";
        i++;
    }
    
    return 0;
}